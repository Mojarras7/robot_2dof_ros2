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
                'input_topic_link2': '/link2/ruido_imu',
                'q_angle': 0.001,
                'q_bias': 0.003,
                'r_measure': 0.03,
            }
        ],
    )

    comparison_node = Node(
        package='kalman_filter',
        executable='kalman_comparison_node',
        name='kalman_comparison_node',
        output='screen'
    )

    return LaunchDescription([kalman_node, comparison_node])
