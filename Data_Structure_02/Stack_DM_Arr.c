
#include "Stack_DM_Arr.h"

//we make helper function: Stack is full and stack is empty functions
static uint8 StackIsEmpty(Stack_t* stack_Obj);
static uint8 StackIsFull(Stack_t* stack_Obj);


Stack_t *Stack_Create(uint32 Maxsize, StackStatus_t *ret_status)
{
    Stack_t *My_Stack = NULL;
    if(NULL == ret_status)
    {
       *ret_status = STACK_NULL_POINTER;
       My_Stack = NULL;
    }
    else
    {
        My_Stack = (Stack_t *)malloc(sizeof(Stack_t));
        if(!My_Stack)
        {
            *ret_status = STACK_NOK;
            My_Stack = NULL;
        }
        else
        {
            My_Stack->StackTop = -1;
            My_Stack->ElementCount = 0;
            My_Stack->StackMaxSize = Maxsize;
            My_Stack->StackArray = (void **)calloc(My_Stack->StackMaxSize, sizeof(void *));
            if(!My_Stack->StackArray)
            {
                free(My_Stack);
                My_Stack = NULL;
                *ret_status = STACK_NOK;
            }
            else
            {
                *ret_status = STACK_OK;
            }

        }
    }
    return My_Stack;
}

Stack_t *Stack_Destroy(Stack_t* stack_obj, StackStatus_t *ret_status)
{
    if((NULL == stack_obj) || (NULL == ret_status))
    {
       *ret_status = STACK_NULL_POINTER;
    }
    else
    {
        free(stack_obj->StackArray);
        free(stack_obj);
        *ret_status = STACK_OK;
    }
    return NULL;
}

StackStatus_t Stack_Push(Stack_t* stack_obj, void* itemPtr)
{
    StackStatus_t stackStates = STACK_NOK;
    if((NULL == stack_obj) || (NULL == itemPtr))
    {
       stackStates = STACK_NULL_POINTER;
    }
    else
    {
        if(StackIsFull(stack_obj))
        {
            stackStates = STACK_FULL;
        }
        else
        {
            (stack_obj->StackTop)++;
            stack_obj->StackArray[stack_obj->StackTop] = itemPtr;
            (stack_obj->ElementCount)++;
            stackStates = STACK_OK;
        }
    }
    return stackStates;
}

void *Stack_Pop(Stack_t* stack_obj, StackStatus_t *ret_status)
{
    void *dataPtrOut = NULL;
    if((NULL == stack_obj) || (NULL == ret_status))
    {
       *ret_status = STACK_NULL_POINTER;
       dataPtrOut = ret_status;
    }
    else
    {
        if(StackIsEmpty(stack_obj))
        {
            *ret_status = STACK_EMPTY;
            dataPtrOut = ret_status;
        }
        else
        {
            dataPtrOut = stack_obj->StackArray[stack_obj->StackTop];
            (stack_obj->StackTop)--;
            (stack_obj->ElementCount)--;
            *ret_status = STACK_OK;
        }
    }
    return dataPtrOut;
}

void *Stack_Top(Stack_t* stack_obj, StackStatus_t *ret_status)
{
    void *dataPtrOut = NULL;
    if((NULL == stack_obj) || (NULL == ret_status))
    {
       *ret_status = STACK_NULL_POINTER;
       dataPtrOut = NULL;
    }
    else
    {
        if(StackIsEmpty(stack_obj))
        {
            *ret_status = STACK_EMPTY;
            dataPtrOut = NULL;
        }
        else
        {
            dataPtrOut = stack_obj->StackArray[stack_obj->StackTop];
            char x = *((char *)dataPtrOut);
            printf("%c hello \n",x);
            *ret_status = STACK_OK;
        }
    }
    return dataPtrOut;
}

StackStatus_t Stack_Count(Stack_t* stack_obj, uint32 *stack_count)
{
    StackStatus_t stackStates = STACK_NOK;
    if((NULL == stack_obj) || (NULL == stack_count))
    {
       stackStates = STACK_NULL_POINTER;
    }
    else
    {
        *stack_count = stack_obj->ElementCount;
        stackStates = STACK_OK;
    }
    return stackStates;
}

static uint8 StackIsEmpty(Stack_t* stack_Obj)
{
    return (stack_Obj->ElementCount == 0);
}

static uint8 StackIsFull(Stack_t* stack_Obj)
{
    return (stack_Obj->ElementCount == stack_Obj->StackMaxSize);
}
