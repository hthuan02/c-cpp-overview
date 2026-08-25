#include "circular.h"

void queue_init(Circle *q1)
{
    q1->items = (int *)malloc(MAX_QUEUE * sizeof(int));
    q1->size  = MAX_QUEUE;
    q1->front = q1->rear = -1;
}

bool isEmpty(Circle q1)
{
    return q1.front == -1;
}

bool isFull(Circle q1)
{
    return q1.front == (q1.rear +1) % q1.size;
}

int enqueue(Circle *q1, int data)
{
    if(isFull(*q1)) return -1;
    
    if (q1->front == -1)
    {
        q1->front = 0;
    }
    q1->rear = (q1->rear +1)% q1->size;
    q1->items[q1->rear] = data;

    return data;
}


int dequeue(Circle *q1)
{
    if (isEmpty(*q1)) return -1;
    
    // Lấy dữ liệu trước
    int value = q1->items[q1->front];
    
    // Còn 1 phần tử
    if (q1->front == q1->rear)
    {
        q1->front = q1->rear = -1;
    }

    // Còn nhiều phần tử 
    else 
    {
        q1->front = (q1->front +1) % q1->size;
    }
    
    return value;
}

int front(Circle q1)
{
    if (isEmpty(q1)) return -1;
    else return q1.items[q1.front];
}
int rear(Circle q1)
{
    if (isEmpty(q1)) return -1;
    else return q1.items[q1.rear];
}

void display(Circle *q1)
{
    if (isEmpty(*q1))
    {
        printf("Queue empty");
    }
    else
    {
        printf("Element of queue is: ");
        int i = q1->front;
        while (1)
        {
            printf("%d ", q1->items[i]);

            if(i == q1->rear)
            {
                break;
            }
            i = (i + 1)% q1->size;

        }
        printf("\n");
        
    }
    
}

void queue_free(Circle *q1)
{
    if (q1->items)
    {
        free(q1->items);
        q1->items = NULL;
    }
    
}
