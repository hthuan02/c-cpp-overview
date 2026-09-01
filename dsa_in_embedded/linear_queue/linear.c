#include "linear.h"

LinearQueueStatus_t init_linear(Linear_t *q1, uint32_t data)
{
    q1->items = (int32_t*)malloc(data*sizeof(int32_t));
    if (q1->items == NULL)
    {
        q1->front = q1->rear = -1;
        q1->size = 0;
        return LINEAR_MALLOC_FAIL;
    }

    q1->front = q1->rear = -1;
    q1->size = data;

    return LINEAR_OK;
}

bool isEmpty(Linear_t q1)
{
    return q1.front == -1;
}

bool isFull(Linear_t q1)
{
    return q1.rear == q1.size - 1;
}

LinearQueueStatus_t enqueue(Linear_t *q1, int32_t data)
{
    if (isFull(*q1))
    {
        return LINEAR_FULL;
    }
    
    if (q1->front == -1)
    {
        q1->front = 0;
    }

    // Tăng trước, đọc/ghi sau
    q1->items[++q1->rear] = data;
    
    return LINEAR_OK;
}

LinearQueueStatus_t dequeue(Linear_t *q1, int32_t *data)
{
    if (isEmpty(*q1))
    {
        return LINEAR_EMPTY;
    }

    // Đọc/ghi trước, tăng front sau
    *data = q1->items[q1->front++];

    if (q1->front > q1->rear)
    {
        q1->front = q1->rear = -1;
    }
    
    return LINEAR_OK;
}

LinearQueueStatus_t front(Linear_t q1, int32_t *data)
{
    if (isEmpty(q1))
    {
        return LINEAR_EMPTY;
    }
    
    *data = q1.items[q1.front];

    return LINEAR_OK;
}

LinearQueueStatus_t rear(Linear_t q1, int32_t *data)
{
    if (isEmpty(q1))
    {
        return LINEAR_EMPTY;
    }
    *data = q1.items[q1.rear];

    return LINEAR_OK;
}

void print_linear(Linear_t q1)
{
    if (isEmpty(q1))
    {
        return;
    }

    printf("Linear queue: ");
    for (int32_t i = q1.front; i <= q1.rear; i++)
    {
        printf("%d ", q1.items[i]);
    }
    
    printf("-----------\n");
}

void free_linear(Linear_t *q1)
{
    if (q1->items)
    {
        free(q1->items);
        q1->items = NULL;
        q1->front = q1->rear = -1;
        q1->size = 0;
    }
    
}
