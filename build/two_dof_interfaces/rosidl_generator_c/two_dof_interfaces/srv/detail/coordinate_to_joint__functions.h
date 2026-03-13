// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from two_dof_interfaces:srv/CoordinateToJoint.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "two_dof_interfaces/srv/coordinate_to_joint.h"


#ifndef TWO_DOF_INTERFACES__SRV__DETAIL__COORDINATE_TO_JOINT__FUNCTIONS_H_
#define TWO_DOF_INTERFACES__SRV__DETAIL__COORDINATE_TO_JOINT__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/action_type_support_struct.h"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_runtime_c/service_type_support_struct.h"
#include "rosidl_runtime_c/type_description/type_description__struct.h"
#include "rosidl_runtime_c/type_description/type_source__struct.h"
#include "rosidl_runtime_c/type_hash.h"
#include "rosidl_runtime_c/visibility_control.h"
#include "two_dof_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "two_dof_interfaces/srv/detail/coordinate_to_joint__struct.h"

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_two_dof_interfaces
const rosidl_type_hash_t *
two_dof_interfaces__srv__CoordinateToJoint__get_type_hash(
  const rosidl_service_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_two_dof_interfaces
const rosidl_runtime_c__type_description__TypeDescription *
two_dof_interfaces__srv__CoordinateToJoint__get_type_description(
  const rosidl_service_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_two_dof_interfaces
const rosidl_runtime_c__type_description__TypeSource *
two_dof_interfaces__srv__CoordinateToJoint__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_two_dof_interfaces
const rosidl_runtime_c__type_description__TypeSource__Sequence *
two_dof_interfaces__srv__CoordinateToJoint__get_type_description_sources(
  const rosidl_service_type_support_t * type_support);

/// Initialize srv/CoordinateToJoint message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * two_dof_interfaces__srv__CoordinateToJoint_Request
 * )) before or use
 * two_dof_interfaces__srv__CoordinateToJoint_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_two_dof_interfaces
bool
two_dof_interfaces__srv__CoordinateToJoint_Request__init(two_dof_interfaces__srv__CoordinateToJoint_Request * msg);

/// Finalize srv/CoordinateToJoint message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_two_dof_interfaces
void
two_dof_interfaces__srv__CoordinateToJoint_Request__fini(two_dof_interfaces__srv__CoordinateToJoint_Request * msg);

/// Create srv/CoordinateToJoint message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * two_dof_interfaces__srv__CoordinateToJoint_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_two_dof_interfaces
two_dof_interfaces__srv__CoordinateToJoint_Request *
two_dof_interfaces__srv__CoordinateToJoint_Request__create(void);

