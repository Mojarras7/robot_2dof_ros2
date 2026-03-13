import math
from importlib import import_module

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import JointState

CoordinateToJoint = import_module('two_dof_interfaces.srv').CoordinateToJoint

class InverseKinematic(Node):
    def __init__(self):
        super().__init__('inverse_kinematic')
        self.get_logger().info('Inverse Kinematic node has been started.')

        self.l1 = 1.0
        self.l2 = 1.0

        self.joint1_lower = float(self.declare_parameter('joint1_lower', -3.14).value)
        self.joint1_upper = float(self.declare_parameter('joint1_upper', 3.14).value)
        self.joint2_lower = float(self.declare_parameter('joint2_lower', -2.6).value)
        self.joint2_upper = float(self.declare_parameter('joint2_upper', 2.6).value)

        self.current_joint_1 = 0.0
        self.current_joint_2 = 0.0
        self.has_joint_state = False

        self.create_subscription(JointState, '/joint_states', self.joint_state_callback, 10)
        self.srv = self.create_service(CoordinateToJoint, 'coordinate_to_joint', self.coordinate_to_joint_callback)

    @staticmethod
    def normalize_angle(angle: float) -> float:
        return math.atan2(math.sin(angle), math.cos(angle))

    def joint_state_callback(self, msg: JointState) -> None:
        if len(msg.position) >= 2:
            self.current_joint_1 = msg.position[0]
            self.current_joint_2 = msg.position[1]
            self.has_joint_state = True

    def within_limits(self, theta1: float, theta2: float) -> bool:
        return self.joint1_lower <= theta1 <= self.joint1_upper and self.joint2_lower <= theta2 <= self.joint2_upper

    def coordinate_to_joint_callback(self, request, response):
        x = request.x
        y = request.y

        distance = math.sqrt(x**2 + y**2)

        if distance > (self.l1 + self.l2) or distance < abs(self.l1 - self.l2):
            self.get_logger().warn('The point is out of reach for the robotic arm.')
            response.theta1 = float('nan')
            response.theta2 = float('nan')
            response.success = False
            response.message = 'Point out of reach'
            return

        cos_theta2 = (x**2 + y**2 - self.l1**2 - self.l2**2) / (2 * self.l1 * self.l2)
        cos_theta2 = max(-1.0, min(1.0, cos_theta2))

        theta2_options = [math.acos(cos_theta2), -math.acos(cos_theta2)]
        candidates = []
        
        '''part of code generated with AI to select the best IK solution based on joint limits and proximity to current joint state'''
        for theta2 in theta2_options:
            k1 = self.l1 + self.l2 * math.cos(theta2)
            k2 = self.l2 * math.sin(theta2)
            theta1 = math.atan2(y, x) - math.atan2(k2, k1)

            theta1 = self.normalize_angle(theta1)
            theta2 = self.normalize_angle(theta2)

            if self.within_limits(theta1, theta2):
                if self.has_joint_state:
                    d1 = self.normalize_angle(theta1 - self.current_joint_1)
                    d2 = self.normalize_angle(theta2 - self.current_joint_2)
                    score = d1 * d1 + d2 * d2
                else:
                    score = abs(theta1) + abs(theta2)
                candidates.append((score, theta1, theta2))

        if not candidates:
            self.get_logger().warn('No IK branch satisfies joint limits for the requested point.')
            response.theta1 = float('nan')
            response.theta2 = float('nan')
            response.success = False
            response.message = 'No IK branch within joint limits'
            return

        _, theta1, theta2 = min(candidates, key=lambda item: item[0])

        response.theta1 = theta1
        response.theta2 = theta2
        response.success = True
        response.message = 'OK'
        self.get_logger().info(f'Received coordinates: x={x:.2f}, y={y:.2f}')
        self.get_logger().info(f'Calculated joint angles: theta1={theta1:.2f}, theta2={theta2:.2f}')
        return response

def main(args=None):
    rclpy.init(args=args)
    inverse_kinematic = InverseKinematic()
    rclpy.spin(inverse_kinematic)
    inverse_kinematic.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()