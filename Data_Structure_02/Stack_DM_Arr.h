
#ifndef STACK_ARRAY_DS_H
#define STACK_ARRAY_DS_H

#include<stdlib.h>

#include "Platform.h"

typedef struct
{
    void **StackArray;   // Points to the array allocated in heap.
    sint8 ElementCount;  // Has the actual number of elements in the stack.
    uint32 StackMaxSize; // Has the Maximum number of elements in the stack.
    sint32 StackTop;     // Has the index of the top element in the stack.
}Stack_t;

typedef enum
{
    STACK_NOK,          // Stack operation not performed successfully.
    STACK_OK,           // Stack operation performed successfully.
    STACK_FULL,         // Stack is full.
    STACK_EMPTY,        // Stack is empty.
    STACK_NULL_POINTER  // Null pointer Passed to stack operation.
}StackStatus_t;

/**
  * @brief This algorithm creates an empty stack by allocating the heap
  *        structure and the array from dynamic memory.
  * @param (maxsize) Stack maximum number of elements.
  * @param (ret_status) Status returned while performing this operation.
  * @retval Pointer to the allocated stack in the heap.
  */
Stack_t *Stack_Create(uint32 Maxsize, StackStatus_t *ret_status);

/**
  * @brief
  * @param
  * @param
  * @retval
  */
Stack_t* Stack_Destroy(Stack_t* stack_obj, StackStatus_t *ret_status);

/**
  * @brief
  * @param
  * @param
  * @retval
  */
StackStatus_t Stack_Push(Stack_t* stack_obj, void* itemPtr);

/**
  * @brief
  * @param
  * @param
  * @retval
  */
void *Stack_Pop(Stack_t* stack_obj, StackStatus_t *ret_status);

/**
  * @brief
  * @param
  * @param
  * @retval
  */
void *Stack_Top(Stack_t* stack_obj, StackStatus_t *ret_status);

/**
  * @brief
  * @param
  * @param
  * @retval
  */
StackStatus_t Stack_Count(Stack_t* stack_obj, uint32 *stack_count);


#endif // STACK_ARRAY_DS_H
