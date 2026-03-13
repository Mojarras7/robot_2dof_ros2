// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from two_dof_interfaces:srv/CoordinateToJoint.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "two_dof_interfaces/srv/coordinate_to_joint.hpp"


#ifndef TWO_DOF_INTERFACES__SRV__DETAIL__COORDINATE_TO_JOINT__TRAITS_HPP_
#define TWO_DOF_INTERFACES__SRV__DETAIL__COORDINATE_TO_JOINT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "two_dof_interfaces/srv/detail/coordinate_to_joint__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace two_dof_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const CoordinateToJoint_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << ", ";
  }

  // member: y
  {
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const CoordinateToJoint_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const CoordinateToJoint_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace two_dof_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use two_dof_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const two_dof_interfaces::srv::CoordinateToJoint_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  two_dof_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use two_dof_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const two_dof_interfaces::srv::CoordinateToJoint_Request & msg)
{
  return two_dof_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<two_dof_interfaces::srv::CoordinateToJoint_Request>()
{
  return "two_dof_interfaces::srv::CoordinateToJoint_Request";
}

template<>
inline const char * name<two_dof_interfaces::srv::CoordinateToJoint_Request>()
{
  return "two_dof_interfaces/srv/CoordinateToJoint_Request";
}

template<>
struct has_fixed_size<two_dof_interfaces::srv::CoordinateToJoint_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<two_dof_interfaces::srv::CoordinateToJoint_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<two_dof_interfaces::srv::CoordinateToJoint_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace two_dof_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const CoordinateToJoint_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: theta1
  {
    out << "theta1: ";
    rosidl_generator_traits::value_to_yaml(msg.theta1, out);
    out << ", ";
  }

  // member: theta2
  {
    out << "theta2: ";
    rosidl_generator_traits::value_to_yaml(msg.theta2, out);
    out << ", ";
  }

  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const CoordinateToJoint_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: theta1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "theta1: ";
    rosidl_generator_traits::value_to_yaml(msg.theta1, out);
    out << "\n";
  }

  // member: theta2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "theta2: ";
    rosidl_generator_traits::value_to_yaml(msg.theta2, out);
    out << "\n";
  }

  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }

  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const CoordinateToJoint_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace two_dof_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use two_dof_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const two_dof_interfaces::srv::CoordinateToJoint_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  two_dof_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use two_dof_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const two_dof_interfaces::srv::CoordinateToJoint_Response & msg)
{
  return two_dof_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<two_dof_interfaces::srv::CoordinateToJoint_Response>()
{
  return "two_dof_interfaces::srv::CoordinateToJoint_Response";
}

template<>
inline const char * name<two_dof_interfaces::srv::CoordinateToJoint_Response>()
{
  return "two_dof_interfaces/srv/CoordinateToJoint_Response";
}

template<>
struct has_fixed_size<two_dof_interfaces::srv::CoordinateToJoint_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<two_dof_interfaces::srv::CoordinateToJoint_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<two_dof_interfaces::srv::CoordinateToJoint_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__traits.hpp"

namespace two_dof_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const CoordinateToJoint_Event & msg,
  std::ostream & out)
{
  out << "{";
  // member: info
  {
    out << "info: ";
    to_flow_style_yaml(msg.info, out);
    out << ", ";
  }

  // member: request
  {
    if (msg.request.size() == 0) {
      out << "request: []";
    } else {
      out << "request: [";
      size_t pending_items = msg.request.size();
      for (auto item : msg.request) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: response
  {
    if (msg.response.size() == 0) {
      out << "response: []";
    } else {
      out << "response: [";
      size_t pending_items = msg.response.size();
      for (auto item : msg.response) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const CoordinateToJoint_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: info
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "info:\n";
    to_block_style_yaml(msg.info, out, indentation + 2);
  }

  // member: request
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.request.size() == 0) {
      out << "request: []\n";
    } else {
      out << "request:\n";
      for (auto item : msg.request) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: response
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.response.size() == 0) {
      out << "response: []\n";
    } else {
      out << "response:\n";
      for (auto item : msg.response) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const CoordinateToJoint_Event & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace two_dof_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use two_dof_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const two_dof_interfaces::srv::CoordinateToJoint_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  two_dof_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use two_dof_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const two_dof_interfaces::srv::CoordinateToJoint_Event & msg)
{
  return two_dof_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<two_dof_interfaces::srv::CoordinateToJoint_Event>()
{
  return "two_dof_interfaces::srv::CoordinateToJoint_Event";
}

template<>
inline const char * name<two_dof_interfaces::srv::CoordinateToJoint_Event>()
{
  return "two_dof_interfaces/srv/CoordinateToJoint_Event";
}

template<>
struct has_fixed_size<two_dof_interfaces::srv::CoordinateToJoint_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<two_dof_interfaces::srv::CoordinateToJoint_Event>
  : std::integral_constant<bool, has_bounded_size<service_msgs::msg::ServiceEventInfo>::value && has_bounded_size<two_dof_interfaces::srv::CoordinateToJoint_Request>::value && has_bounded_size<two_dof_interfaces::srv::CoordinateToJoint_Response>::value> {};

template<>
struct is_message<two_dof_interfaces::srv::CoordinateToJoint_Event>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<two_dof_interfaces::srv::CoordinateToJoint>()
{
  return "two_dof_interfaces::srv::CoordinateToJoint";
}

template<>
inline const char * name<two_dof_interfaces::srv::CoordinateToJoint>()
{
  return "two_dof_interfaces/srv/CoordinateToJoint";
}

template<>
struct has_fixed_size<two_dof_interfaces::srv::CoordinateToJoint>
  : std::integral_constant<
    bool,
    has_fixed_size<two_dof_interfaces::srv::CoordinateToJoint_Request>::value &&
    has_fixed_size<two_dof_interfaces::srv::CoordinateToJoint_Response>::value
  >
{
};

template<>
struct has_bounded_size<two_dof_interfaces::srv::CoordinateToJoint>
  : std::integral_constant<
    bool,
    has_bounded_size<two_dof_interfaces::srv::CoordinateToJoint_Request>::value &&
    has_bounded_size<two_dof_interfaces::srv::CoordinateToJoint_Response>::value
  >
{
};

template<>
struct is_service<two_dof_interfaces::srv::CoordinateToJoint>
  : std::true_type
{
};

template<>
struct is_service_request<two_dof_interfaces::srv::CoordinateToJoint_Request>
  : std::true_type
{
};

template<>
struct is_service_response<two_dof_interfaces::srv::CoordinateToJoint_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // TWO_DOF_INTERFACES__SRV__DETAIL__COORDINATE_TO_JOINT__TRAITS_HPP_
