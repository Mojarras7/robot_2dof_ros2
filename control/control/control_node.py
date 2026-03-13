import rclpy
import sys
import math

# Node is the base class for all ROS 2 nodes
from rclpy.node import Node 
# Float64MultiArray is used to send arrays of numbers (like our joint efforts or positions)
from std_msgs.msg import Float64MultiArray
# JointState tells us the current angles and speeds of the joints
from sensor_msgs.msg import JointState
# Point is a simple message that holds x, y, and z coordinates
from geometry_msgs.msg import Point

# Import our custom service definition directly
from two_dof_interfaces.srv import CoordinateToJoint

class ControlNode(Node):
    def __init__(self):
        super().__init__('control_node')
        self.get_logger().info('Control node has been started.')

        # PID Controller parameters (used to smoothly move the robot to the target)
        # You made a great point: Joint 1 carries the weight of the whole arm, 
        # while Joint 2 only carries the tip. They need different strengths!
        
        # Gains for Joint 1 (Shoulder - needs to be stronger)
        self.kp1 = 1.0  # Proportional: "How hard should I push based on how far I am?"
        self.ki1 = 1.0   # Integral: "Push harder if I've been stuck near the target for a while" 
        self.kd1 = 6.0   # Derivative: "Slow down as I get closer so I don't overshoot (bounce)"

        # Gains for Joint 2 (Elbow - needs less force)
        self.kp2 = 0.5
        self.ki2 = 0.5
        self.kd2 = 4.0
        
        # Time step for the control loop
        self.dt = 0.01 
        self.max_effort = 20.0
        self.integral_limit = 14.0

        # Variables to store the robot's current state
        self.current_joint_1 = 0.0
        self.current_joint_2 = 0.0
        self.current_vel_joint_1 = 0.0
        self.current_vel_joint_2 = 0.0
        
        # Variables to store where we WANT the robot to be
        self.desired_joint_1 = 0.0
        self.desired_joint_2 = 0.0
        
        self.integral_error_joint_1 = 0.0
        self.integral_error_joint_2 = 0.0

        # Read the 'mode' parameter to know if we are sending positions directly, or efforts (force)
        self.mode = self.declare_parameter('mode', 'effort').value
        
        # New parameter to choose between 'pid' and 'computed_torque' (only matters if mode is 'effort')
        self.control_type = self.declare_parameter('control_type', 'computed_torque').value

        # Computed Torque (Feedback Linearization) Gains
        # Added small Integral (I) term to absorb Gazebo's viscous friction and unmodeled dynamics
        self.kp1_ct = 14.0
        self.kd1_ct = 6.0
        self.ki1_ct = 1.0  # Small I term for joint 1
        
        self.kp2_ct = 7.0
        self.kd2_ct = 4.0
        self.ki2_ct = 1.0  # Small I term for joint 2
        
        self.ct_integral_limit = 0.5  # Limit to prevent windup

        # Listen to the current joint states
        self.create_subscription(JointState, '/joint_states', self.joint_state_callback, 10)
        
        # --- NEW: Listen to a standard topic for target coordinates! ---
        # This solves the problem of needing to restart the node. 
        # You can now publish to this topic while the node is running.
        self.create_subscription(Point, '/target_coordinate', self.target_coordinate_callback, 10)
        
        # Publisher for desired joint states (useful for plotting)
        self.desired_joint_pub = self.create_publisher(JointState, '/desired_joint_states', 10)
        
        # Setup publishers based on our control mode
        if self.mode == 'position':
            self.control_commands_publisher = self.create_publisher(Float64MultiArray, '/position_controller/commands', 10)
        else:
            self.control_commands_publisher = self.create_publisher(Float64MultiArray, '/effort_controller/commands', 10)
            
        # We need to talk to the inverse kinematics node to translate (X, Y) into (Theta1, Theta2)
        self.ik_client = self.create_client(CoordinateToJoint, 'coordinate_to_joint')
        
        # Create a timer that runs the control loop exactly 100 times a second (1 / 0.01)
        self.create_timer(self.dt, self.control_loop)

        self.get_logger().info('Ready! Send coordinates via terminal using:')
        self.get_logger().info('ros2 topic pub --once /target_coordinate geometry_msgs/msg/Point "{x: 1.0, y: 1.0}"')

    # Updates our records of where the robot currently is
    def joint_state_callback(self, msg: JointState) -> None:
        if len(msg.position) >= 2:
            self.current_joint_1 = msg.position[0]
            self.current_joint_2 = msg.position[1]
        if len(msg.velocity) >= 2:
            self.current_vel_joint_1 = msg.velocity[0]
            self.current_vel_joint_2 = msg.velocity[1]

    # --- NEW: Callback when someone publishes a Point to /target_coordinate ---
    def target_coordinate_callback(self, msg: Point) -> None:
        self.get_logger().info(f'Received new target coordinate: X={msg.x:.2f}, Y={msg.y:.2f}')
        self.request_desired_position(msg.x, msg.y)

    # Asks the IK node "What joint angles correspond to this X,Y coordinate?"
    def request_desired_position(self, x_value: float, y_value: float) -> None:
        # Check if the IK node is actually running
        if not self.ik_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().warn('Waiting for /coordinate_to_joint service. Make sure inverse_kinematic is running!')
            return

        # Prepare the request
        request = CoordinateToJoint.Request()
        request.x = x_value
        request.y = y_value

        # Send request asynchronously (doesn't freeze the code while waiting)
        future = self.ik_client.call_async(request)
        # When the IK node responds, call the handle_ik_response function
        future.add_done_callback(self.handle_ik_response)

    # Triggered when the IK node replies with the angles
    def handle_ik_response(self, future) -> None:
        try:
            response = future.result()
        except Exception as error:
            self.get_logger().error(f'Error while calling IK service: {error}')
            return

        if response is None or not response.success:
            self.get_logger().warn(f'IK returned an error: {response.message if response else "No response"}')
            return

        # Update our target goal!
        self.desired_joint_1 = response.theta1
        self.desired_joint_2 = response.theta2
        
        showDegrees_joint1 = math.degrees(self.desired_joint_1)
        showDegrees_joint2 = math.degrees(self.desired_joint_2)
        
        self.get_logger().info(f'Moving to angles: [{self.desired_joint_1:.3f} rad, {self.desired_joint_2:.3f} rad]')
        self.get_logger().info(f'Which is: [{showDegrees_joint1:.1f} deg, {showDegrees_joint2:.1f} deg]')

    def computed_torque(self, q1, q2, dq1, dq2, u_pd1, u_pd2) -> tuple:
        """
        Feedback Linearization (Computed Torque) Control Law
        Translated directly from your MATLAB script, but using the REAL physical 
        parameters of our Gazebo ROS 2 robot!
        """
        # 1. Matching the Gazebo URDF Physical Parameters Exactly
        m1 = 1.0        # Mass of link 1
        m2 = 0.5        # Mass of link 2
        L1 = 1.0        # Length of link 1
        L2 = 1.0        # Length of link 2
        lc1 = 0.5       # Center of mass of link 1
        lc2 = 0.5       # Center of mass of link 2
        
        # From the URDF <inertia> izz values for Z-axis rotation
        I1 = 0.08       # Not just (1/12)*m*L^2, URDF says 0.08
        I2 = 0.0417708  # URDF says 0.0417708
        

        g_const = 9.8   # Gazebo's default gravity
        
        # 2. Recalculate Matrices M(q), C(q, dq), and G(q) based on current state
        M11 = m1*(lc1**2) + m2*(L1**2 + lc2**2 + 2*L1*lc2*math.cos(q2)) + I1 + I2
        M12 = m2*(lc2**2 + L1*lc2*math.cos(q2)) + I2
        M21 = M12 
        M22 = m2*(lc2**2) + I2
        # M is our Inertia Matrix
        
        H = m2 * L1 * lc2 * math.sin(q2)
        
        C11 = -H * dq2
        C12 = -H * (dq1 + dq2)
        C21 =  H * dq1
        C22 =  0.0
        # C is our Coriolis/Centrifugal Matrix
             
        g1 = (m1*lc1 + m2*L1) * g_const * math.cos(q1) + m2*lc2*g_const*math.cos(q1 + q2)
        g2 = m2*lc2*g_const*math.cos(q1 + q2)
        # G_vec is our Gravity Matrix
             
        # 3. CONTROL LAW COMPUTATION: torque = M * u_pd + C * dq_vec + G_vec
        # Notice we do matrix multiplication out by hand since we don't use 'numpy' here yet:
        
        # (C * dq_vec)
        C_dq1 = C11 * dq1 + C12 * dq2
        C_dq2 = C21 * dq1 + C22 * dq2
        
        # (M * u_pd)
        M_u1 = M11 * u_pd1 + M12 * u_pd2
        M_u2 = M21 * u_pd1 + M22 * u_pd2
        
        # Final Torque = M_u + C_dq + G
        torque1 = M_u1 + C_dq1 + g1
        torque2 = M_u2 + C_dq2 + g2
        
        return torque1, torque2

    # The Math brain that constantly adjusts speeds/forces to reach the target angles
    def control_loop(self) -> None:
        # 1. Calculate Error (Where I want to be MINUS Where I am right now)
        error_joint_1 = self.desired_joint_1 - self.current_joint_1
        error_joint_2 = self.desired_joint_2 - self.current_joint_2

        # 2. Add up the error over time (Integral). This helps if the arm gets stuck just shy of the goal.
        self.integral_error_joint_1 += error_joint_1 * self.dt
        self.integral_error_joint_2 += error_joint_2 * self.dt

        # To prevent the "I" term from building up to crazy numbers and making the robot explode, we limit it.
        # Note: We now use separate limits for standard PID vs Computed Torque to be safe
        self.integral_error_joint_1 = max(-self.integral_limit, min(self.integral_limit, self.integral_error_joint_1))
        self.integral_error_joint_2 = max(-self.integral_limit, min(self.integral_limit, self.integral_error_joint_2))

        # 3. Calculate Derivative (Rate of change). In robotics, the negative current velocity 
        # is often used instead of (Error - Prev Error) to prevent jerky movements.
        derivative_joint_1 = -self.current_vel_joint_1
        derivative_joint_2 = -self.current_vel_joint_2

        # 4. Control Law Decisions
        if self.control_type == 'computed_torque':
            # -- COMPUTED TORQUE (FEEDBACK LINEARIZATION) --
            # In this mode, u_pd is our outer loop. Note we've added a small 'I' term 
            # (as suggested by your prof) to handle Gazebo's viscous friction and unmodeled parts.
            
            # Constrain integral error for the computed torque I term separately
            i_term_1_ct = self.ki1_ct * self.integral_error_joint_1
            i_term_2_ct = self.ki2_ct * self.integral_error_joint_2
            
            i_term_1_ct = max(-self.ct_integral_limit, min(self.ct_integral_limit, i_term_1_ct))
            i_term_2_ct = max(-self.ct_integral_limit, min(self.ct_integral_limit, i_term_2_ct))
            
            u_pd1 = self.kp1_ct * error_joint_1 + self.kd1_ct * derivative_joint_1 + i_term_1_ct
            u_pd2 = self.kp2_ct * error_joint_2 + self.kd2_ct * derivative_joint_2 + i_term_2_ct
            
            # Send the state and our PD+I commands through the nonlinear math block!
            control_joint_1, control_joint_2 = self.computed_torque(
                self.current_joint_1, self.current_joint_2, 
                self.current_vel_joint_1, self.current_vel_joint_2, 
                u_pd1, u_pd2
            )
        else:
            # -- STANDARD PID CONTROL --
            control_joint_1 = (
                self.kp1 * error_joint_1
                + self.ki1 * self.integral_error_joint_1
                + self.kd1 * derivative_joint_1
            )
            control_joint_2 = (
                self.kp2 * error_joint_2
                + self.ki2 * self.integral_error_joint_2
                + self.kd2 * derivative_joint_2
            )

        # Safety Check: Limit the maximum force we send so the robot doesn't swing too violently
        control_joint_1 = max(-self.max_effort, min(self.max_effort, control_joint_1))
        control_joint_2 = max(-self.max_effort, min(self.max_effort, control_joint_2))

        # Publish the desired position for tracking and plotting
        desired_msg = JointState()
        desired_msg.header.stamp = self.get_clock().now().to_msg()
        desired_msg.name = ['joint1', 'joint2']
        desired_msg.position = [self.desired_joint_1, self.desired_joint_2]
        self.desired_joint_pub.publish(desired_msg)

        # 5. Pack our calculated commands into a message and Publish it!
        control_msg = Float64MultiArray()
        if self.mode == 'position':
            # In position mode, we bypass PID and just tell Gazebo the exact angles we want
            control_msg.data = [self.desired_joint_1, self.desired_joint_2]
        else:
            # In effort mode, we send the Torques (forces) calculated by our PID loop
            control_msg.data = [control_joint_1, control_joint_2]
            
        self.control_commands_publisher.publish(control_msg)

def main(args=None):
    rclpy.init(args=args)
    control_node = ControlNode()
    
    # We simplified the confusing startup logic! 
    # The node now just starts up normally and waits for coordinates on the /target_coordinate topic.
    # No more complex python AI-generated sys.argv parsing needed.
    
    rclpy.spin(control_node)  # Keeps the program running until it is manually stopped
    
    control_node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main() 