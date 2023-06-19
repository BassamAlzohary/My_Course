#include <stdio.h>
#include <stdlib.h>

#include"QueueArr.h"

uint32 Queue1MaxElem = 0;
Queue_t *Queue1;

uint32 Number1 = 0x11, Number2 = 0x22, Number3 = 0x33,
       Number4 = 0x44, Number5 = 0x55;

int main()
{
    QueueStatus_t ReturnQueueStatus = QUEUE_NOK;

    void *RetPtr = NULL;
    uint32 QueueCount = 0;

    printf("Please Enter your Queue1MaxElem ");
    scanf("%i", &Queue1MaxElem);

    Queue1 = Create_Queue(Queue1MaxElem, &ReturnQueueStatus);
    printf("0x%X \n",Queue1);

    ReturnQueueStatus = Get_Queue_Count(Queue1, &QueueCount);
    printf("ReturnQueueStatus is equal to %i \n",ReturnQueueStatus);
    printf("QueueCount is equal to %i \n",QueueCount);

    ReturnQueueStatus = Enqueue_Element(Queue1, &Number1);
    printf("ReturnQueueStatus is equal to %i \n",ReturnQueueStatus);

    ReturnQueueStatus = Get_Queue_Count(Queue1, &QueueCount);
    printf("ReturnQueueStatus is equal to %i \n",ReturnQueueStatus);
    printf("QueueCount is equal to %i \n",QueueCount);

    ReturnQueueStatus = Enqueue_Element(Queue1, &Number2);
    printf("ReturnQueueStatus is equal to %i \n",ReturnQueueStatus);

    ReturnQueueStatus = Enqueue_Element(Queue1, &Number3);
    printf("ReturnQueueStatus is equal to %i \n",ReturnQueueStatus);

    ReturnQueueStatus = Enqueue_Element(Queue1, &Number4);
    printf("ReturnQueueStatus is equal to %i \n",ReturnQueueStatus);

    ReturnQueueStatus = Enqueue_Element(Queue1, &Number5);
    printf("ReturnQueueStatus is equal to %i \n",ReturnQueueStatus);

    ReturnQueueStatus = Get_Queue_Count(Queue1, &QueueCount);
    printf("ReturnQueueStatus is equal to %i \n",ReturnQueueStatus);
    printf("QueueCount is equal to %i \n",QueueCount);


    printf("-------------------------------------\n");

    RetPtr = Dequeue_Element(Queue1, &ReturnQueueStatus);
    printf("ReturnQueueStatus is equal to %i \n",ReturnQueueStatus);
    printf("Dequeue_Element is equal to 0x%X \n",*(uint32 *)RetPtr);

    RetPtr = Dequeue_Element(Queue1, &ReturnQueueStatus);
    printf("ReturnQueueStatus is equal to %i \n",ReturnQueueStatus);
    printf("Dequeue_Element is equal to 0x%X \n",*(uint32 *)RetPtr);

    RetPtr = Queue_Front(Queue1, &ReturnQueueStatus);
    printf("ReturnQueueStatus is equal to %i \n",ReturnQueueStatus);
    printf("Queue_Front is equal to 0x%X \n",*(uint32 *)RetPtr);

    RetPtr = Queue_Rear(Queue1, &ReturnQueueStatus);
    printf("ReturnQueueStatus is equal to %i \n",ReturnQueueStatus);
    printf("Queue_Rear is equal to 0x%X \n",*(uint32 *)RetPtr);

    RetPtr = Dequeue_Element(Queue1, &ReturnQueueStatus);
    printf("ReturnQueueStatus is equal to %i \n",ReturnQueueStatus);
    printf("Dequeue_Element is equal to 0x%X \n",*(uint32 *)RetPtr);

    RetPtr = Dequeue_Element(Queue1, &ReturnQueueStatus);
    printf("ReturnQueueStatus is equal to %i \n",ReturnQueueStatus);
    printf("Dequeue_Element is equal to 0x%X \n",*(uint32 *)RetPtr);

    RetPtr = Dequeue_Element(Queue1, &ReturnQueueStatus);
    printf("ReturnQueueStatus is equal to %i \n",ReturnQueueStatus);
    printf("Dequeue_Element is equal to 0x%X \n",*(uint32 *)RetPtr);

    RetPtr = Dequeue_Element(Queue1, &ReturnQueueStatus);
    printf("ReturnQueueStatus is equal to %i \n",ReturnQueueStatus);
    // we must validate function of dequeue to not make program to crash.
    if(RetPtr)
    {
        printf("ReturnQueueStatus is equal to 0x%X \n",*(uint32 *)RetPtr);
    }

    ReturnQueueStatus = Destroy_Queue(Queue1);

    return 0;
}
