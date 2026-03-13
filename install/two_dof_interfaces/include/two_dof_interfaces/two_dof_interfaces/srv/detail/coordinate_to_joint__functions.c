// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from two_dof_interfaces:srv/CoordinateToJoint.idl
// generated code does not contain a copyright notice
#include "two_dof_interfaces/srv/detail/coordinate_to_joint__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
two_dof_interfaces__srv__CoordinateToJoint_Request__init(two_dof_interfaces__srv__CoordinateToJoint_Request * msg)
{
  if (!msg) {
    return false;
  }
  // x
  // y
  return true;
}

void
two_dof_interfaces__srv__CoordinateToJoint_Request__fini(two_dof_interfaces__srv__CoordinateToJoint_Request * msg)
{
  if (!msg) {
    return;
  }
  // x
  // y
}

bool
two_dof_interfaces__srv__CoordinateToJoint_Request__are_equal(const two_dof_interfaces__srv__CoordinateToJoint_Request * lhs, const two_dof_interfaces__srv__CoordinateToJoint_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // x
  if (lhs->x != rhs->x) {
    return false;
  }
  // y
  if (lhs->y != rhs->y) {
    return false;
  }
  return true;
}

bool
two_dof_interfaces__srv__CoordinateToJoint_Request__copy(
  const two_dof_interfaces__srv__CoordinateToJoint_Request * input,
  two_dof_interfaces__srv__CoordinateToJoint_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  return true;
}

