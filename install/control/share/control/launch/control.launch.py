from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description():
    x_arg = DeclareLaunchArgument('x', default_value='0.0', description='desired X coordinate')
    y_arg = DeclareLaunchArgument('y', default_value='0.0', description='desired Y coordinate')

    inverse_kinematic_node = Node(
        package='control',
        executable='inverse_kinematic',
        name='inverse_kinematic',
        output='screen',
    )

    control_node = Node(
        package='control',
        executable='control_node',
        name='control_node',
        output='screen',
        parameters=[
            {'x': LaunchConfiguration('x')},
            {'y': LaunchConfiguration('y')},
        ],
    )

    return LaunchDescription([
        x_arg,
        y_arg,
        inverse_kinematic_node,
        control_node,
    ])
