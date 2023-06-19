#include <stdio.h>
#include <stdlib.h>

#include "stack_ds.h"

stack_ds_t Stack_1;
stack_ds_t Stack_2;

uint32_t stack_pop_value = ZERO_INT;

int main()
{

    return_status_t ret = R_NOK;
    ret = stack_init(&Stack_1);
    if(R_NOK == ret)
    {
        printf("Stack Failed to initialized !!\n");
    }
    else
    {
        ret = stack_push(&Stack_1, 11);
        ret = stack_push(&Stack_1, 22);
        ret = stack_push(&Stack_1, 33);
        ret = stack_push(&Stack_1, 44);
        ret = stack_push(&Stack_1, 55);
        ret = stack_push(&Stack_1, 66);//Failed
        ret = stack_push(&Stack_1, 77);//Failed
        ret = stack_pop(&Stack_1, &stack_pop_value);
        ret = stack_pop(&Stack_1, &stack_pop_value);
        ret = stack_pop(&Stack_1, &stack_pop_value);
        ret = stack_pop(&Stack_1, &stack_pop_value);
        ret = stack_pop(&Stack_1, &stack_pop_value);
        ret = stack_pop(&Stack_1, &stack_pop_value);
        ret = stack_pop(&Stack_1, &stack_pop_value);
        ret = stack_pop(&Stack_1, &stack_pop_value);


        printf("===========================\n");
        uint32_t stack_top = ZERO_INT;
        ret = stack_push(&Stack_1, 99);
        ret = stack_push(&Stack_1, 11);
        ret = stack_push(&Stack_1, 22);
        ret = stack_push(&Stack_1, 33);
        ret = stack_push(&Stack_1, 44);
        ret = stack_push(&Stack_1, 55);
        ret = stack_display(&Stack_1);
    }
    return 0;
}
