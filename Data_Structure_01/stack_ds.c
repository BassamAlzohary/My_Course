
#include "stack_ds.h"
/*This is a helper Function should be static as the user
Can not use it.
*/
/**
  * @brief   check stack is Full
  * @param   my_stack pointer to stack.
  * @retval  Status of Stack.
  */
static Stack_status_t stack_Full(stack_ds_t *My_Stack)
{
    if(My_Stack->stack_pointer == (STACK_MAX_SIZE - 1))
    {
        return Stack_Full;
    }
    else
    {
        return Stack_Not_Full;
    }
}

/*This is a helper Function should be static as the user
Can not use it.
*/
/**
  * @brief   check stack is Empty
  * @param   my_stack pointer to stack.
  * @retval  Status of Stack.
  */
static Stack_status_t stack_Empty(stack_ds_t *My_Stack)
{
    if(My_Stack->stack_pointer == -1)
    {
        return Stack_Empty;
    }
    else
    {
        return Stack_Not_Full;
    }
}

/**
  * @brief   initialize the stack of pointer
  * @param   my_stack pointer to stack.
  * @retval  Status of initialization process.
  */
return_status_t stack_init(stack_ds_t *My_Stack)
{
    return_status_t ret = R_NOK;
    if(NULL == My_Stack)
    {
        ret = R_NOK;
    }
    else
    {
        My_Stack->stack_pointer = -1;// stack is empty.
        ret = R_OK;
    }
    return ret;
}

/**
  * @brief   Add new element pushed to stack.
  * @param   my_stack pointer to stack.
  * @param   value to be added to stack.
  * @retval  Status of Stack Push.
  */
return_status_t stack_push(stack_ds_t *My_Stack, uint32_t value)
{
    return_status_t ret = R_NOK;
    if((NULL == My_Stack) || (Stack_Full == stack_Full(My_Stack)))
    {
        #ifdef STACK_DBEG // this is debugging mode
        printf("Error !! Stack Is Full, Can not push (%i) !!\n", value);
        #endif // STACK_DBEG
        ret = R_NOK;
    }
    else
    {
        My_Stack->stack_pointer++;
        My_Stack->data[My_Stack->stack_pointer] = value; // we Can not access direct we could access through pointer.
        #ifdef STACK_DBEG // this is debugging mode
        printf("Value (%i) pushed to stack. \n", value);
        #endif // STACK_DBEG
        ret = R_OK;
    }

    return ret;
}

/**
  * @brief   Get the last element poped from stack.
  * @param   my_stack pointer to stack.
  * @param   Element to be poped from stack.
  * @retval  Status of Stack pop.
  */
return_status_t stack_pop(stack_ds_t *My_Stack, uint32_t *value)
{
    return_status_t ret = R_NOK;
    if((NULL == My_Stack) || (NULL == value) || (Stack_Empty == stack_Empty(My_Stack)))
    {
        #ifdef STACK_DBEG // this is debugging mode
        printf("Error !! Stack Is Empty, Can not PoP Any Value !!\n");
        #endif // STACK_DBEG
        ret = R_NOK;
    }
    else
    {
        *value = My_Stack->data[My_Stack->stack_pointer];
        My_Stack->stack_pointer--;
        #ifdef STACK_DBEG // this is debugging mode
        printf("Value (%i) Poped to stack. \n", *value);
        #endif // STACK_DBEG
        ret = R_OK;
    }
    return ret;
}

/**
  * @brief   Get the last element pushed to stack.
  * @param   my_stack pointer to stack.
  * @param   Element to be return from stack.
  * @retval  Status of Stack Top
  */
return_status_t stack_Top(stack_ds_t *My_Stack, uint32_t *value)
{
    return_status_t ret = R_NOK;
    if((NULL == My_Stack) || (NULL == value) || (Stack_Empty == stack_Empty(My_Stack)))
    {
        #ifdef STACK_DBEG // this is debugging mode
        printf("The stack is Empty. \n");
        #endif // STACK_DBEG
        ret = R_NOK;
    }
    else
    {
        *value = My_Stack->data[My_Stack->stack_pointer];
        #ifdef STACK_DBEG // this is debugging mode
        printf("Stack Top Value (%i). \n", *value);
        #endif // STACK_DBEG
        ret = R_OK;
    }
    return ret;
}

/**
  * @brief   Get the size of stack -> number of elements.
  * @param   my_stack pointer to stack.
  * @param   Stack size size of stack -> hold the size of stack.
  * @retval  Status of Stack Size.
  */
return_status_t stack_size(stack_ds_t *My_Stack, uint32_t *Stack_size)
{
    return_status_t ret = R_NOK;
    if((NULL == My_Stack) || (NULL == Stack_size))
    {
        ret = R_NOK;
    }
    else
    {
        *Stack_size = My_Stack->stack_pointer + 1;
        ret = R_OK;
    }
    return ret;
}

/**
  * @brief   Display elements of stack.
  * @param   my_stack pointer to stack.
  * @retval  Status of Stack Display.
  */
return_status_t stack_display(stack_ds_t *My_Stack)
{
    return_status_t ret = R_NOK;
    sint32_t Local_Counter;
    if(NULL == My_Stack)
    {
        ret = R_NOK;
    }
    else
    {
        for(Local_Counter = My_Stack->stack_pointer; Local_Counter >= ZERO; Local_Counter--)
        {
            printf("%i\t",My_Stack->data[Local_Counter]);
        }
        printf("\n");
        ret = R_OK;
    }
    return ret;
}
