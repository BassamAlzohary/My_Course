
#ifndef _QUEUE_ARRAY_H
#define _QUEUE_ARRAY_H

#include <stdio.h>
#include <stdlib.h>

#include"Platform.h"

typedef struct
{
    void **QueueArray;   // Pointer array of void pointer
    uint32 QueueMaxSize; // Maximum element in Queue
    sint32 ElementCount; // Number of element in Queue
    sint32 QueueFront;   // Index of front element.
    sint32 QueueRear;    // Index of rear element.
}Queue_t;

typedef enum
{
    QUEUE_NOK,
    QUEUE_OK,
    QUEUE_FULL,
    QUEUE_EMPTY,
    QUEUE_NULL_POINTER
}QueueStatus_t;

Queue_t *Create_Queue(uint32 MaxSize, QueueStatus_t *RetStatus);
QueueStatus_t Enqueue_Element(Queue_t *QueueObj, void *ItemPtr);
void *Dequeue_Element(Queue_t *QueueObj, QueueStatus_t *RetStatus);
void *Queue_Front(Queue_t *QueueObj, QueueStatus_t *RetStatus);
void *Queue_Rear(Queue_t *QueueObj, QueueStatus_t *RetStatus);
QueueStatus_t Get_Queue_Count(Queue_t *QueueObj, uint32 *QueueCount);
QueueStatus_t Destroy_Queue(Queue_t *QueueObj);

#endif // _QUEUE_ARRAY_H
