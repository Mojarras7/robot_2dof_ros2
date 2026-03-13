// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from two_dof_interfaces:srv/CoordinateToJoint.idl
// generated code does not contain a copyright notice

#include "two_dof_interfaces/srv/detail/coordinate_to_joint__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_two_dof_interfaces
const rosidl_type_hash_t *
two_dof_interfaces__srv__CoordinateToJoint__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x29, 0x5a, 0x23, 0x6f, 0xc3, 0xb3, 0xde, 0x80,
      0x2d, 0xe1, 0x66, 0x67, 0xed, 0x81, 0xd4, 0x04,
      0x94, 0xef, 0xa2, 0xb8, 0xfa, 0x57, 0x54, 0x8f,
      0x1c, 0x3a, 0xc5, 0xc7, 0x9c, 0x9c, 0xfb, 0x57,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_two_dof_interfaces
const rosidl_type_hash_t *
two_dof_interfaces__srv__CoordinateToJoint_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x9e, 0xb0, 0x0d, 0xb0, 0xcd, 0x86, 0x87, 0xcd,
      0xbf, 0xba, 0x26, 0x49, 0x7f, 0xbc, 0x9b, 0xb0,
      0x0f, 0x25, 0x97, 0xf3, 0x16, 0xac, 0x64, 0xdf,
      0x5b, 0x00, 0x4c, 0xef, 0xe0, 0x96, 0x9f, 0x36,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_two_dof_interfaces
const rosidl_type_hash_t *
two_dof_interfaces__srv__CoordinateToJoint_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xb3, 0x7d, 0x15, 0xf6, 0x77, 0xb8, 0xdc, 0x50,
      0xca, 0xb6, 0xfc, 0xeb, 0xb0, 0xb8, 0x7d, 0x91,
      0x03, 0xe6, 0x94, 0xad, 0xa7, 0x69, 0x1a, 0xc8,
      0xc1, 0xe5, 0xea, 0x2d, 0xa0, 0x58, 0xe6, 0x56,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_two_dof_interfaces
const rosidl_type_hash_t *
two_dof_interfaces__srv__CoordinateToJoint_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x25, 0x3c, 0x63, 0x10, 0xd0, 0xd1, 0xa3, 0x3a,
      0xbc, 0xc4, 0x39, 0xb8, 0x87, 0x59, 0xdb, 0x1b,
      0x53, 0x45, 0x68, 0x9d, 0x4c, 0xd3, 0x2c, 0x1a,
      0x91, 0x51, 0x86, 0x4b, 0xda, 0x6c, 0xca, 0x62,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "service_msgs/msg/detail/service_event_info__functions.h"
#include "builtin_interfaces/msg/detail/time__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
static const rosidl_type_hash_t service_msgs__msg__ServiceEventInfo__EXPECTED_HASH = {1, {
    0x41, 0xbc, 0xbb, 0xe0, 0x7a, 0x75, 0xc9, 0xb5,
    0x2b, 0xc9, 0x6b, 0xfd, 0x5c, 0x24, 0xd7, 0xf0,
    0xfc, 0x0a, 0x08, 0xc0, 0xcb, 0x79, 0x21, 0xb3,
    0x37, 0x3c, 0x57, 0x32, 0x34, 0x5a, 0x6f, 0x45,
  }};
#endif

static char two_dof_interfaces__srv__CoordinateToJoint__TYPE_NAME[] = "two_dof_interfaces/srv/CoordinateToJoint";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";
static char two_dof_interfaces__srv__CoordinateToJoint_Event__TYPE_NAME[] = "two_dof_interfaces/srv/CoordinateToJoint_Event";
static char two_dof_interfaces__srv__CoordinateToJoint_Request__TYPE_NAME[] = "two_dof_interfaces/srv/CoordinateToJoint_Request";
static char two_dof_interfaces__srv__CoordinateToJoint_Response__TYPE_NAME[] = "two_dof_interfaces/srv/CoordinateToJoint_Response";

