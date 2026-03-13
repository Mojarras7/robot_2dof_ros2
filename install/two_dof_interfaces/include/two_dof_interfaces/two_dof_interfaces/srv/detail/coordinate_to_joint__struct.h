// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from two_dof_interfaces:srv/CoordinateToJoint.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "two_dof_interfaces/srv/coordinate_to_joint.h"


#ifndef TWO_DOF_INTERFACES__SRV__DETAIL__COORDINATE_TO_JOINT__STRUCT_H_
#define TWO_DOF_INTERFACES__SRV__DETAIL__COORDINATE_TO_JOINT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/CoordinateToJoint in the package two_dof_interfaces.
typedef struct two_dof_interfaces__srv__CoordinateToJoint_Request
{
  double x;
  double y;
} two_dof_interfaces__srv__CoordinateToJoint_Request;

// Struct for a sequence of two_dof_interfaces__srv__CoordinateToJoint_Request.
typedef struct two_dof_interfaces__srv__CoordinateToJoint_Request__Sequence
{
  two_dof_interfaces__srv__CoordinateToJoint_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} two_dof_interfaces__srv__CoordinateToJoint_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/CoordinateToJoint in the package two_dof_interfaces.
typedef struct two_dof_interfaces__srv__CoordinateToJoint_Response
{
  double theta1;
  double theta2;
  bool success;
  rosidl_runtime_c__String message;
} two_dof_interfaces__srv__CoordinateToJoint_Response;

// Struct for a sequence of two_dof_interfaces__srv__CoordinateToJoint_Response.
typedef struct two_dof_interfaces__srv__CoordinateToJoint_Response__Sequence
{
  two_dof_interfaces__srv__CoordinateToJoint_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} two_dof_interfaces__srv__CoordinateToJoint_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  two_dof_interfaces__srv__CoordinateToJoint_Event__request__MAX_SIZE = 1
};
// response
enum
{
  two_dof_interfaces__srv__CoordinateToJoint_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/CoordinateToJoint in the package two_dof_interfaces.
typedef struct two_dof_interfaces__srv__CoordinateToJoint_Event
{
  service_msgs__msg__ServiceEventInfo info;
  two_dof_interfaces__srv__CoordinateToJoint_Request__Sequence request;
  two_dof_interfaces__srv__CoordinateToJoint_Response__Sequence response;
} two_dof_interfaces__srv__CoordinateToJoint_Event;

// Struct for a sequence of two_dof_interfaces__srv__CoordinateToJoint_Event.
typedef struct two_dof_interfaces__srv__CoordinateToJoint_Event__Sequence
{
  two_dof_interfaces__srv__CoordinateToJoint_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} two_dof_interfaces__srv__CoordinateToJoint_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TWO_DOF_INTERFACES__SRV__DETAIL__COORDINATE_TO_JOINT__STRUCT_H_
