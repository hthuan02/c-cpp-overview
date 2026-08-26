#include "linear.h"

LinearQueueStatus_t create_queue(Linear_t *q, uint32_t data)
{
    q->items = (uint32_t*)malloc(data * sizeof(uint32_t));
    
    if (q->items == NULL)
    {
        q->front = q->rear = -1;
        q->size = 0;

        return LINEAR_MALLOC_FAIL;
    }
    
    q->front = q->rear = -1;
    q->size = data;

    return LINEAR_OK;
}

bool isEmpty(Linear_t q)
{
    return q.front == -1;
}

bool isFull(Linear_t q)
{
    return q.rear == q.size -1;
}

LinearQueueStatus_t enqueue(Linear_t *q, int32_t data)
{
    if (isFull((*q)))
    {
        return LINEAR_FULL;
    }

    // Kiểm tra rỗng trước
    if (q->front == -1)
    {
        q->front = 0;
    }

    // Tăng trước, ghi sau
    q->items[++q->rear] = data;

    return LINEAR_OK;
}

LinearQueueStatus_t dequeue(Linear_t *q, int32_t *data)
{
    if (isEmpty(*q))
    {
        return LINEAR_EMPTY;
    }

    // Đọc trước, tăng front sau
    *data = q->items[q->front++];

    // Kiểm tra khi nào rỗng, linear -> front > rear
    if (q->front > q->rear)
    {
        q->front = q->rear = -1;
    }

    return LINEAR_OK;    
}

LinearQueueStatus_t get_front(Linear_t q, int32_t *data)
{
    if (isEmpty(q))
    {
        return LINEAR_EMPTY;
    }

    // Đọc dữ liệu
    *data = q.items[q.front];
    return LINEAR_OK;
}

LinearQueueStatus_t get_rear(Linear_t q, int32_t *data)
{
    if (isEmpty(q))
    {
        return LINEAR_EMPTY;
    }

    *data = q.items[q.rear];
    return LINEAR_OK;
}

void print_queue(Linear_t q)
{
    if (isEmpty(q))
    {
        return;
    }

    else
    {   
        printf("Queue: ");
        for (uint32_t i = q.front; i <= q.rear; i++)
        {
            printf("%d ", q.items[i]);
        }
        printf("-----------\n");
    }
    
}

void free_queue(Linear_t *q)
{
    if (q->items)
    {
        free(q->items);
        q->items = NULL;
        q->front = q->rear = -1;
        q->size = 0;
    }
    

}