// Define type names, field names, and default values
static char two_dof_interfaces__srv__CoordinateToJoint__FIELD_NAME__request_message[] = "request_message";
static char two_dof_interfaces__srv__CoordinateToJoint__FIELD_NAME__response_message[] = "response_message";
static char two_dof_interfaces__srv__CoordinateToJoint__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field two_dof_interfaces__srv__CoordinateToJoint__FIELDS[] = {
  {
    {two_dof_interfaces__srv__CoordinateToJoint__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {two_dof_interfaces__srv__CoordinateToJoint_Request__TYPE_NAME, 48, 48},
    },
    {NULL, 0, 0},
  },
  {
    {two_dof_interfaces__srv__CoordinateToJoint__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {two_dof_interfaces__srv__CoordinateToJoint_Response__TYPE_NAME, 49, 49},
    },
    {NULL, 0, 0},
  },
  {
    {two_dof_interfaces__srv__CoordinateToJoint__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {two_dof_interfaces__srv__CoordinateToJoint_Event__TYPE_NAME, 46, 46},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription two_dof_interfaces__srv__CoordinateToJoint__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
  {
    {two_dof_interfaces__srv__CoordinateToJoint_Event__TYPE_NAME, 46, 46},
    {NULL, 0, 0},
  },
  {
    {two_dof_interfaces__srv__CoordinateToJoint_Request__TYPE_NAME, 48, 48},
    {NULL, 0, 0},
  },
  {
    {two_dof_interfaces__srv__CoordinateToJoint_Response__TYPE_NAME, 49, 49},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
two_dof_interfaces__srv__CoordinateToJoint__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {two_dof_interfaces__srv__CoordinateToJoint__TYPE_NAME, 40, 40},
      {two_dof_interfaces__srv__CoordinateToJoint__FIELDS, 3, 3},
    },
    {two_dof_interfaces__srv__CoordinateToJoint__REFERENCED_TYPE_DESCRIPTIONS, 5, 5},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = two_dof_interfaces__srv__CoordinateToJoint_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = two_dof_interfaces__srv__CoordinateToJoint_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[4].fields = two_dof_interfaces__srv__CoordinateToJoint_Response__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char two_dof_interfaces__srv__CoordinateToJoint_Request__FIELD_NAME__x[] = "x";
static char two_dof_interfaces__srv__CoordinateToJoint_Request__FIELD_NAME__y[] = "y";

static rosidl_runtime_c__type_description__Field two_dof_interfaces__srv__CoordinateToJoint_Request__FIELDS[] = {
  {
    {two_dof_interfaces__srv__CoordinateToJoint_Request__FIELD_NAME__x, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {two_dof_interfaces__srv__CoordinateToJoint_Request__FIELD_NAME__y, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
two_dof_interfaces__srv__CoordinateToJoint_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {two_dof_interfaces__srv__CoordinateToJoint_Request__TYPE_NAME, 48, 48},
      {two_dof_interfaces__srv__CoordinateToJoint_Request__FIELDS, 2, 2},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char two_dof_interfaces__srv__CoordinateToJoint_Response__FIELD_NAME__theta1[] = "theta1";
static char two_dof_interfaces__srv__CoordinateToJoint_Response__FIELD_NAME__theta2[] = "theta2";
static char two_dof_interfaces__srv__CoordinateToJoint_Response__FIELD_NAME__success[] = "success";
static char two_dof_interfaces__srv__CoordinateToJoint_Response__FIELD_NAME__message[] = "message";

static rosidl_runtime_c__type_description__Field two_dof_interfaces__srv__CoordinateToJoint_Response__FIELDS[] = {
  {
    {two_dof_interfaces__srv__CoordinateToJoint_Response__FIELD_NAME__theta1, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {two_dof_interfaces__srv__CoordinateToJoint_Response__FIELD_NAME__theta2, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {two_dof_interfaces__srv__CoordinateToJoint_Response__FIELD_NAME__success, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {two_dof_interfaces__srv__CoordinateToJoint_Response__FIELD_NAME__message, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
two_dof_interfaces__srv__CoordinateToJoint_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {two_dof_interfaces__srv__CoordinateToJoint_Response__TYPE_NAME, 49, 49},
      {two_dof_interfaces__srv__CoordinateToJoint_Response__FIELDS, 4, 4},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char two_dof_interfaces__srv__CoordinateToJoint_Event__FIELD_NAME__info[] = "info";
static char two_dof_interfaces__srv__CoordinateToJoint_Event__FIELD_NAME__request[] = "request";
static char two_dof_interfaces__srv__CoordinateToJoint_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field two_dof_interfaces__srv__CoordinateToJoint_Event__FIELDS[] = {
  {
    {two_dof_interfaces__srv__CoordinateToJoint_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {two_dof_interfaces__srv__CoordinateToJoint_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {two_dof_interfaces__srv__CoordinateToJoint_Request__TYPE_NAME, 48, 48},
    },
    {NULL, 0, 0},
  },
  {
    {two_dof_interfaces__srv__CoordinateToJoint_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {two_dof_interfaces__srv__CoordinateToJoint_Response__TYPE_NAME, 49, 49},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription two_dof_interfaces__srv__CoordinateToJoint_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
  {
    {two_dof_interfaces__srv__CoordinateToJoint_Request__TYPE_NAME, 48, 48},
    {NULL, 0, 0},
  },
  {
    {two_dof_interfaces__srv__CoordinateToJoint_Response__TYPE_NAME, 49, 49},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
two_dof_interfaces__srv__CoordinateToJoint_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {two_dof_interfaces__srv__CoordinateToJoint_Event__TYPE_NAME, 46, 46},
      {two_dof_interfaces__srv__CoordinateToJoint_Event__FIELDS, 3, 3},
    },
    {two_dof_interfaces__srv__CoordinateToJoint_Event__REFERENCED_TYPE_DESCRIPTIONS, 4, 4},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = two_dof_interfaces__srv__CoordinateToJoint_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = two_dof_interfaces__srv__CoordinateToJoint_Response__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "float64 x\n"
  "float64 y\n"
  "---\n"
  "float64 theta1\n"
  "float64 theta2\n"
  "bool success\n"
  "string message";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
two_dof_interfaces__srv__CoordinateToJoint__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {two_dof_interfaces__srv__CoordinateToJoint__TYPE_NAME, 40, 40},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 82, 82},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
two_dof_interfaces__srv__CoordinateToJoint_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {two_dof_interfaces__srv__CoordinateToJoint_Request__TYPE_NAME, 48, 48},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
two_dof_interfaces__srv__CoordinateToJoint_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {two_dof_interfaces__srv__CoordinateToJoint_Response__TYPE_NAME, 49, 49},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
two_dof_interfaces__srv__CoordinateToJoint_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {two_dof_interfaces__srv__CoordinateToJoint_Event__TYPE_NAME, 46, 46},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
two_dof_interfaces__srv__CoordinateToJoint__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[6];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 6, 6};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *two_dof_interfaces__srv__CoordinateToJoint__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    sources[3] = *two_dof_interfaces__srv__CoordinateToJoint_Event__get_individual_type_description_source(NULL);
    sources[4] = *two_dof_interfaces__srv__CoordinateToJoint_Request__get_individual_type_description_source(NULL);
    sources[5] = *two_dof_interfaces__srv__CoordinateToJoint_Response__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
two_dof_interfaces__srv__CoordinateToJoint_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *two_dof_interfaces__srv__CoordinateToJoint_Request__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
two_dof_interfaces__srv__CoordinateToJoint_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *two_dof_interfaces__srv__CoordinateToJoint_Response__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
two_dof_interfaces__srv__CoordinateToJoint_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[5];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 5, 5};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *two_dof_interfaces__srv__CoordinateToJoint_Event__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    sources[3] = *two_dof_interfaces__srv__CoordinateToJoint_Request__get_individual_type_description_source(NULL);
    sources[4] = *two_dof_interfaces__srv__CoordinateToJoint_Response__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
