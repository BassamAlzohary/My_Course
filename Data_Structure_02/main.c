#include <stdio.h>
#include <stdlib.h>

#include "Stack_DM_Arr.h"

uint32 Stack1_Size = 0, Stack1_Count = 0;
Stack_t *Stack1 = NULL;
void *Stack1_return = NULL;

uint32 Var1 = 0x11;
float32 Var2 = 2.14;
unsigned char Var3 = 'a';


int main()
{
    printf("Hello\n");
    StackStatus_t Stack1_States = STACK_NOK;
    printf("Enter Number of Stack 1 Element: ");
    scanf("%i",&Stack1_Size);
    Stack1 = Stack_Create(Stack1_Size, &Stack1_States);
    if(Stack1)
    {
        printf("Stack 1 is created\n");
    }

    Stack1_States =  Stack_Push(Stack1, &Var1); printf("Stack1_States = %i\n", Stack1_States);
    Stack1_States =  Stack_Push(Stack1, &Var2); printf("Stack1_States = %i\n", Stack1_States);
    Stack1_States =  Stack_Push(Stack1, &Var3); printf("Stack1_States = %i\n", Stack1_States);

    Stack1_States = Stack_Count(Stack1, &Stack1_Count); printf("Stack1_States = %i\n", Stack1_States);
    printf("Stack_Count = %i\n", Stack1_Count);

    Stack1_return = Stack_Top(Stack1, &Stack1_States); printf("Stack1_States = %i\n", Stack1_States);
    printf("Stack_Top = %c\n", *((unsigned char *)Stack1_return));

    printf("--------------------------\n");
    Stack1_return = Stack_Pop(Stack1, &Stack1_States); printf("Stack1_States = %i\n", Stack1_States);
    printf("Stack_Pop = %c\n", *((unsigned char *)Stack1_return));

    Stack1_return = Stack_Pop(Stack1, &Stack1_States); printf("Stack1_States = %i\n", Stack1_States);
    printf("Stack_Pop = %f\n", *((float32 *)Stack1_return));

    Stack1_return = Stack_Pop(Stack1, &Stack1_States); printf("Stack1_States = %i\n", Stack1_States);
    printf("Stack_Pop = %x\n", *((uint32 *)Stack1_return));

    Stack1_return = Stack_Pop(Stack1, &Stack1_States); printf("Stack1_States = %i\n", Stack1_States);
    printf("Stack_Pop = %i\n", *((uint32 *)Stack1_return));

    Stack1_return = Stack_Pop(Stack1, &Stack1_States); printf("Stack1_States = %i\n", Stack1_States);
    printf("Stack_Pop = %i\n", *((uint32 *)Stack1_return));

    Stack1 = Stack_Destroy(Stack1, &Stack1_States);
    if(!Stack1)
    {
        printf("Stack 1 is destroy\n");
    }
    return 0;
}
