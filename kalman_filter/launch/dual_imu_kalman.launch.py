from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    kalman_node = Node(
        package='kalman_filter',
        executable='kalman_filter_node',
        name='kalman_filter_node',
        output='screen',
        parameters=[
            {
                'input_topic_link1': '/link1/ruido_imu',
                'output_topic_link1': '/link1/imu_filtrada',
                'input_topic_link2': '/link2/ruido_imu',
                'output_topic_link2': '/link2/imu_filtrada',
                'process_noise': 0.01,
                'measurement_noise': 0.05,
            }
        ],
    )

    return LaunchDescription([kalman_node])
