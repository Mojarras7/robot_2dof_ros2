import math
import numpy as np

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Imu, JointState

class TiltKalmanFilter:
    """
    A simple 1D Kalman Filter that fuses an accelerometer and a gyroscope.
    It tracks two things (the state):
    1. The angle (theta)
    2. The gyroscope bias (the inherent drift of the gyro)
    """
    def __init__(self, process_noise_Q_angle: float, process_noise_Q_bias: float, measurement_noise_R: float):
        # State: [angle, gyro_bias]
        self.x = np.array([[0.0], 
                           [0.0]])
        
        # P: Covariance matrix (how uncertain we are about the current state)
        self.P = np.array([[1.0, 0.0],
                           [0.0, 1.0]])
        
        # Q: Process Noise matrix (how much we "distrust" our prediction model)
        # We trust the angle prediction quite a bit, but we also allow the bias to change slowly
        self.Q = np.array([[process_noise_Q_angle, 0.0],
                           [0.0, process_noise_Q_bias]])
        
        # R: Measurement Noise matrix (how much we "distrust" the accelerometer reading)
        self.R = np.array([[measurement_noise_R]])
        
        # H: Measurement matrix (maps state to measurement)
        # We only measure the angle directly from the accelerometer, not the bias
        self.H = np.array([[1.0, 0.0]])

    def predict(self, dt: float, gyro_rate: float):
        """
        Step 1: Predict the new angle using the gyroscope.
        angle_new = angle_old + (gyro_rate - gyro_bias) * dt
        """
        # F: State transition matrix
        # x_new = F * x_old
        # [angle_new] = [1, -dt] * [angle_old]   + [dt] * gyro_rate
        # [bias_new ]   [0,   1]   [bias_old ]   [ 0]
        
        # 1. Predict State
        self.x[0, 0] += (gyro_rate - self.x[1, 0]) * dt
        # self.x[1, 0] remains the same (bias doesn't change predictably)
        
        # 2. Predict Covariance (Uncertainty grows over time without measurements)
        F = np.array([[1.0, -dt],
                      [0.0,  1.0]])
        self.P = F @ self.P @ F.T + self.Q

    def update(self, accel_angle: float) -> float:
        """
        Step 2: Update the predicted angle with the actual accelerometer reading.
        """
        z = np.array([[accel_angle]])
        
        # S: Innovation covariance (how much uncertainty there is in this update)
        S = self.H @ self.P @ self.H.T + self.R
        
        # K: Kalman Gain (how much should we trust the measurement vs prediction)
        K = self.P @ self.H.T @ np.linalg.inv(S)
        
        # Innovation: difference between measured angle and predicted angle
        innovation = z - (self.H @ self.x)
        
        # 3. Update State
        self.x = self.x + K @ innovation
        
        # 4. Update Covariance (Uncertainty decreases because we have a measurement)
        I = np.eye(2)
        self.P = (I - K @ self.H) @ self.P
        
        # Return the final filtered angle
        return float(self.x[0, 0])

