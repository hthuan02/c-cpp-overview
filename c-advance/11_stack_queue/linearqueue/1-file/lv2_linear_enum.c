#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct Queue_t
{
    uint32_t *items;
    uint32_t size;
    int32_t front;
    int32_t rear;
}Queue_t;

typedef enum
{
    QUEUE_OK,
    QUEUE_MALLOC_FAIL,
    QUEUE_EMPTY,
    QUEUE_FULL
}QueueStatus_t;

/* Prototype function */
QueueStatus_t create_queue(Queue_t *q, uint32_t data);

bool isEmpty(Queue_t q);
bool isFull(Queue_t q);

QueueStatus_t enqueue(Queue_t *q, uint32_t data);

// Đọc data, lấy dữ liệu phải dùng con trỏ
// Vừa return status, return data (phải có con trỏ)
QueueStatus_t dequeue(Queue_t *q, uint32_t *data);
QueueStatus_t get_front(Queue_t q, uint32_t *val);
QueueStatus_t get_rear(Queue_t q, uint32_t *val);

void print_queue(Queue_t q);
void free_queue(Queue_t *q);


int main ()
{
    Queue_t q1;
    uint32_t val_dequeue;
    uint32_t val_front;
    uint32_t val_rear;

    create_queue(&q1, 5);
    enqueue(&q1, 1);
    enqueue(&q1, 2);
    enqueue(&q1, 3);
    enqueue(&q1, 4);
    enqueue(&q1, 5);
    enqueue(&q1, 6);
    print_queue(q1);

    // Vì không phải lúc nào dequeue cũng lấy được data
    // Gần kiểm tra status trước khi lấy
    if (dequeue(&q1, &val_dequeue) == QUEUE_OK)
    {
        printf("Dequeue: %d\n", val_dequeue);
    }
    print_queue(q1);
    

    if (get_front(q1, &val_front) == QUEUE_OK)
    {
        printf("Front: %d\n", val_front);
    }
    
    if (get_rear(q1, &val_rear) == QUEUE_OK)
    {
        printf("Rear: %d\n", val_rear);
    }

    return 0;
}


QueueStatus_t create_queue(Queue_t *q, uint32_t data)
{
    q->items = (uint32_t*)malloc(data * sizeof(uint32_t));
    if (q->items == NULL)
    {
        q->front = q->rear = -1;
        q->size = 0;

        return QUEUE_MALLOC_FAIL;
    }
    q->front = q->rear = -1;
    q->size = data;

    return QUEUE_OK;
}

bool isEmpty(Queue_t q)
{
    return q.front == -1;
}

bool isFull(Queue_t q)
{
    return q.rear == q.size - 1;
}

QueueStatus_t enqueue(Queue_t *q, uint32_t data)
{
    if (isFull(*q))
    {
        return QUEUE_FULL;
    }

    if (q->front == -1)
    {
        q->front = 0;
    }
    q->items[++q->rear] = data;
    
    return QUEUE_OK;
}

QueueStatus_t dequeue(Queue_t *q, uint32_t *data)
{
    if (isEmpty(*q))
    {
        return QUEUE_EMPTY;
    }

    *data = q->items[q->front++];

    if (q->front > q->rear)
    {
        q->front = q->rear = -1;
    }
    
    return QUEUE_OK;
}

QueueStatus_t get_front(Queue_t q, uint32_t *val)
{
    if (isEmpty(q))
    {
        return QUEUE_EMPTY;
    }

    // đọc data, nếu ghi ngược lại là ghi
    *val = q.items[q.front];

    return QUEUE_OK;
}

QueueStatus_t get_rear(Queue_t q, uint32_t *val)
{
    if (isEmpty(q))
    {
        return QUEUE_EMPTY;
    }
    *val = q.items[q.rear];

    return QUEUE_OK;
}

void print_queue(Queue_t q)
{
    if (isEmpty(q))
    {
        printf("Queue empty! Cant print.\n");
        return;
    }
    else
    {
        printf("Queue: ");
        for (uint32_t i = q.front; i <= q.rear; i++)
        {
            printf("%d ", q.items[i]);
        }
        printf("-------------\n");
    }
    
}

void free_queue(Queue_t *q)
{
    if (q->items)
    {
        free(q->items);
        q->items = NULL;
        q->front = q->rear = -1;
        q->size = 0;
    }
    
}