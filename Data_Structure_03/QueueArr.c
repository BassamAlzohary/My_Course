
#include"QueueArr.h"

// we could make helper function.
static uint8 QueuIsFull(Queue_t *QueueObj)
{
    return (QueueObj->ElementCount == QueueObj->QueueMaxSize);
}

static uint8 QueuIsEmpty(Queue_t *QueueObj)
{
    return (!QueueObj->ElementCount);
}

Queue_t *Create_Queue(uint32 MaxSize, QueueStatus_t *RetStatus)
{
    Queue_t *My_Queue = NULL;
    //Create new Object in in the heap to hold the queue information.
    My_Queue = (Queue_t *)malloc(sizeof(Queue_t));
    if(NULL == My_Queue)
    {
        *RetStatus = QUEUE_NULL_POINTER;
        My_Queue = NULL;
    }
    else
    {
        //Create The array of Void Pointer to hold the addresses of Que Data.
        My_Queue->QueueArray = (void **)calloc(MaxSize, sizeof(void *));
        if(NULL == My_Queue->QueueArray)
        {
            *RetStatus = QUEUE_NOK;
            My_Queue = NULL;
            free(My_Queue);
        }
        else
        {
            My_Queue->ElementCount = 0;
            My_Queue->QueueFront = -1;
            My_Queue->QueueRear = -1;
            My_Queue->QueueMaxSize = MaxSize;
            *RetStatus = QUEUE_OK;
        }

    }

    return My_Queue;
}

QueueStatus_t Enqueue_Element(Queue_t *QueueObj, void *ItemPtr)
{
    QueueStatus_t status = QUEUE_NOK;
    if((NULL == QueueObj) || (NULL == ItemPtr))
    {
        status = QUEUE_NULL_POINTER;
    }
    else
    {
        //Validate if The Queue is not full.
        if(QueuIsFull(QueueObj))
        {
            status = QUEUE_FULL;
        }
        else
        {
            //Increment to Queue Rear Idex.
            (QueueObj->QueueRear)++;
            if(QueueObj->QueueRear == QueueObj->QueueMaxSize)
            {
                QueueObj->QueueRear = 0;
            }
            //Inserting Data in to the rear Position.
            QueueObj->QueueArray[QueueObj->QueueRear] = ItemPtr;

            if(QueueObj->ElementCount == 0)
            {
                QueueObj->QueueFront = 0;
                QueueObj->ElementCount = 1;
            }
            else
            {
                (QueueObj->ElementCount)++;
            }

            status = QUEUE_OK;
        }

    }
    return status;
}

void *Dequeue_Element(Queue_t *QueueObj, QueueStatus_t *RetStatus)
{
    void *Returned_Value = NULL;
    if((NULL == QueueObj)|| (NULL == RetStatus))
    {
        *RetStatus = QUEUE_NULL_POINTER;
    }
    else
    {
        //Check if the Queue is Empty.
        if(QueuIsEmpty(QueueObj))
        {
            *RetStatus = QUEUE_EMPTY;
            Returned_Value = NULL;
        }
        else
        {
            Returned_Value = QueueObj->QueueArray[QueueObj->QueueFront];
            (QueueObj->QueueFront)++;
            if(QueueObj->QueueFront == QueueObj->QueueMaxSize)
            {
                QueueObj->QueueFront = 0; //for the circular Queue.
            }
            else{/* Do Nothing */}
            // Check if the element is the last element in queue.
            if(1 == QueueObj->ElementCount)
            {
                QueueObj->QueueFront = -1; // Queue is empty.
                QueueObj->QueueRear = -1; // Queue is empty.
            }
            else{/* Do Nothing */}
            (QueueObj->ElementCount)--;
            *RetStatus = QUEUE_OK;
        }
    }
    return (Returned_Value);
}

void *Queue_Front(Queue_t *QueueObj, QueueStatus_t *RetStatus)
{
    void *Returned_Value = NULL;
    if((NULL == QueueObj)|| (NULL == RetStatus))
    {
        Returned_Value = QUEUE_NULL_POINTER;
    }
    else
    {
        if(!QueueObj->ElementCount)
        {
            *RetStatus = QUEUE_EMPTY;
            Returned_Value = NULL;
        }
        else
        {
            Returned_Value = QueueObj->QueueArray[QueueObj->QueueFront];
            *RetStatus = QUEUE_OK;
        }
    }
    return Returned_Value;
}

void *Queue_Rear(Queue_t *QueueObj, QueueStatus_t *RetStatus)
{
    void *Returned_Value = NULL;
    if((NULL == QueueObj)|| (NULL == RetStatus))
    {
        Returned_Value = QUEUE_NULL_POINTER;
    }
    else
    {
        if(!QueueObj->ElementCount)
        {
            *RetStatus = QUEUE_EMPTY;
            Returned_Value = NULL;
        }
        else
        {
            Returned_Value = QueueObj->QueueArray[QueueObj->QueueRear];
            *RetStatus = QUEUE_OK;
        }
    }
    return Returned_Value;
}

QueueStatus_t Get_Queue_Count(Queue_t *QueueObj, uint32 *QueueCount)
{
    QueueStatus_t status = QUEUE_NOK;
    if((NULL == QueueObj)|| (NULL == QueueCount))
    {
        status = QUEUE_NULL_POINTER;
    }
    else
    {
        *QueueCount = QueueObj->ElementCount;
        status = QUEUE_OK;
    }
    return status;
}

QueueStatus_t Destroy_Queue(Queue_t *QueueObj)
{
    QueueStatus_t status = QUEUE_NOK;
    if(NULL == QueueObj)
    {
        free(QueueObj->QueueArray);
        free(QueueObj);
        status = QUEUE_NULL_POINTER;
    }
    else
    {

        status = QUEUE_OK;
    }
    return status;
}