class KalmanFilterNode(Node):
    def __init__(self):
        super().__init__('kalman_filter_node')
        self.get_logger().info('Kalman Filter Node started (Estimating Angles).')

        # Parameters
        self.declare_parameter('input_topic_link1', '/link1/ruido_imu')
        self.declare_parameter('input_topic_link2', '/link2/ruido_imu')
        self.declare_parameter('output_topic_joints', '/kalman_joint_states')
        
        # Kalman filter tuning parameters
        self.declare_parameter('q_angle', 0.001) # Trust model (gyro)
        self.declare_parameter('q_bias',  0.003) 
        self.declare_parameter('r_measure', 0.03) # Distrust accel
        
        input_topic_link1 = self.get_parameter('input_topic_link1').get_parameter_value().string_value
        input_topic_link2 = self.get_parameter('input_topic_link2').get_parameter_value().string_value
        output_topic_joints = self.get_parameter('output_topic_joints').get_parameter_value().string_value
        
        q_angle = self.get_parameter('q_angle').get_parameter_value().double_value
        q_bias = self.get_parameter('q_bias').get_parameter_value().double_value
        r_measure = self.get_parameter('r_measure').get_parameter_value().double_value

        # Create two separate filters for Link 1 and Link 2 absolute angles
        self.kf_link1 = TiltKalmanFilter(q_angle, q_bias, r_measure)
        self.kf_link2 = TiltKalmanFilter(q_angle, q_bias, r_measure)

        # Variables to store the latest angles and time
        self.theta1_abs = 0.0 # Absolute angle of link 1
        self.theta2_abs = 0.0 # Absolute angle of link 2
        self.last_time_link1 = None
        self.last_time_link2 = None

        # Publisher for the Joint States
        self.joint_pub = self.create_publisher(JointState, output_topic_joints, 10)

        # Subscribers
        self.sub_link1 = self.create_subscription(
            Imu, input_topic_link1, self.imu1_callback, 10)
        self.sub_link2 = self.create_subscription(
            Imu, input_topic_link2, self.imu2_callback, 10)

    def compute_accel_angle(self, msg: Imu) -> float:
        """
        Calculates the angle of the sensor strictly based on the accelerometer.
        Since gravity always points down (-Y axis), we can use basic trigonometry.
        """
        ax = msg.linear_acceleration.x
        ay = msg.linear_acceleration.y
        
        # When joint angle is 0, arm is horizontal (along X). Gravity pulls down (-Y).
        # Accelerometer measures normal force pushing UP (+Y), so ax=0, ay=+9.8.
        # So we use atan2(ax, ay) to get angle=0 when resting horizontally.
        return math.atan2(ax, ay)

    def imu1_callback(self, msg: Imu):
        current_time = float(msg.header.stamp.sec) + float(msg.header.stamp.nanosec) * 1e-9
        
        if self.last_time_link1 is None:
            self.last_time_link1 = current_time
            return
            
        dt = current_time - self.last_time_link1
        self.last_time_link1 = current_time
        dt = max(dt, 1e-4)

        # 1. Get Accelerometer angle (noisy absolute angle)
        accel_angle = self.compute_accel_angle(msg)
        
        # 2. Get Gyroscope rate (smooth velocity)
        gyro_rate = msg.angular_velocity.z

        # 3. Kalman Filter Predict & Update
        self.kf_link1.predict(dt, gyro_rate)
        self.theta1_abs = self.kf_link1.update(accel_angle)
        
        # Publish the joint states using the latest info
        self.publish_joint_states(msg.header.stamp)

    def imu2_callback(self, msg: Imu):
        current_time = float(msg.header.stamp.sec) + float(msg.header.stamp.nanosec) * 1e-9
        
        if self.last_time_link2 is None:
            self.last_time_link2 = current_time
            return
            
        dt = current_time - self.last_time_link2
        self.last_time_link2 = current_time
        dt = max(dt, 1e-4)

        # 1. Get Accelerometer angle
        accel_angle = self.compute_accel_angle(msg)
        
        # 2. Get Gyroscope rate
        gyro_rate = msg.angular_velocity.z

        # 3. Kalman Filter Predict & Update
        self.kf_link2.predict(dt, gyro_rate)
        self.theta2_abs = self.kf_link2.update(accel_angle)

    def publish_joint_states(self, stamp):
        # Joint 1 angle is just the absolute angle of link 1
        joint1_angle = self.theta1_abs
        
        # Joint 2 angle is the difference between link 2's absolute angle and link 1's absolute angle
        joint2_angle = self.theta2_abs - self.theta1_abs

        msg = JointState()
        msg.header.stamp = stamp
        msg.name = ['joint1', 'joint2']
        # Provide the computed angles!
        msg.position = [joint1_angle, joint2_angle]
        
        self.joint_pub.publish(msg)

def main(args=None):
    rclpy.init(args=args)
    node = KalmanFilterNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
