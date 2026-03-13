import rclpy
import sys
import math
from importlib import import_module
from rclpy.node import Node 
from std_msgs.msg import Float64MultiArray
from sensor_msgs.msg import JointState


CoordinateToJoint = import_module('two_dof_interfaces.srv').CoordinateToJoint


class ControlNode(Node):
    def __init__(self):
        super().__init__('control_node')
        self.get_logger().info('Control node has been started.')

        self.kp = 12.0
        self.ki = 2.0
        self.kd = 1.0
        self.dt = 0.01
        self.max_effort = 20.0
        self.integral_limit = 2.0

        self.current_joint_1 = 0.0
        self.current_joint_2 = 0.0
        self.current_vel_joint_1 = 0.0
        self.current_vel_joint_2 = 0.0
        self.desired_joint_1 = 0.0
        self.desired_joint_2 = 0.0
        self.integral_error_joint_1 = 0.0
        self.integral_error_joint_2 = 0.0

        self.create_subscription(JointState, '/joint_states', self.joint_state_callback, 10)
        self.control_commands_publisher = self.create_publisher(Float64MultiArray, '/effort_controller/commands', 10)
        self.ik_client = self.create_client(CoordinateToJoint, 'coordinate_to_joint')
        self.create_timer(self.dt, self.control_loop)  # 100 Hz

    def joint_state_callback(self, msg: JointState) -> None:
        if len(msg.position) >= 2:
            self.current_joint_1 = msg.position[0]
            self.current_joint_2 = msg.position[1]
        if len(msg.velocity) >= 2:
            self.current_vel_joint_1 = msg.velocity[0]
            self.current_vel_joint_2 = msg.velocity[1]

    def request_desired_position(self, x_value: float, y_value: float) -> None:
        while not self.ik_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Waiting for /coordinate_to_joint service...')

        request = CoordinateToJoint.Request()
        request.x = x_value
        request.y = y_value

        future = self.ik_client.call_async(request)
        future.add_done_callback(self.handle_ik_response)

    def handle_ik_response(self, future) -> None:
        try:
            response = future.result()
        except Exception as error:
            self.get_logger().error(f'Error while calling IK service: {error}')
            return

        if response is None:
            self.get_logger().error('IK service returned no response')
            return

        if not response.success:
            self.get_logger().warn(f'IK returned an error: {response.message}')
            return

        self.desired_joint_1 = response.theta1
        self.desired_joint_2 = response.theta2
        showDegrees_joint1 = self.desired_joint_1 * 180.0 / math.pi
        showDegrees_joint2 = self.desired_joint_2 * 180.0 / math.pi
        self.get_logger().info(
            f'Desired position received from IK -> [{self.desired_joint_1:.3f}, {self.desired_joint_2:.3f}]'
        )
        self.get_logger().info(
            f'Desired position in degrees -> [{showDegrees_joint1:.3f}, {showDegrees_joint2:.3f}]'
        )

    def control_loop(self) -> None:
        error_joint_1 = self.desired_joint_1 - self.current_joint_1
        error_joint_2 = self.desired_joint_2 - self.current_joint_2

        self.integral_error_joint_1 += error_joint_1 * self.dt
        self.integral_error_joint_2 += error_joint_2 * self.dt

        self.integral_error_joint_1 = max(-self.integral_limit, min(self.integral_limit, self.integral_error_joint_1))
        self.integral_error_joint_2 = max(-self.integral_limit, min(self.integral_limit, self.integral_error_joint_2))

        derivative_joint_1 = -self.current_vel_joint_1
        derivative_joint_2 = -self.current_vel_joint_2

        control_joint_1 = (
            self.kp * error_joint_1
            + self.ki * self.integral_error_joint_1
            + self.kd * derivative_joint_1
        )
        control_joint_2 = (
            self.kp * error_joint_2
            + self.ki * self.integral_error_joint_2
            + self.kd * derivative_joint_2
        )

        control_joint_1 = max(-self.max_effort, min(self.max_effort, control_joint_1))
        control_joint_2 = max(-self.max_effort, min(self.max_effort, control_joint_2))

        control_msg = Float64MultiArray()
        control_msg.data = [control_joint_1, control_joint_2]
        self.control_commands_publisher.publish(control_msg)

def main(args=None):
    rclpy.init(args=args)
    control_node = ControlNode()
    control_node.declare_parameter('x', 0.0)
    control_node.declare_parameter('y', 0.0)

    '''part of code generated with AI to receive coordinates from terminal'''
    x_param = float(control_node.get_parameter('x').value)
    y_param = float(control_node.get_parameter('y').value)

    if x_param != 0.0 or y_param != 0.0:
        control_node.get_logger().info(f'Coordinates from launch params: x={x_param}, y={y_param}')
        control_node.request_desired_position(x_param, y_param)
    else:
        cli_args = [value for value in sys.argv[1:] if value != '--ros-args' and not value.startswith('-')]
        if len(cli_args) >= 2:
            x_value = float(cli_args[0])
            y_value = float(cli_args[1])
            control_node.get_logger().info(f'Coordinates from CLI args: x={x_value}, y={y_value}')
            control_node.request_desired_position(x_value, y_value)
        else:
            control_node.get_logger().info('No coordinates provided. Using defaults and waiting for commands.')
            control_node.get_logger().info('Usage with launch: ros2 launch control control.launch.py x:=0.5 y:=1.0')

    rclpy.spin(control_node)  # Keeps the program running until it is manually stopped
    control_node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main() 