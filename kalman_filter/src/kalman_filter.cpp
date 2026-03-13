/**
 * kalman_filter_node.cpp
 *
 * Subscribes to /joint_states (noisy), applies a per-joint discrete Kalman
 * filter (state: [position, velocity]), and publishes the filtered result to
 * /joint_states_filtered.
 *
 * Model
 * -----
 *  State      x  = [pos, vel]^T           (2×1)
 *  Transition F  = [[1, dt], [0, 1]]      (2×2)
 *  Measurement H  = [[1, 0]]              (1×2)
 *  Proc. noise Q  = diag(q_pos, q_vel)    (2×2)
 *  Meas. noise R  = [r]                   (1×1)
 */

#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/joint_state.hpp> 

#include <array>
#include <cmath>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

// ---------------------------------------------------------------------------
// 2-state scalar Kalman filter  (position + velocity, 1-D measurement)
// ---------------------------------------------------------------------------
struct KalmanJoint
{
  // State estimate
  double pos{0.0};
  double vel{0.0};

  // Error covariance  P = [[p00, p01], [p10, p11]]
  double p00{1.0}, p01{0.0};
  double p10{0.0}, p11{1.0};

  bool initialised{false};

  // Noise parameters (tunable)
  double q_pos{1e-4};   // process noise – position
  double q_vel{1e-3};   // process noise – velocity
  double r_pos{0.01};   // measurement noise – position

  // ------------------------------------------------------------------
  void init(double position)
  {
    pos = position;
    vel = 0.0;
    p00 = 1.0; p01 = 0.0;
    p10 = 0.0; p11 = 1.0;
    initialised = true;
  }

  // ------------------------------------------------------------------
  // dt  : seconds since last update
  // meas: measured position
  // Returns filtered position
  double update(double dt, double meas)
  {
    if (!initialised) {
      init(meas);
      return meas;
    }

    // ── PREDICT ──────────────────────────────────────────────────────
    // x_prior = F * x
    double pos_p = pos + vel * dt;
    double vel_p = vel;

    // P_prior = F * P * F^T + Q
    //   F = [[1,dt],[0,1]]
    double a00 = p00 + dt * p10;
    double a01 = p01 + dt * p11;
    double a10 = p10;
    double a11 = p11;

    // F * P * F^T
    double pp00 = a00 + dt * a01;
    double pp01 = a01;
    double pp10 = a10 + dt * a11;
    double pp11 = a11;

    // + Q
    pp00 += q_pos;
    pp11 += q_vel;

    // ── UPDATE (H = [1, 0]) ──────────────────────────────────────────
    // Innovation  y = meas - H * x_prior
    double y = meas - pos_p;

    // S = H * P_prior * H^T + R  =  pp00 + r_pos
    double s = pp00 + r_pos;

    // Kalman gain  K = P_prior * H^T / S  (column vector)
    double k0 = pp00 / s;
    double k1 = pp10 / s;

    // State update
    pos = pos_p + k0 * y;
    vel = vel_p + k1 * y;

    // Covariance update  P = (I - K*H) * P_prior
    p00 = (1.0 - k0) * pp00;
    p01 = (1.0 - k0) * pp01;
    p10 = pp10 - k1 * pp00;
    p11 = pp11 - k1 * pp01;

    return pos;
  }
};

// ---------------------------------------------------------------------------
// ROS 2 node
// ---------------------------------------------------------------------------
class KalmanFilterNode : public rclcpp::Node
{
public:
  KalmanFilterNode()
  : Node("kalman_filter_node")
  {
    // ── parameters ────────────────────────────────────────────────────
    this->declare_parameter("q_pos", 1e-4);
    this->declare_parameter("q_vel", 1e-3);
    this->declare_parameter("r_pos", 0.01);

    q_pos_ = this->get_parameter("q_pos").as_double();
    q_vel_ = this->get_parameter("q_vel").as_double();
    r_pos_ = this->get_parameter("r_pos").as_double();

    // ── pub / sub ─────────────────────────────────────────────────────
    sub_ = this->create_subscription<sensor_msgs::msg::JointState>(
      "/joint_states", 10,
      std::bind(&KalmanFilterNode::jointStatesCb, this, std::placeholders::_1));

    pub_ = this->create_publisher<sensor_msgs::msg::JointState>(
      "/joint_states_filtered", 10);

    RCLCPP_INFO(this->get_logger(),
      "Kalman filter node started  (q_pos=%.2e  q_vel=%.2e  r_pos=%.2e)",
      q_pos_, q_vel_, r_pos_);
  }

private:
  // ── callback ──────────────────────────────────────────────────────
  void jointStatesCb(const sensor_msgs::msg::JointState::SharedPtr msg)
  {
    if (msg->name.empty()) { return; }

    // Compute dt from header stamp
    rclcpp::Time now(msg->header.stamp);
    double dt = 0.01;   // default 10 ms on first message
    if (last_time_.nanoseconds() != 0) {
      double diff = (now - last_time_).seconds();
      if (diff > 0.0 && diff < 1.0) { dt = diff; }
    }
    last_time_ = now;

    // Prepare output message (copy header and names)
    auto out = sensor_msgs::msg::JointState();
    out.header = msg->header;
    out.name   = msg->name;
    out.position.resize(msg->name.size(), 0.0);
    out.velocity.resize(msg->name.size(), 0.0);

    // Copy effort if present
    if (!msg->effort.empty()) {
      out.effort = msg->effort;
    }

    std::ostringstream log;
    log << "\n--- Kalman filter ---";

    for (std::size_t i = 0; i < msg->name.size(); ++i) {
      const std::string & jname = msg->name[i];

      // Create filter on first sight
      if (filters_.find(jname) == filters_.end()) {
        auto & f = filters_[jname];
        f.q_pos = q_pos_;
        f.q_vel = q_vel_;
        f.r_pos = r_pos_;
        RCLCPP_INFO(this->get_logger(), "New joint tracked: %s", jname.c_str());
      }

      auto & kf = filters_[jname];

      double meas_pos = (i < msg->position.size()) ? msg->position[i] : 0.0;
      double filtered_pos = kf.update(dt, meas_pos);

      out.position[i] = filtered_pos;
      out.velocity[i] = kf.vel;   // estimated velocity

      // Accumulate per-joint data for the combined log
      char buf[200];
      std::snprintf(buf, sizeof(buf),
        "\n  [%s]  RAW: %+.5f  FILTERED: %+.5f  delta: %+.5f  est_vel: %+.5f",
        jname.c_str(), meas_pos, filtered_pos, meas_pos - filtered_pos, kf.vel);
      log << buf;
    }

    // Single throttled log — all joints visible every 500 ms
    RCLCPP_INFO_THROTTLE(
      this->get_logger(), *this->get_clock(), 500 /*ms*/,
      "%s", log.str().c_str());

    pub_->publish(out);
  }

  // ── members ──────────────────────────────────────────────────────
  rclcpp::Subscription<sensor_msgs::msg::JointState>::SharedPtr sub_;
  rclcpp::Publisher<sensor_msgs::msg::JointState>::SharedPtr    pub_;

  std::unordered_map<std::string, KalmanJoint> filters_;
  rclcpp::Time last_time_{0, 0, RCL_ROS_TIME};

  double q_pos_{1e-4};
  double q_vel_{1e-3};
  double r_pos_{0.01};
};

// ---------------------------------------------------------------------------
int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<KalmanFilterNode>());
  rclcpp::shutdown();
  return 0;
}
