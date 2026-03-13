# math module provides mathematical functions like sine, cosine, and square root
import math

# rclpy is the main ROS 2 Python client library. It lets us create nodes, publishers, and subscribers.
import rclpy
# Node is the base class for all ROS 2 nodes. We inherit from it to create our own node.
from rclpy.node import Node

# JointState is a standard ROS 2 message type used to communicate the state (angles, velocities) of robot joints.
from sensor_msgs.msg import JointState

# Import the custom service definition CoordinateToJoint. 
# A Service in ROS has a Request (input coordinates) and a Response (output joint angles).
from two_dof_interfaces.srv import CoordinateToJoint

class InverseKinematic(Node):
    # __init__ is the constructor method in Python. It's called when we create an instance of this class.
    def __init__(self):
        # Initialize the parent Node class with the name we want to give to our ROS node ('inverse_kinematic')
        super().__init__('inverse_kinematic')
        
        # get_logger() allows us to print messages to the console in a ROS-friendly way
        self.get_logger().info('Inverse Kinematic node has been started.')

        # Robot arm link lengths
        self.l1 = 1.0
        self.l2 = 1.0

        # We set a flag to alternate between "elbow down" and "elbow up" configurations
        # True = Elbow Up, False = Elbow Down
        self.use_elbow_up = False 

        # Parameters allow us to configure the node from outside (like launch files) without changing code.
        self.joint1_lower = float(self.declare_parameter('joint1_lower', -3.14).value)
        self.joint1_upper = float(self.declare_parameter('joint1_upper', 3.14).value)
        self.joint2_lower = float(self.declare_parameter('joint2_lower', -3.14).value)
        self.joint2_upper = float(self.declare_parameter('joint2_upper', 3.14).value)

        # We create a subscriber to listen to the '/joint_states' topic.
        # This gives us the current position of the robot's joints.
        # The '10' is the queue size (how many messages to hold if we process them slowly).
        self.create_subscription(JointState, '/joint_states', self.joint_state_callback, 10)
        
        # We create a service called 'coordinate_to_joint'. 
        # When another node calls this service, our 'coordinate_to_joint_callback' function will run.
        self.srv = self.create_service(CoordinateToJoint, 'coordinate_to_joint', self.coordinate_to_joint_callback)

    # @staticmethod means this function doesn't need to access 'self' (the class instance).
    # It just takes an input and returns an output.
    @staticmethod
    def normalize_angle(angle: float) -> float:
        # Keeps the angle between -pi and +pi
        return math.atan2(math.sin(angle), math.cos(angle))

    # This is a callback function. It runs automatically every time a new message arrives on '/joint_states'.
    def joint_state_callback(self, msg: JointState) -> None:
        pass # We don't really need the current joint states to alternate between elbow up/down

    # Helper method to check if calculated angles are within the robot's physical limits
    def within_limits(self, theta1: float, theta2: float) -> bool:
        return self.joint1_lower <= theta1 <= self.joint1_upper and self.joint2_lower <= theta2 <= self.joint2_upper

    # This function is triggered whenever another node uses our service.
    # 'request' has the input data (x, y). 'response' is what we will send back.
    def coordinate_to_joint_callback(self, request, response):
        x = request.x
        y = request.y

        # Calculate straight-line distance to the target point
        distance = math.sqrt(x**2 + y**2)

        # Check if the target is too far or too close
        if distance > (self.l1 + self.l2) or distance < abs(self.l1 - self.l2):
            self.get_logger().warn('The point is out of reach for the robotic arm.')
            response.success = False
            response.message = 'Point out of reach'
            return response

        # Cosine rule to find the angle of the second joint (elbow)
        cos_theta2 = (x**2 + y**2 - self.l1**2 - self.l2**2) / (2 * self.l1 * self.l2)
        # Prevent math domain errors from floating point inaccuracies
        cos_theta2 = max(-1.0, min(1.0, cos_theta2))

        # We have two possible angles for the elbow: one positive, one negative.
        # This translates to the "Elbow Up" and "Elbow Down" configurations.
        angle = math.acos(cos_theta2)
        
        # Alternate the configuration based on our flag
        if self.use_elbow_up:
            theta2 = -angle # Negative theta2 usually corresponds to elbow up in standard conventions
        else:
            theta2 = angle # Positive theta2 usually corresponds to elbow down

        # Calculate the angle of the first joint (shoulder) based on the chosen elbow angle
        k1 = self.l1 + self.l2 * math.cos(theta2)
        k2 = self.l2 * math.sin(theta2)
        theta1 = math.atan2(y, x) - math.atan2(k2, k1)

        # Normalize the angles
        theta1 = self.normalize_angle(theta1)
        theta2 = self.normalize_angle(theta2)

        # Check if the calculated angles break the robot's physical limits
        if not self.within_limits(theta1, theta2):
            self.get_logger().warn('Calculated IK branch is outside joint limits.')
            response.success = False
            response.message = 'No IK branch within joint limits'
            # Even if it failed, we flip the flag so next time it tries the other way
            self.use_elbow_up = not self.use_elbow_up
            return response

        # Save results to the response object
        response.theta1 = theta1
        response.theta2 = theta2
        response.success = True
        response.message = f'OK. Used configuration: {"Elbow Up" if self.use_elbow_up else "Elbow Down"}'
        
        self.get_logger().info(f'Received coords: x={x:.2f}, y={y:.2f} | Config: {"Elbow Up" if self.use_elbow_up else "Elbow Down"}')
        self.get_logger().info(f'Calculated joint angles: theta1={theta1:.2f}, theta2={theta2:.2f}')
        
        # Toggle (flip) the boolean flag for the next time we receive a request
        # 'not True' becomes False, and 'not False' becomes True.
        self.use_elbow_up = not self.use_elbow_up

        return response

# This is the main block that runs when the script is executed
def main(args=None):
    # Initialize the ROS 2 communications
    rclpy.init(args=args)
    # Create an instance of our node
    inverse_kinematic = InverseKinematic()
    # Spin keeps the node running, waiting for messages or service calls
    rclpy.spin(inverse_kinematic)
    # Once spin is stopped (e.g. by pressing Ctrl+C), clean up
    inverse_kinematic.destroy_node()
    rclpy.shutdown()

# This checks if this file is being run directly (rather than just being imported into another file).
if __name__ == '__main__':
    main()