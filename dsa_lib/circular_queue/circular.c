#include "circular.h"

CircularQueueStatus_t init_queue(Circular_t *q2, int32_t newSize)
{
    q2->items = (int32_t*)malloc(newSize*sizeof(int32_t));
    if (q2->items == NULL)
    {
        q2->front = q2->rear = -1;
        q2->size = 0;
        return CIRCULAR_MALLOC_FAIL;
    }
    
    q2->front = q2->rear = -1;
    q2->size = newSize;

    return CIRCULAR_OK;
}

bool isEmpty(Circular_t q2)
{
    return q2.front == -1;
}

bool isFull(Circular_t q2)
{
    return q2.front == (q2.rear + 1) % q2.size;
}

CircularQueueStatus_t enqueue(Circular_t *q2, int32_t data)
{
    if (isFull(*q2))
    {
        return CIRCULAR_FULL;
    }

    // tăng trước, đọc/ghi sau
    if (q2->front == -1)
    {
        q2->front = 0;
    }

    q2->rear = (q2->rear + 1) % q2->size;
    q2->items[q2->rear] = data;

    return CIRCULAR_OK;
}

CircularQueueStatus_t dequeue(Circular_t *q2, int32_t *data)
{
    if (isEmpty(*q2))
    {
        return CIRCULAR_EMPTY;
    }

    // Đọc/ghi trước, tăng front sau
    *data = q2->items[q2->front];
    if (q2->front == q2->rear)
    {
        q2->front = q2->rear = -1;
    }
    
    else
    {
        q2->front = (q2->front + 1) % q2->size;
    }
    return CIRCULAR_OK;
}

CircularQueueStatus_t front(Circular_t q2, int32_t *data)
{
    if (isEmpty(q2))
    {
        return CIRCULAR_EMPTY;
    }

    *data = q2.items[q2.front];
    return CIRCULAR_OK;
}

CircularQueueStatus_t rear(Circular_t q2, int32_t *data)
{
    if (isEmpty(q2))
    {
        return CIRCULAR_EMPTY;
    }

    *data = q2.items[q2.rear];
    return CIRCULAR_OK;
}

void print_queue(Circular_t q2)
{
    if (isEmpty(q2))
    {
        return;
    }

    printf("Circular queue: ");
    
    int32_t i = q2.front;
    while (1)
    {   
        printf("%d ", q2.items[i]);
        
        if (i == q2.rear) break;
        i = (i + 1) % q2.size;   
    }
    printf("----------\n");
}

void free_queue(Circular_t *q2)
{
    if (q2->items)
    {
        free(q2->items);
        q2->items = NULL;
        q2->front = q2->rear = -1;
        q2->size = 0;
    }
    
}