/// Destroy srv/CoordinateToJoint message.
/**
 * It calls
 * two_dof_interfaces__srv__CoordinateToJoint_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_two_dof_interfaces
void
two_dof_interfaces__srv__CoordinateToJoint_Request__destroy(two_dof_interfaces__srv__CoordinateToJoint_Request * msg);

/// Check for srv/CoordinateToJoint message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_two_dof_interfaces
bool
two_dof_interfaces__srv__CoordinateToJoint_Request__are_equal(const two_dof_interfaces__srv__CoordinateToJoint_Request * lhs, const two_dof_interfaces__srv__CoordinateToJoint_Request * rhs);

/// Copy a srv/CoordinateToJoint message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_two_dof_interfaces
bool
two_dof_interfaces__srv__CoordinateToJoint_Request__copy(
  const two_dof_interfaces__srv__CoordinateToJoint_Request * input,
  two_dof_interfaces__srv__CoordinateToJoint_Request * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_two_dof_interfaces
const rosidl_type_hash_t *
two_dof_interfaces__srv__CoordinateToJoint_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_two_dof_interfaces
const rosidl_runtime_c__type_description__TypeDescription *
two_dof_interfaces__srv__CoordinateToJoint_Request__get_type_description(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_two_dof_interfaces
const rosidl_runtime_c__type_description__TypeSource *
two_dof_interfaces__srv__CoordinateToJoint_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_two_dof_interfaces
const rosidl_runtime_c__type_description__TypeSource__Sequence *
two_dof_interfaces__srv__CoordinateToJoint_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support);

/// Initialize array of srv/CoordinateToJoint messages.
/**
 * It allocates the memory for the number of elements and calls
 * two_dof_interfaces__srv__CoordinateToJoint_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_two_dof_interfaces
bool
two_dof_interfaces__srv__CoordinateToJoint_Request__Sequence__init(two_dof_interfaces__srv__CoordinateToJoint_Request__Sequence * array, size_t size);

/// Finalize array of srv/CoordinateToJoint messages.
/**
 * It calls
 * two_dof_interfaces__srv__CoordinateToJoint_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_two_dof_interfaces
void
two_dof_interfaces__srv__CoordinateToJoint_Request__Sequence__fini(two_dof_interfaces__srv__CoordinateToJoint_Request__Sequence * array);

/// Create array of srv/CoordinateToJoint messages.
/**
 * It allocates the memory for the array and calls
 * two_dof_interfaces__srv__CoordinateToJoint_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_two_dof_interfaces
two_dof_interfaces__srv__CoordinateToJoint_Request__Sequence *
two_dof_interfaces__srv__CoordinateToJoint_Request__Sequence__create(size_t size);

/// Destroy array of srv/CoordinateToJoint messages.
/**
 * It calls
 * two_dof_interfaces__srv__CoordinateToJoint_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_two_dof_interfaces
void
two_dof_interfaces__srv__CoordinateToJoint_Request__Sequence__destroy(two_dof_interfaces__srv__CoordinateToJoint_Request__Sequence * array);

/// Check for srv/CoordinateToJoint message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_two_dof_interfaces
bool
two_dof_interfaces__srv__CoordinateToJoint_Request__Sequence__are_equal(const two_dof_interfaces__srv__CoordinateToJoint_Request__Sequence * lhs, const two_dof_interfaces__srv__CoordinateToJoint_Request__Sequence * rhs);

/// Copy an array of srv/CoordinateToJoint messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_two_dof_interfaces
bool
two_dof_interfaces__srv__CoordinateToJoint_Request__Sequence__copy(
  const two_dof_interfaces__srv__CoordinateToJoint_Request__Sequence * input,
  two_dof_interfaces__srv__CoordinateToJoint_Request__Sequence * output);

/// Initialize srv/CoordinateToJoint message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * two_dof_interfaces__srv__CoordinateToJoint_Response
 * )) before or use
 * two_dof_interfaces__srv__CoordinateToJoint_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_two_dof_interfaces
bool
two_dof_interfaces__srv__CoordinateToJoint_Response__init(two_dof_interfaces__srv__CoordinateToJoint_Response * msg);

/// Finalize srv/CoordinateToJoint message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_two_dof_interfaces
void
two_dof_interfaces__srv__CoordinateToJoint_Response__fini(two_dof_interfaces__srv__CoordinateToJoint_Response * msg);

/// Create srv/CoordinateToJoint message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * two_dof_interfaces__srv__CoordinateToJoint_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_two_dof_interfaces
two_dof_interfaces__srv__CoordinateToJoint_Response *
two_dof_interfaces__srv__CoordinateToJoint_Response__create(void);

/// Destroy srv/CoordinateToJoint message.
/**
 * It calls
 * two_dof_interfaces__srv__CoordinateToJoint_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_two_dof_interfaces
void
two_dof_interfaces__srv__CoordinateToJoint_Response__destroy(two_dof_interfaces__srv__CoordinateToJoint_Response * msg);

/// Check for srv/CoordinateToJoint message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_two_dof_interfaces
bool
two_dof_interfaces__srv__CoordinateToJoint_Response__are_equal(const two_dof_interfaces__srv__CoordinateToJoint_Response * lhs, const two_dof_interfaces__srv__CoordinateToJoint_Response * rhs);

/// Copy a srv/CoordinateToJoint message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_two_dof_interfaces
bool
two_dof_interfaces__srv__CoordinateToJoint_Response__copy(
  const two_dof_interfaces__srv__CoordinateToJoint_Response * input,
  two_dof_interfaces__srv__CoordinateToJoint_Response * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_two_dof_interfaces
const rosidl_type_hash_t *
two_dof_interfaces__srv__CoordinateToJoint_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_two_dof_interfaces
const rosidl_runtime_c__type_description__TypeDescription *
two_dof_interfaces__srv__CoordinateToJoint_Response__get_type_description(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_two_dof_interfaces
const rosidl_runtime_c__type_description__TypeSource *
two_dof_interfaces__srv__CoordinateToJoint_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_two_dof_interfaces
const rosidl_runtime_c__type_description__TypeSource__Sequence *
two_dof_interfaces__srv__CoordinateToJoint_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support);

/// Initialize array of srv/CoordinateToJoint messages.
/**
 * It allocates the memory for the number of elements and calls
 * two_dof_interfaces__srv__CoordinateToJoint_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_two_dof_interfaces
bool
two_dof_interfaces__srv__CoordinateToJoint_Response__Sequence__init(two_dof_interfaces__srv__CoordinateToJoint_Response__Sequence * array, size_t size);

/// Finalize array of srv/CoordinateToJoint messages.
/**
 * It calls
 * two_dof_interfaces__srv__CoordinateToJoint_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_two_dof_interfaces
void
two_dof_interfaces__srv__CoordinateToJoint_Response__Sequence__fini(two_dof_interfaces__srv__CoordinateToJoint_Response__Sequence * array);

/// Create array of srv/CoordinateToJoint messages.
/**
 * It allocates the memory for the array and calls
 * two_dof_interfaces__srv__CoordinateToJoint_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_two_dof_interfaces
two_dof_interfaces__srv__CoordinateToJoint_Response__Sequence *
two_dof_interfaces__srv__CoordinateToJoint_Response__Sequence__create(size_t size);

/// Destroy array of srv/CoordinateToJoint messages.
/**
 * It calls
 * two_dof_interfaces__srv__CoordinateToJoint_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_two_dof_interfaces
void
two_dof_interfaces__srv__CoordinateToJoint_Response__Sequence__destroy(two_dof_interfaces__srv__CoordinateToJoint_Response__Sequence * array);

/// Check for srv/CoordinateToJoint message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_two_dof_interfaces
bool
two_dof_interfaces__srv__CoordinateToJoint_Response__Sequence__are_equal(const two_dof_interfaces__srv__CoordinateToJoint_Response__Sequence * lhs, const two_dof_interfaces__srv__CoordinateToJoint_Response__Sequence * rhs);

/// Copy an array of srv/CoordinateToJoint messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_two_dof_interfaces
bool
two_dof_interfaces__srv__CoordinateToJoint_Response__Sequence__copy(
  const two_dof_interfaces__srv__CoordinateToJoint_Response__Sequence * input,
  two_dof_interfaces__srv__CoordinateToJoint_Response__Sequence * output);

/// Initialize srv/CoordinateToJoint message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * two_dof_interfaces__srv__CoordinateToJoint_Event
 * )) before or use
 * two_dof_interfaces__srv__CoordinateToJoint_Event__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_two_dof_interfaces
bool
two_dof_interfaces__srv__CoordinateToJoint_Event__init(two_dof_interfaces__srv__CoordinateToJoint_Event * msg);

/// Finalize srv/CoordinateToJoint message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_two_dof_interfaces
void
two_dof_interfaces__srv__CoordinateToJoint_Event__fini(two_dof_interfaces__srv__CoordinateToJoint_Event * msg);

/// Create srv/CoordinateToJoint message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * two_dof_interfaces__srv__CoordinateToJoint_Event__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_two_dof_interfaces
two_dof_interfaces__srv__CoordinateToJoint_Event *
two_dof_interfaces__srv__CoordinateToJoint_Event__create(void);

/// Destroy srv/CoordinateToJoint message.
/**
 * It calls
 * two_dof_interfaces__srv__CoordinateToJoint_Event__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_two_dof_interfaces
void
two_dof_interfaces__srv__CoordinateToJoint_Event__destroy(two_dof_interfaces__srv__CoordinateToJoint_Event * msg);

/// Check for srv/CoordinateToJoint message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_two_dof_interfaces
bool
two_dof_interfaces__srv__CoordinateToJoint_Event__are_equal(const two_dof_interfaces__srv__CoordinateToJoint_Event * lhs, const two_dof_interfaces__srv__CoordinateToJoint_Event * rhs);

/// Copy a srv/CoordinateToJoint message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_two_dof_interfaces
bool
two_dof_interfaces__srv__CoordinateToJoint_Event__copy(
  const two_dof_interfaces__srv__CoordinateToJoint_Event * input,
  two_dof_interfaces__srv__CoordinateToJoint_Event * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_two_dof_interfaces
const rosidl_type_hash_t *
two_dof_interfaces__srv__CoordinateToJoint_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_two_dof_interfaces
const rosidl_runtime_c__type_description__TypeDescription *
two_dof_interfaces__srv__CoordinateToJoint_Event__get_type_description(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_two_dof_interfaces
const rosidl_runtime_c__type_description__TypeSource *
two_dof_interfaces__srv__CoordinateToJoint_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_two_dof_interfaces
const rosidl_runtime_c__type_description__TypeSource__Sequence *
two_dof_interfaces__srv__CoordinateToJoint_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support);

/// Initialize array of srv/CoordinateToJoint messages.
/**
 * It allocates the memory for the number of elements and calls
 * two_dof_interfaces__srv__CoordinateToJoint_Event__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_two_dof_interfaces
bool
two_dof_interfaces__srv__CoordinateToJoint_Event__Sequence__init(two_dof_interfaces__srv__CoordinateToJoint_Event__Sequence * array, size_t size);

/// Finalize array of srv/CoordinateToJoint messages.
/**
 * It calls
 * two_dof_interfaces__srv__CoordinateToJoint_Event__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_two_dof_interfaces
void
two_dof_interfaces__srv__CoordinateToJoint_Event__Sequence__fini(two_dof_interfaces__srv__CoordinateToJoint_Event__Sequence * array);

/// Create array of srv/CoordinateToJoint messages.
/**
 * It allocates the memory for the array and calls
 * two_dof_interfaces__srv__CoordinateToJoint_Event__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_two_dof_interfaces
two_dof_interfaces__srv__CoordinateToJoint_Event__Sequence *
two_dof_interfaces__srv__CoordinateToJoint_Event__Sequence__create(size_t size);

/// Destroy array of srv/CoordinateToJoint messages.
/**
 * It calls
 * two_dof_interfaces__srv__CoordinateToJoint_Event__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_two_dof_interfaces
void
two_dof_interfaces__srv__CoordinateToJoint_Event__Sequence__destroy(two_dof_interfaces__srv__CoordinateToJoint_Event__Sequence * array);

/// Check for srv/CoordinateToJoint message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_two_dof_interfaces
bool
two_dof_interfaces__srv__CoordinateToJoint_Event__Sequence__are_equal(const two_dof_interfaces__srv__CoordinateToJoint_Event__Sequence * lhs, const two_dof_interfaces__srv__CoordinateToJoint_Event__Sequence * rhs);

/// Copy an array of srv/CoordinateToJoint messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_two_dof_interfaces
bool
two_dof_interfaces__srv__CoordinateToJoint_Event__Sequence__copy(
  const two_dof_interfaces__srv__CoordinateToJoint_Event__Sequence * input,
  two_dof_interfaces__srv__CoordinateToJoint_Event__Sequence * output);
#ifdef __cplusplus
}
#endif

#endif  // TWO_DOF_INTERFACES__SRV__DETAIL__COORDINATE_TO_JOINT__FUNCTIONS_H_
