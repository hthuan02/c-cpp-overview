#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Queue_t
{
    uint32_t *items;
    int32_t front;
    int32_t rear;
    uint32_t size;
}Queue_t;

typedef enum
{
    QUEUE_OK,
    QUEUE_FULL,
    QUEUE_EMPTY,
    QUEUE_MALLOC_FAIL
}QueueCircularStatus_t;

/* Kiểm tra empty & full */
bool isEmpty(Queue_t q);
bool isFull(Queue_t q);

QueueCircularStatus_t create_queue(Queue_t *q, uint32_t size);
QueueCircularStatus_t enqueue(Queue_t *q, uint32_t data);
QueueCircularStatus_t dequeue(Queue_t *q, uint32_t *data);
QueueCircularStatus_t front(Queue_t q, uint32_t *value);
QueueCircularStatus_t rear(Queue_t q, uint32_t *value);

void print_queue(Queue_t q);
void free_queue(Queue_t *q);

int main ()
{
    Queue_t q1;
    int32_t val_dequeue,
            val_front,
            val_rear;

    create_queue(&q1, 5);

    enqueue(&q1,1);
    enqueue(&q1,2);
    enqueue(&q1,3);
    enqueue(&q1,4);
    enqueue(&q1,5);
    enqueue(&q1,6);

    print_queue(q1);
    
    if (dequeue(&q1, &val_dequeue) == QUEUE_OK)
    {
        printf("Dequeue: %d\n", val_dequeue);
    }
    
    print_queue(q1);
    if (front(q1, &val_front) == QUEUE_OK)
    {
        printf("Front: %d\n", val_front);
    }
    
    if (rear(q1, &val_rear) == QUEUE_OK)
    {
        printf("Rear: %d\n", val_rear);
    }
    
    free_queue(&q1);
    return 0;
}

QueueCircularStatus_t create_queue(Queue_t *q, uint32_t data)
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
    return q.front == (q.rear + 1) % q.size;
}

QueueCircularStatus_t enqueue(Queue_t *q, uint32_t data)
{
    if (isFull(*q))
    {
        return QUEUE_FULL;
    }

    // Kiểm tra rỗng, vì queue rỗng enqueue mới được
    if (q->front == -1)
    {
        q->front = 0;
    }
    
    q->rear = (q->rear + 1) % q->size;
    // Tăng rear trước, ghi giá trị sau
    q->items[q->rear] = data;

    return QUEUE_OK;
}

QueueCircularStatus_t dequeue(Queue_t *q, uint32_t *data)
{
    if (isEmpty(*q))
    {
        return QUEUE_EMPTY;
    }

    // Đọc trước, tăng front sau 
    *data = q->items[q->front]; 
    
    // Kiểm tra sau khi đọc
    if (q->front == q->rear)
    {
        q->front = q->rear = -1;
    }
    else
    {
        q->front = (q->front + 1) % q->size;
    }
    return QUEUE_OK;
}

QueueCircularStatus_t front(Queue_t q, uint32_t *value)
{
    if (isEmpty(q))
    {
        return QUEUE_EMPTY;
    }

    *value = q.items[q.front];

    return QUEUE_OK;
}

QueueCircularStatus_t rear(Queue_t q, uint32_t *value)
{
    if (isEmpty(q))
    {
        return QUEUE_EMPTY;
    }
    *value = q.items[q.rear];

    return QUEUE_OK;
}

void print_queue(Queue_t q)
{
    if (isEmpty(q))
    {
        return; 
    }

    else
    {
        /**
         *  Không dùng for, vì circular queue xoay vòng 
         *  --> Bắt buộc dùng while(1)
         *  khi front == rear thì break;
         **/
        printf("Queue: ");

        int32_t i = q.front;
        while (1)
        {
            printf("%d ", q.items[i]);

            if (i == q.rear)
            {
                break;
            }
            
            i = (i+1) % q.size;
        }
        printf("---------\n");        
        
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
