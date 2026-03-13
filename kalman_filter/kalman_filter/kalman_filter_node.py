import numpy as np
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Imu


class AxisKalmanFilter:
    def __init__(self, process_noise: float, measurement_noise: float):
        self.process_noise = process_noise
        self.measurement_noise = measurement_noise

        self.x = np.array([[0.0], [0.0]])
        self.P = np.eye(2)
        self.H = np.array([[1.0, 0.0]])
        self.R = np.array([[measurement_noise]])

    def predict(self, dt: float):
        dt = max(dt, 1e-4)
        F = np.array([[1.0, dt], [0.0, 1.0]])
        G = np.array([[0.5 * dt * dt], [dt]])
        Q = (G @ G.T) * self.process_noise

        self.x = F @ self.x
        self.P = F @ self.P @ F.T + Q

    def update(self, measurement: float) -> float:
        z = np.array([[measurement]])
        S = self.H @ self.P @ self.H.T + self.R
        K = self.P @ self.H.T @ np.linalg.inv(S)
        innovation = z - (self.H @ self.x)
        self.x = self.x + K @ innovation

        I = np.eye(self.P.shape[0])
        self.P = (I - K @ self.H) @ self.P
        return float(self.x[0, 0])

    def variance(self) -> float:
        return float(self.P[0, 0])


class KalmanFilterNode(Node):
    def __init__(self):
        super().__init__('kalman_filter_node')
        self.get_logger().info('Kalman Filter Node started.')

        self.declare_parameter('input_topic_link1', '/link1/ruido_imu')
        self.declare_parameter('output_topic_link1', '/link1/imu_filtrada')
        self.declare_parameter('input_topic_link2', '/link2/ruido_imu')
        self.declare_parameter('output_topic_link2', '/link2/imu_filtrada')
        self.declare_parameter('process_noise', 0.01)
        self.declare_parameter('measurement_noise', 0.05)

        input_topic_link1 = self.get_parameter('input_topic_link1').get_parameter_value().string_value
        output_topic_link1 = self.get_parameter('output_topic_link1').get_parameter_value().string_value
        input_topic_link2 = self.get_parameter('input_topic_link2').get_parameter_value().string_value
        output_topic_link2 = self.get_parameter('output_topic_link2').get_parameter_value().string_value
        process_noise = self.get_parameter('process_noise').get_parameter_value().double_value
        measurement_noise = self.get_parameter('measurement_noise').get_parameter_value().double_value

        self.filters = {
            'link1': self._create_filter_bank(process_noise, measurement_noise),
            'link2': self._create_filter_bank(process_noise, measurement_noise),
        }

        self.publisher_link1 = self.create_publisher(Imu, output_topic_link1, 10)
        self.publisher_link2 = self.create_publisher(Imu, output_topic_link2, 10)

        self.subscription_link1 = self.create_subscription(
            Imu,
            input_topic_link1,
            lambda msg: self.imu_callback(msg, 'link1'),
            10,
        )
        self.subscription_link2 = self.create_subscription(
            Imu,
            input_topic_link2,
            lambda msg: self.imu_callback(msg, 'link2'),
            10,
        )

        self.get_logger().info(f'Subscribed to link1 IMU: {input_topic_link1}')
        self.get_logger().info(f'Publishing filtered link1 IMU to: {output_topic_link1}')
        self.get_logger().info(f'Subscribed to link2 IMU: {input_topic_link2}')
        self.get_logger().info(f'Publishing filtered link2 IMU to: {output_topic_link2}')

    def _create_filter_bank(self, process_noise: float, measurement_noise: float) -> dict:
        return {
            'angular': {
                'x': AxisKalmanFilter(process_noise, measurement_noise),
                'y': AxisKalmanFilter(process_noise, measurement_noise),
                'z': AxisKalmanFilter(process_noise, measurement_noise),
            },
            'linear': {
                'x': AxisKalmanFilter(process_noise, measurement_noise),
                'y': AxisKalmanFilter(process_noise, measurement_noise),
                'z': AxisKalmanFilter(process_noise, measurement_noise),
            },
            'last_time': None,
        }

    def _get_publisher(self, link_key: str):
        return self.publisher_link1 if link_key == 'link1' else self.publisher_link2

    def _compute_dt(self, msg: Imu, link_key: str) -> float:
        link_filter = self.filters[link_key]
        current_time = float(msg.header.stamp.sec) + float(msg.header.stamp.nanosec) * 1e-9

        if current_time == 0.0:
            if link_filter['last_time'] is None:
                link_filter['last_time'] = self.get_clock().now().nanoseconds * 1e-9
                return 0.01
            now_time = self.get_clock().now().nanoseconds * 1e-9
            dt = now_time - link_filter['last_time']
            link_filter['last_time'] = now_time
            return max(dt, 1e-4)

        if link_filter['last_time'] is None:
            link_filter['last_time'] = current_time
            return 0.01

        dt = current_time - link_filter['last_time']
        link_filter['last_time'] = current_time
        return max(dt, 1e-4)

    def imu_callback(self, msg: Imu, link_key: str):
        dt = self._compute_dt(msg, link_key)
        link_filter = self.filters[link_key]
        angular_filters = link_filter['angular']
        linear_filters = link_filter['linear']

        for axis in ['x', 'y', 'z']:
            angular_filters[axis].predict(dt)
            linear_filters[axis].predict(dt)

        filtered_msg = Imu()
        filtered_msg.header = msg.header
        filtered_msg.orientation = msg.orientation
        filtered_msg.orientation_covariance = msg.orientation_covariance

        filtered_msg.angular_velocity.x = angular_filters['x'].update(msg.angular_velocity.x)
        filtered_msg.angular_velocity.y = angular_filters['y'].update(msg.angular_velocity.y)
        filtered_msg.angular_velocity.z = angular_filters['z'].update(msg.angular_velocity.z)

        filtered_msg.linear_acceleration.x = linear_filters['x'].update(msg.linear_acceleration.x)
        filtered_msg.linear_acceleration.y = linear_filters['y'].update(msg.linear_acceleration.y)
        filtered_msg.linear_acceleration.z = linear_filters['z'].update(msg.linear_acceleration.z)

        filtered_msg.angular_velocity_covariance = [
            angular_filters['x'].variance(), 0.0, 0.0,
            0.0, angular_filters['y'].variance(), 0.0,
            0.0, 0.0, angular_filters['z'].variance(),
        ]

        filtered_msg.linear_acceleration_covariance = [
            linear_filters['x'].variance(), 0.0, 0.0,
            0.0, linear_filters['y'].variance(), 0.0,
            0.0, 0.0, linear_filters['z'].variance(),
        ]

        self._get_publisher(link_key).publish(filtered_msg)


def main(args=None):
    rclpy.init(args=args)
    node = KalmanFilterNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()

