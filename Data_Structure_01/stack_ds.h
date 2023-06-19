#ifndef _STACK_DS_H
#define _STACK_DS_H

#include "std_types.h"

#define STACK_MAX_SIZE 5
#define STACK_DBEG

typedef struct stack_ds
{
    sint32_t stack_pointer;
    uint32_t data[STACK_MAX_SIZE];

}stack_ds_t;

typedef enum Stack_Status
{
    Stack_Empty,
    Stack_Full,
    Stack_Not_Full
}Stack_status_t;

/**
  * @brief   initialize the stack of pointer
  * @param   my_stack pointer to stack.
  * @retval  Status of initialization process.
  */
return_status_t stack_init(stack_ds_t *My_Stack);

/**
  * @brief   Add new element pushed to stack.
  * @param   my_stack pointer to stack.
  * @param   value to be added to stack.
  * @retval  Status of Stack Push.
  */
return_status_t stack_push(stack_ds_t *My_Stack, uint32_t value);

/**
  * @brief   Get the last element poped from stack.
  * @param   my_stack pointer to stack.
  * @param   Element to be poped from stack.
  * @retval  Status of Stack pop.
  */
return_status_t stack_pop(stack_ds_t *My_Stack, uint32_t *value);

/**
  * @brief   Get the last element pushed to stack.
  * @param   my_stack pointer to stack.
  * @param   Element to be return from stack.
  * @retval  Status of Stack Top
  */
return_status_t stack_Top(stack_ds_t *My_Stack, uint32_t *value);

/**
  * @brief   Get the size of stack -> number of elements.
  * @param   my_stack pointer to stack.
  * @param   Stack size size of stack -> hold the size of stack.
  * @retval  Status of Stack Size.
  */
return_status_t stack_size(stack_ds_t *My_Stack, uint32_t *Stack_size);

/**
  * @brief   Display elements of stack.
  * @param   my_stack pointer to stack.
  * @retval  Status of Stack Display.
  */
return_status_t stack_display(stack_ds_t *My_Stack);

#endif // _STACK_DS_H
