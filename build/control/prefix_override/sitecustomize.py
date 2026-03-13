import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/media/mojarras/Wiwi/sinFiltro/robot_2dof_ros2/install/control'
