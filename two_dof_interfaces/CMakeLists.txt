cmake_minimum_required(VERSION 3.8)
project(two_dof_interfaces)

find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)

rosidl_generate_interfaces(${PROJECT_NAME}
  "srv/CoordinateToJoint.srv"
)

ament_package()
