#include "linear.h"

void queue_init(Queue *q)
{
    q->items = (int *)malloc(MAX_QUEUE * sizeof(int));
    q->size  = MAX_QUEUE;
    q->front = q->rear = -1; 
}

bool isEmpty(Queue q)
{
    return q.front == -1;
}

bool isFull(Queue q)
{
    return q.rear == q.size - 1;
}

int enqueue(Queue *q, int data)
{
    if (isFull(*q))
    {
        printf("Queue full\n");
        return -1;
    }
    if (q->front == -1)
    {
        q->front = 0;
    }
    
    q->items[++q->rear] = data;

    return data;
}

int dequeue(Queue *q)
{
    if (isEmpty(*q))
    {
        printf("Queue empty\n");
        return -1;
    }

    int value = q->items[q->front++];
    if (q->front > q->rear)
    {
        q->front = q->rear = -1;
    }
    
    return value;
}

int front(Queue q)
{
    return q.items[q.front];
}

int rear(Queue q)
{
    return q.items[q.rear];
}

void display(Queue q)
{
    if (isEmpty(q))
    {
        printf("Queue empty\n");
    }
    else 
    {   
        printf("Element of queue is: ");
        for (int i = q.front; i <= q.rear; i++)
        {
            printf("%d ", q.items[i]);
        }
        printf("\n");
    }
}

void queue_free(Queue *q)
{
    if (q->items)
    {
        free(q->items);
        q->items = NULL;
        // q->front = q->rear = -1;
    }
    
}