import rclpy
from rclpy.node import Node
from sensor_msgs.msg import JointState

class KalmanComparisonNode(Node):
    def __init__(self):
        super().__init__('kalman_comparison_node')
        self.get_logger().info('Kalman Comparison Node Started. Listening to both topics...')

        self.true_state = None
        self.estimated_state = None

        self.sub_true = self.create_subscription(
            JointState, '/joint_states', self.true_callback, 10)
            
        self.sub_estim = self.create_subscription(
            JointState, '/kalman_joint_states', self.estim_callback, 10)
            
        # Timer to print side by side every 1 second
        self.timer = self.create_timer(1.0, self.timer_callback)

    def true_callback(self, msg):
        self.true_state = msg

    def estim_callback(self, msg):
        self.estimated_state = msg

    def timer_callback(self):
        if self.true_state and self.estimated_state:
            # We want to make sure we are grabbing the correct joints.
            # Usually /joint_states comes in as [joint1, joint2]
            
            # Find index of joint1 and joint2 in the true messages 
            try:
                t_idx1 = self.true_state.name.index('joint1')
                t_idx2 = self.true_state.name.index('joint2')
                
                true_j1 = self.true_state.position[t_idx1]
                true_j2 = self.true_state.position[t_idx2]
                
                estim_j1 = self.estimated_state.position[0]
                estim_j2 = self.estimated_state.position[1]
                
                self.get_logger().info(f'---')
                self.get_logger().info(f'Joint 1 | True: {true_j1:+.3f} | Kalman: {estim_j1:+.3f} | Diff: {abs(true_j1 - estim_j1):.3f}')
                self.get_logger().info(f'Joint 2 | True: {true_j2:+.3f} | Kalman: {estim_j2:+.3f} | Diff: {abs(true_j2 - estim_j2):.3f}')
            except ValueError:
                self.get_logger().warn("Could not find 'joint1' or 'joint2' in /joint_states array.")

def main(args=None):
    rclpy.init(args=args)
    node = KalmanComparisonNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
