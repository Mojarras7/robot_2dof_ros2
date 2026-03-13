import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription, TimerAction
from launch.conditions import IfCondition
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration, PythonExpression
from launch_ros.actions import Node
import xacro

def generate_launch_description():
    controller_mode = LaunchConfiguration('controller_mode')
    controller_mode_arg = DeclareLaunchArgument(
        'controller_mode',
        default_value='position',
        description='Controller to spawn: position or effort'
    )

    # ==============================================================================
    # 1. DEFINICIÓN DEL PAQUETE Y RUTAS
    # ==============================================================================
    pkg_name = 'simulation_2dof'    
    pkg_path = os.path.join(get_package_share_directory(pkg_name))
    
    urdf_path = os.path.join(pkg_path, 'urdf', 'robot_2dof.urdf')
    # rviz_config_path = os.path.join(pkg_path, 'rviz', 'view_robot.rviz')
    
    # NUEVO: Calculamos la ruta absoluta del YAML aquí en Python
    yaml_path = os.path.join(pkg_path, 'config', 'controllers.yaml')

    # ==============================================================================
    # 2. PROCESAR XACRO (Inyección Dinámica)
    # ==============================================================================
    # Le pasamos la ruta completa del YAML a la variable 'yaml_file_path' del URDF
    doc = xacro.process_file(urdf_path, mappings={'yaml_file_path': yaml_path})
    robot_desc = doc.toprettyxml(indent='  ')

    # ==============================================================================
    # 3. PUBLICADOR DEL ESTADO DEL ROBOT
    # ==============================================================================
    node_robot_state_publisher = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        output='screen',
        parameters=[{'robot_description': robot_desc, 'use_sim_time': True}]
    )

    # ==============================================================================
    # 4. GAZEBO HARMONIC Y SPAWN DEL ROBOT
    # ==============================================================================
    # Inicia el simulador de Gazebo
    # -r: Inicia la simulación inmediatamente (sin estar en pausa)
    # gz_args: Le pasa la ruta de nuestro mundo con gravedad planar (gravedad en -Y)
    world_path = os.path.join(pkg_path, 'worlds', 'planar_gravity.sdf')
    gazebo = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(get_package_share_directory('ros_gz_sim'), 'launch', 'gz_sim.launch.py')
        ),
        launch_arguments={'gz_args': f'-r {world_path}'}.items()
    )

    # Materializa el robot 2-DOF dentro del simulador
    # -topic: Lee la descripción URDF desde este topic de ROS
    # -name: Nombre de la entidad dentro de Gazebo
    # -x, -y, -z: Posición inicial en el mundo; Z=0.1 evita que el robot traspase el suelo visualmente
    # (Nota: Esto no interfiere con la gravedad en -Y, solo es la posición inicial en 3D)
    spawn_entity = Node(
        package='ros_gz_sim',
        executable='create',
        output='screen',
        arguments=['-topic', 'robot_description', '-name', 'pendulum_2dof', '-x', '0.0', '-y', '0.0', '-z', '0.1']
    )

    # ==============================================================================
    # 5. PUENTE ROS 2 - GAZEBO (BRIDGE)
    # ==============================================================================
    # Cruzamos el reloj general y las IMUs del robot
    bridge_node = Node(
        package='ros_gz_bridge',
        executable='parameter_bridge',
        arguments=[
            '/clock@rosgraph_msgs/msg/Clock[gz.msgs.Clock',
            '/link1/ruido_imu@sensor_msgs/msg/Imu[gz.msgs.IMU',
            '/link2/ruido_imu@sensor_msgs/msg/Imu[gz.msgs.IMU'
        ],
        output='screen'
    )

    # ==============================================================================
    # 6. VISUALIZACIÓN EN RVIZ 2
    # ==============================================================================
    # node_rviz = Node(
    #     package='rviz2',
    #     executable='rviz2',
    #     name='rviz2',
    #     output='screen',
    #     arguments=['-d', rviz_config_path],
    #     parameters=[{'use_sim_time': True}]
    # )

    # ==============================================================================
    # 7. SPAWNERS DE CONTROLADORES
    # ==============================================================================
    joint_state_broadcaster_spawner = Node(
        package='controller_manager',
        executable='spawner',
        arguments=['joint_state_broadcaster'],
        output='screen',
    )

    effort_controller_spawner = Node(
        package='controller_manager',
        executable='spawner',
        arguments=['effort_controller'],
        output='screen',
        condition=IfCondition(PythonExpression(["'", controller_mode, "' == 'effort'"]))
    )

    position_controller_spawner = Node(
        package='controller_manager',
        executable='spawner',
        arguments=['position_controller'],
        output='screen',
        condition=IfCondition(PythonExpression(["'", controller_mode, "' == 'position'"]))
    )

    # Los spawners arrancan 3 segundos después del spawn del robot
    delayed_controllers = TimerAction(
        period=3.0,
        actions=[joint_state_broadcaster_spawner, effort_controller_spawner, position_controller_spawner]
    )

    # ==============================================================================
    # ORQUESTACIÓN FINAL
    # ==============================================================================
    return LaunchDescription([
        controller_mode_arg,
        gazebo,
        node_robot_state_publisher,
        spawn_entity,
        bridge_node,
        delayed_controllers,
        #node_rviz,
    ])