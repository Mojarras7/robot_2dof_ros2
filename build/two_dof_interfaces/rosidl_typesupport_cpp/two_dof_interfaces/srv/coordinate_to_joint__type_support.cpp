// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from two_dof_interfaces:srv/CoordinateToJoint.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "two_dof_interfaces/srv/detail/coordinate_to_joint__functions.h"
#include "two_dof_interfaces/srv/detail/coordinate_to_joint__struct.hpp"
#include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
#include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace two_dof_interfaces
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _CoordinateToJoint_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _CoordinateToJoint_Request_type_support_ids_t;

static const _CoordinateToJoint_Request_type_support_ids_t _CoordinateToJoint_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _CoordinateToJoint_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _CoordinateToJoint_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _CoordinateToJoint_Request_type_support_symbol_names_t _CoordinateToJoint_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, two_dof_interfaces, srv, CoordinateToJoint_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, two_dof_interfaces, srv, CoordinateToJoint_Request)),
  }
};

typedef struct _CoordinateToJoint_Request_type_support_data_t
{
  void * data[2];
} _CoordinateToJoint_Request_type_support_data_t;

static _CoordinateToJoint_Request_type_support_data_t _CoordinateToJoint_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _CoordinateToJoint_Request_message_typesupport_map = {
  2,
  "two_dof_interfaces",
  &_CoordinateToJoint_Request_message_typesupport_ids.typesupport_identifier[0],
  &_CoordinateToJoint_Request_message_typesupport_symbol_names.symbol_name[0],
  &_CoordinateToJoint_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t CoordinateToJoint_Request_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_CoordinateToJoint_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &two_dof_interfaces__srv__CoordinateToJoint_Request__get_type_hash,
  &two_dof_interfaces__srv__CoordinateToJoint_Request__get_type_description,
  &two_dof_interfaces__srv__CoordinateToJoint_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace two_dof_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<two_dof_interfaces::srv::CoordinateToJoint_Request>()
{
  return &::two_dof_interfaces::srv::rosidl_typesupport_cpp::CoordinateToJoint_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, two_dof_interfaces, srv, CoordinateToJoint_Request)() {
  return get_message_type_support_handle<two_dof_interfaces::srv::CoordinateToJoint_Request>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "two_dof_interfaces/srv/detail/coordinate_to_joint__functions.h"
// already included above
// #include "two_dof_interfaces/srv/detail/coordinate_to_joint__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace two_dof_interfaces
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _CoordinateToJoint_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _CoordinateToJoint_Response_type_support_ids_t;

static const _CoordinateToJoint_Response_type_support_ids_t _CoordinateToJoint_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _CoordinateToJoint_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _CoordinateToJoint_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _CoordinateToJoint_Response_type_support_symbol_names_t _CoordinateToJoint_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, two_dof_interfaces, srv, CoordinateToJoint_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, two_dof_interfaces, srv, CoordinateToJoint_Response)),
  }
};

typedef struct _CoordinateToJoint_Response_type_support_data_t
{
  void * data[2];
} _CoordinateToJoint_Response_type_support_data_t;

static _CoordinateToJoint_Response_type_support_data_t _CoordinateToJoint_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _CoordinateToJoint_Response_message_typesupport_map = {
  2,
  "two_dof_interfaces",
  &_CoordinateToJoint_Response_message_typesupport_ids.typesupport_identifier[0],
  &_CoordinateToJoint_Response_message_typesupport_symbol_names.symbol_name[0],
  &_CoordinateToJoint_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t CoordinateToJoint_Response_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_CoordinateToJoint_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &two_dof_interfaces__srv__CoordinateToJoint_Response__get_type_hash,
  &two_dof_interfaces__srv__CoordinateToJoint_Response__get_type_description,
  &two_dof_interfaces__srv__CoordinateToJoint_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace two_dof_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<two_dof_interfaces::srv::CoordinateToJoint_Response>()
{
  return &::two_dof_interfaces::srv::rosidl_typesupport_cpp::CoordinateToJoint_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, two_dof_interfaces, srv, CoordinateToJoint_Response)() {
  return get_message_type_support_handle<two_dof_interfaces::srv::CoordinateToJoint_Response>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "two_dof_interfaces/srv/detail/coordinate_to_joint__functions.h"
// already included above
// #include "two_dof_interfaces/srv/detail/coordinate_to_joint__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace two_dof_interfaces
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _CoordinateToJoint_Event_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _CoordinateToJoint_Event_type_support_ids_t;

static const _CoordinateToJoint_Event_type_support_ids_t _CoordinateToJoint_Event_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _CoordinateToJoint_Event_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _CoordinateToJoint_Event_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _CoordinateToJoint_Event_type_support_symbol_names_t _CoordinateToJoint_Event_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, two_dof_interfaces, srv, CoordinateToJoint_Event)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, two_dof_interfaces, srv, CoordinateToJoint_Event)),
  }
};

