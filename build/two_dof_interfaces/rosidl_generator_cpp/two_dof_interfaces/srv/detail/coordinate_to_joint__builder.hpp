// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from two_dof_interfaces:srv/CoordinateToJoint.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "two_dof_interfaces/srv/coordinate_to_joint.hpp"


#ifndef TWO_DOF_INTERFACES__SRV__DETAIL__COORDINATE_TO_JOINT__BUILDER_HPP_
#define TWO_DOF_INTERFACES__SRV__DETAIL__COORDINATE_TO_JOINT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "two_dof_interfaces/srv/detail/coordinate_to_joint__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace two_dof_interfaces
{

namespace srv
{

namespace builder
{

class Init_CoordinateToJoint_Request_y
{
public:
  explicit Init_CoordinateToJoint_Request_y(::two_dof_interfaces::srv::CoordinateToJoint_Request & msg)
  : msg_(msg)
  {}
  ::two_dof_interfaces::srv::CoordinateToJoint_Request y(::two_dof_interfaces::srv::CoordinateToJoint_Request::_y_type arg)
  {
    msg_.y = std::move(arg);
    return std::move(msg_);
  }

private:
  ::two_dof_interfaces::srv::CoordinateToJoint_Request msg_;
};

class Init_CoordinateToJoint_Request_x
{
public:
  Init_CoordinateToJoint_Request_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CoordinateToJoint_Request_y x(::two_dof_interfaces::srv::CoordinateToJoint_Request::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_CoordinateToJoint_Request_y(msg_);
  }

private:
  ::two_dof_interfaces::srv::CoordinateToJoint_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::two_dof_interfaces::srv::CoordinateToJoint_Request>()
{
  return two_dof_interfaces::srv::builder::Init_CoordinateToJoint_Request_x();
}

}  // namespace two_dof_interfaces


namespace two_dof_interfaces
{

namespace srv
{

namespace builder
{

class Init_CoordinateToJoint_Response_message
{
public:
  explicit Init_CoordinateToJoint_Response_message(::two_dof_interfaces::srv::CoordinateToJoint_Response & msg)
  : msg_(msg)
  {}
  ::two_dof_interfaces::srv::CoordinateToJoint_Response message(::two_dof_interfaces::srv::CoordinateToJoint_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::two_dof_interfaces::srv::CoordinateToJoint_Response msg_;
};

class Init_CoordinateToJoint_Response_success
{
public:
  explicit Init_CoordinateToJoint_Response_success(::two_dof_interfaces::srv::CoordinateToJoint_Response & msg)
  : msg_(msg)
  {}
  Init_CoordinateToJoint_Response_message success(::two_dof_interfaces::srv::CoordinateToJoint_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_CoordinateToJoint_Response_message(msg_);
  }

private:
  ::two_dof_interfaces::srv::CoordinateToJoint_Response msg_;
};

class Init_CoordinateToJoint_Response_theta2
{
public:
  explicit Init_CoordinateToJoint_Response_theta2(::two_dof_interfaces::srv::CoordinateToJoint_Response & msg)
  : msg_(msg)
  {}
  Init_CoordinateToJoint_Response_success theta2(::two_dof_interfaces::srv::CoordinateToJoint_Response::_theta2_type arg)
  {
    msg_.theta2 = std::move(arg);
    return Init_CoordinateToJoint_Response_success(msg_);
  }

private:
  ::two_dof_interfaces::srv::CoordinateToJoint_Response msg_;
};

class Init_CoordinateToJoint_Response_theta1
{
public:
  Init_CoordinateToJoint_Response_theta1()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CoordinateToJoint_Response_theta2 theta1(::two_dof_interfaces::srv::CoordinateToJoint_Response::_theta1_type arg)
  {
    msg_.theta1 = std::move(arg);
    return Init_CoordinateToJoint_Response_theta2(msg_);
  }

private:
  ::two_dof_interfaces::srv::CoordinateToJoint_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::two_dof_interfaces::srv::CoordinateToJoint_Response>()
{
  return two_dof_interfaces::srv::builder::Init_CoordinateToJoint_Response_theta1();
}

}  // namespace two_dof_interfaces


namespace two_dof_interfaces
{

namespace srv
{

namespace builder
{

class Init_CoordinateToJoint_Event_response
{
public:
  explicit Init_CoordinateToJoint_Event_response(::two_dof_interfaces::srv::CoordinateToJoint_Event & msg)
  : msg_(msg)
  {}
  ::two_dof_interfaces::srv::CoordinateToJoint_Event response(::two_dof_interfaces::srv::CoordinateToJoint_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::two_dof_interfaces::srv::CoordinateToJoint_Event msg_;
};

class Init_CoordinateToJoint_Event_request
{
public:
  explicit Init_CoordinateToJoint_Event_request(::two_dof_interfaces::srv::CoordinateToJoint_Event & msg)
  : msg_(msg)
  {}
  Init_CoordinateToJoint_Event_response request(::two_dof_interfaces::srv::CoordinateToJoint_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_CoordinateToJoint_Event_response(msg_);
  }

private:
  ::two_dof_interfaces::srv::CoordinateToJoint_Event msg_;
};

class Init_CoordinateToJoint_Event_info
{
public:
  Init_CoordinateToJoint_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CoordinateToJoint_Event_request info(::two_dof_interfaces::srv::CoordinateToJoint_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_CoordinateToJoint_Event_request(msg_);
  }

private:
  ::two_dof_interfaces::srv::CoordinateToJoint_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::two_dof_interfaces::srv::CoordinateToJoint_Event>()
{
  return two_dof_interfaces::srv::builder::Init_CoordinateToJoint_Event_info();
}

}  // namespace two_dof_interfaces

#endif  // TWO_DOF_INTERFACES__SRV__DETAIL__COORDINATE_TO_JOINT__BUILDER_HPP_
