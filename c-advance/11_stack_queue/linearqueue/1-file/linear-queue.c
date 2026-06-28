#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_QUEUE 5

typedef struct
{
    int *items;
    int size;
    int front;
    int rear;
}Queue;

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
        return -1;
    }

    if (q->front = -1)
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
    if (isEmpty(q))
    {
        return -1;
    }
    
    else return q.items[q.front];
}

int rear(Queue q)
{
    if (isEmpty(q))
    {
        return -1;
    }
    
    else return q.items[q.rear];
}

void display(Queue *q)
{
    if (isEmpty(*q))
    {
        printf("Queue empty\n");
    }
    else
    {
        printf("Element of Queue is: ");
        for (int i = q->front; i <= q->rear; i++)
        {
            printf("%d ", q->items[i]);
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
    }
    
}

int main()
{
    Queue q1;
    queue_init(&q1);

    enqueue(&q1,1);
    enqueue(&q1,2);
    enqueue(&q1,3);
    enqueue(&q1,4);
    enqueue(&q1,5);
    enqueue(&q1,6);
    enqueue(&q1,6);
    display(&q1);
    printf("Front: %d\n", front(q1));
    printf("Rear: %d\n", rear(q1));

    printf("-----------------\n");
    dequeue(&q1);
    dequeue(&q1);
    dequeue(&q1);
    dequeue(&q1);
    dequeue(&q1);
    enqueue(&q1,100);
    display(&q1);

    queue_free(&q1);
    return 0;
}