typedef struct _CoordinateToJoint_Event_type_support_data_t
{
  void * data[2];
} _CoordinateToJoint_Event_type_support_data_t;

static _CoordinateToJoint_Event_type_support_data_t _CoordinateToJoint_Event_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _CoordinateToJoint_Event_message_typesupport_map = {
  2,
  "two_dof_interfaces",
  &_CoordinateToJoint_Event_message_typesupport_ids.typesupport_identifier[0],
  &_CoordinateToJoint_Event_message_typesupport_symbol_names.symbol_name[0],
  &_CoordinateToJoint_Event_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t CoordinateToJoint_Event_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_CoordinateToJoint_Event_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &two_dof_interfaces__srv__CoordinateToJoint_Event__get_type_hash,
  &two_dof_interfaces__srv__CoordinateToJoint_Event__get_type_description,
  &two_dof_interfaces__srv__CoordinateToJoint_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace two_dof_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<two_dof_interfaces::srv::CoordinateToJoint_Event>()
{
  return &::two_dof_interfaces::srv::rosidl_typesupport_cpp::CoordinateToJoint_Event_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, two_dof_interfaces, srv, CoordinateToJoint_Event)() {
  return get_message_type_support_handle<two_dof_interfaces::srv::CoordinateToJoint_Event>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "two_dof_interfaces/srv/detail/coordinate_to_joint__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/service_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace two_dof_interfaces
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _CoordinateToJoint_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _CoordinateToJoint_type_support_ids_t;

static const _CoordinateToJoint_type_support_ids_t _CoordinateToJoint_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _CoordinateToJoint_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _CoordinateToJoint_type_support_symbol_names_t;
#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _CoordinateToJoint_type_support_symbol_names_t _CoordinateToJoint_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, two_dof_interfaces, srv, CoordinateToJoint)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, two_dof_interfaces, srv, CoordinateToJoint)),
  }
};

typedef struct _CoordinateToJoint_type_support_data_t
{
  void * data[2];
} _CoordinateToJoint_type_support_data_t;

static _CoordinateToJoint_type_support_data_t _CoordinateToJoint_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _CoordinateToJoint_service_typesupport_map = {
  2,
  "two_dof_interfaces",
  &_CoordinateToJoint_service_typesupport_ids.typesupport_identifier[0],
  &_CoordinateToJoint_service_typesupport_symbol_names.symbol_name[0],
  &_CoordinateToJoint_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t CoordinateToJoint_service_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_CoordinateToJoint_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
  ::rosidl_typesupport_cpp::get_message_type_support_handle<two_dof_interfaces::srv::CoordinateToJoint_Request>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<two_dof_interfaces::srv::CoordinateToJoint_Response>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<two_dof_interfaces::srv::CoordinateToJoint_Event>(),
  &::rosidl_typesupport_cpp::service_create_event_message<two_dof_interfaces::srv::CoordinateToJoint>,
  &::rosidl_typesupport_cpp::service_destroy_event_message<two_dof_interfaces::srv::CoordinateToJoint>,
  &two_dof_interfaces__srv__CoordinateToJoint__get_type_hash,
  &two_dof_interfaces__srv__CoordinateToJoint__get_type_description,
  &two_dof_interfaces__srv__CoordinateToJoint__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace two_dof_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<two_dof_interfaces::srv::CoordinateToJoint>()
{
  return &::two_dof_interfaces::srv::rosidl_typesupport_cpp::CoordinateToJoint_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_cpp, two_dof_interfaces, srv, CoordinateToJoint)() {
  return ::rosidl_typesupport_cpp::get_service_type_support_handle<two_dof_interfaces::srv::CoordinateToJoint>();
}

#ifdef __cplusplus
}
#endif