two_dof_interfaces__srv__CoordinateToJoint_Request *
two_dof_interfaces__srv__CoordinateToJoint_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  two_dof_interfaces__srv__CoordinateToJoint_Request * msg = (two_dof_interfaces__srv__CoordinateToJoint_Request *)allocator.allocate(sizeof(two_dof_interfaces__srv__CoordinateToJoint_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(two_dof_interfaces__srv__CoordinateToJoint_Request));
  bool success = two_dof_interfaces__srv__CoordinateToJoint_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
two_dof_interfaces__srv__CoordinateToJoint_Request__destroy(two_dof_interfaces__srv__CoordinateToJoint_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    two_dof_interfaces__srv__CoordinateToJoint_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
two_dof_interfaces__srv__CoordinateToJoint_Request__Sequence__init(two_dof_interfaces__srv__CoordinateToJoint_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  two_dof_interfaces__srv__CoordinateToJoint_Request * data = NULL;

  if (size) {
    data = (two_dof_interfaces__srv__CoordinateToJoint_Request *)allocator.zero_allocate(size, sizeof(two_dof_interfaces__srv__CoordinateToJoint_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = two_dof_interfaces__srv__CoordinateToJoint_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        two_dof_interfaces__srv__CoordinateToJoint_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
two_dof_interfaces__srv__CoordinateToJoint_Request__Sequence__fini(two_dof_interfaces__srv__CoordinateToJoint_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      two_dof_interfaces__srv__CoordinateToJoint_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

two_dof_interfaces__srv__CoordinateToJoint_Request__Sequence *
two_dof_interfaces__srv__CoordinateToJoint_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  two_dof_interfaces__srv__CoordinateToJoint_Request__Sequence * array = (two_dof_interfaces__srv__CoordinateToJoint_Request__Sequence *)allocator.allocate(sizeof(two_dof_interfaces__srv__CoordinateToJoint_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = two_dof_interfaces__srv__CoordinateToJoint_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
two_dof_interfaces__srv__CoordinateToJoint_Request__Sequence__destroy(two_dof_interfaces__srv__CoordinateToJoint_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    two_dof_interfaces__srv__CoordinateToJoint_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
two_dof_interfaces__srv__CoordinateToJoint_Request__Sequence__are_equal(const two_dof_interfaces__srv__CoordinateToJoint_Request__Sequence * lhs, const two_dof_interfaces__srv__CoordinateToJoint_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!two_dof_interfaces__srv__CoordinateToJoint_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
two_dof_interfaces__srv__CoordinateToJoint_Request__Sequence__copy(
  const two_dof_interfaces__srv__CoordinateToJoint_Request__Sequence * input,
  two_dof_interfaces__srv__CoordinateToJoint_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(two_dof_interfaces__srv__CoordinateToJoint_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    two_dof_interfaces__srv__CoordinateToJoint_Request * data =
      (two_dof_interfaces__srv__CoordinateToJoint_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!two_dof_interfaces__srv__CoordinateToJoint_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          two_dof_interfaces__srv__CoordinateToJoint_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!two_dof_interfaces__srv__CoordinateToJoint_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `message`
#include "rosidl_runtime_c/string_functions.h"

bool
two_dof_interfaces__srv__CoordinateToJoint_Response__init(two_dof_interfaces__srv__CoordinateToJoint_Response * msg)
{
  if (!msg) {
    return false;
  }
  // theta1
  // theta2
  // success
  // message
  if (!rosidl_runtime_c__String__init(&msg->message)) {
    two_dof_interfaces__srv__CoordinateToJoint_Response__fini(msg);
    return false;
  }
  return true;
}

void
two_dof_interfaces__srv__CoordinateToJoint_Response__fini(two_dof_interfaces__srv__CoordinateToJoint_Response * msg)
{
  if (!msg) {
    return;
  }
  // theta1
  // theta2
  // success
  // message
  rosidl_runtime_c__String__fini(&msg->message);
}

bool
two_dof_interfaces__srv__CoordinateToJoint_Response__are_equal(const two_dof_interfaces__srv__CoordinateToJoint_Response * lhs, const two_dof_interfaces__srv__CoordinateToJoint_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // theta1
  if (lhs->theta1 != rhs->theta1) {
    return false;
  }
  // theta2
  if (lhs->theta2 != rhs->theta2) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->message), &(rhs->message)))
  {
    return false;
  }
  return true;
}

bool
two_dof_interfaces__srv__CoordinateToJoint_Response__copy(
  const two_dof_interfaces__srv__CoordinateToJoint_Response * input,
  two_dof_interfaces__srv__CoordinateToJoint_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // theta1
  output->theta1 = input->theta1;
  // theta2
  output->theta2 = input->theta2;
  // success
  output->success = input->success;
  // message
  if (!rosidl_runtime_c__String__copy(
      &(input->message), &(output->message)))
  {
    return false;
  }
  return true;
}

two_dof_interfaces__srv__CoordinateToJoint_Response *
two_dof_interfaces__srv__CoordinateToJoint_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  two_dof_interfaces__srv__CoordinateToJoint_Response * msg = (two_dof_interfaces__srv__CoordinateToJoint_Response *)allocator.allocate(sizeof(two_dof_interfaces__srv__CoordinateToJoint_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(two_dof_interfaces__srv__CoordinateToJoint_Response));
  bool success = two_dof_interfaces__srv__CoordinateToJoint_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
two_dof_interfaces__srv__CoordinateToJoint_Response__destroy(two_dof_interfaces__srv__CoordinateToJoint_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    two_dof_interfaces__srv__CoordinateToJoint_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
two_dof_interfaces__srv__CoordinateToJoint_Response__Sequence__init(two_dof_interfaces__srv__CoordinateToJoint_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  two_dof_interfaces__srv__CoordinateToJoint_Response * data = NULL;

  if (size) {
    data = (two_dof_interfaces__srv__CoordinateToJoint_Response *)allocator.zero_allocate(size, sizeof(two_dof_interfaces__srv__CoordinateToJoint_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = two_dof_interfaces__srv__CoordinateToJoint_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        two_dof_interfaces__srv__CoordinateToJoint_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
two_dof_interfaces__srv__CoordinateToJoint_Response__Sequence__fini(two_dof_interfaces__srv__CoordinateToJoint_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      two_dof_interfaces__srv__CoordinateToJoint_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

two_dof_interfaces__srv__CoordinateToJoint_Response__Sequence *
two_dof_interfaces__srv__CoordinateToJoint_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  two_dof_interfaces__srv__CoordinateToJoint_Response__Sequence * array = (two_dof_interfaces__srv__CoordinateToJoint_Response__Sequence *)allocator.allocate(sizeof(two_dof_interfaces__srv__CoordinateToJoint_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = two_dof_interfaces__srv__CoordinateToJoint_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
two_dof_interfaces__srv__CoordinateToJoint_Response__Sequence__destroy(two_dof_interfaces__srv__CoordinateToJoint_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    two_dof_interfaces__srv__CoordinateToJoint_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
two_dof_interfaces__srv__CoordinateToJoint_Response__Sequence__are_equal(const two_dof_interfaces__srv__CoordinateToJoint_Response__Sequence * lhs, const two_dof_interfaces__srv__CoordinateToJoint_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!two_dof_interfaces__srv__CoordinateToJoint_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
two_dof_interfaces__srv__CoordinateToJoint_Response__Sequence__copy(
  const two_dof_interfaces__srv__CoordinateToJoint_Response__Sequence * input,
  two_dof_interfaces__srv__CoordinateToJoint_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(two_dof_interfaces__srv__CoordinateToJoint_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    two_dof_interfaces__srv__CoordinateToJoint_Response * data =
      (two_dof_interfaces__srv__CoordinateToJoint_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!two_dof_interfaces__srv__CoordinateToJoint_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          two_dof_interfaces__srv__CoordinateToJoint_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!two_dof_interfaces__srv__CoordinateToJoint_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `info`
#include "service_msgs/msg/detail/service_event_info__functions.h"
// Member `request`
// Member `response`
// already included above
// #include "two_dof_interfaces/srv/detail/coordinate_to_joint__functions.h"

bool
two_dof_interfaces__srv__CoordinateToJoint_Event__init(two_dof_interfaces__srv__CoordinateToJoint_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    two_dof_interfaces__srv__CoordinateToJoint_Event__fini(msg);
    return false;
  }
  // request
  if (!two_dof_interfaces__srv__CoordinateToJoint_Request__Sequence__init(&msg->request, 0)) {
    two_dof_interfaces__srv__CoordinateToJoint_Event__fini(msg);
    return false;
  }
  // response
  if (!two_dof_interfaces__srv__CoordinateToJoint_Response__Sequence__init(&msg->response, 0)) {
    two_dof_interfaces__srv__CoordinateToJoint_Event__fini(msg);
    return false;
  }
  return true;
}

void
two_dof_interfaces__srv__CoordinateToJoint_Event__fini(two_dof_interfaces__srv__CoordinateToJoint_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  two_dof_interfaces__srv__CoordinateToJoint_Request__Sequence__fini(&msg->request);
  // response
  two_dof_interfaces__srv__CoordinateToJoint_Response__Sequence__fini(&msg->response);
}

bool
two_dof_interfaces__srv__CoordinateToJoint_Event__are_equal(const two_dof_interfaces__srv__CoordinateToJoint_Event * lhs, const two_dof_interfaces__srv__CoordinateToJoint_Event * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__are_equal(
      &(lhs->info), &(rhs->info)))
  {
    return false;
  }
  // request
  if (!two_dof_interfaces__srv__CoordinateToJoint_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!two_dof_interfaces__srv__CoordinateToJoint_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
two_dof_interfaces__srv__CoordinateToJoint_Event__copy(
  const two_dof_interfaces__srv__CoordinateToJoint_Event * input,
  two_dof_interfaces__srv__CoordinateToJoint_Event * output)
{
  if (!input || !output) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__copy(
      &(input->info), &(output->info)))
  {
    return false;
  }
  // request
  if (!two_dof_interfaces__srv__CoordinateToJoint_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!two_dof_interfaces__srv__CoordinateToJoint_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

two_dof_interfaces__srv__CoordinateToJoint_Event *
two_dof_interfaces__srv__CoordinateToJoint_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  two_dof_interfaces__srv__CoordinateToJoint_Event * msg = (two_dof_interfaces__srv__CoordinateToJoint_Event *)allocator.allocate(sizeof(two_dof_interfaces__srv__CoordinateToJoint_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(two_dof_interfaces__srv__CoordinateToJoint_Event));
  bool success = two_dof_interfaces__srv__CoordinateToJoint_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
two_dof_interfaces__srv__CoordinateToJoint_Event__destroy(two_dof_interfaces__srv__CoordinateToJoint_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    two_dof_interfaces__srv__CoordinateToJoint_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
two_dof_interfaces__srv__CoordinateToJoint_Event__Sequence__init(two_dof_interfaces__srv__CoordinateToJoint_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  two_dof_interfaces__srv__CoordinateToJoint_Event * data = NULL;

  if (size) {
    data = (two_dof_interfaces__srv__CoordinateToJoint_Event *)allocator.zero_allocate(size, sizeof(two_dof_interfaces__srv__CoordinateToJoint_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = two_dof_interfaces__srv__CoordinateToJoint_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        two_dof_interfaces__srv__CoordinateToJoint_Event__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
two_dof_interfaces__srv__CoordinateToJoint_Event__Sequence__fini(two_dof_interfaces__srv__CoordinateToJoint_Event__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      two_dof_interfaces__srv__CoordinateToJoint_Event__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

two_dof_interfaces__srv__CoordinateToJoint_Event__Sequence *
two_dof_interfaces__srv__CoordinateToJoint_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  two_dof_interfaces__srv__CoordinateToJoint_Event__Sequence * array = (two_dof_interfaces__srv__CoordinateToJoint_Event__Sequence *)allocator.allocate(sizeof(two_dof_interfaces__srv__CoordinateToJoint_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = two_dof_interfaces__srv__CoordinateToJoint_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
two_dof_interfaces__srv__CoordinateToJoint_Event__Sequence__destroy(two_dof_interfaces__srv__CoordinateToJoint_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    two_dof_interfaces__srv__CoordinateToJoint_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
two_dof_interfaces__srv__CoordinateToJoint_Event__Sequence__are_equal(const two_dof_interfaces__srv__CoordinateToJoint_Event__Sequence * lhs, const two_dof_interfaces__srv__CoordinateToJoint_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!two_dof_interfaces__srv__CoordinateToJoint_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
two_dof_interfaces__srv__CoordinateToJoint_Event__Sequence__copy(
  const two_dof_interfaces__srv__CoordinateToJoint_Event__Sequence * input,
  two_dof_interfaces__srv__CoordinateToJoint_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(two_dof_interfaces__srv__CoordinateToJoint_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    two_dof_interfaces__srv__CoordinateToJoint_Event * data =
      (two_dof_interfaces__srv__CoordinateToJoint_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!two_dof_interfaces__srv__CoordinateToJoint_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          two_dof_interfaces__srv__CoordinateToJoint_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!two_dof_interfaces__srv__CoordinateToJoint_Event__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
