#include <stdio.h>
#include <stdlib.h>     
#include <stdbool.h>

typedef struct Queue_t
{
    int *items;
    int front;
    int rear;
    int size;
}Queue_t;

void create_queue(Queue_t *q, int size);
bool isEmpty(Queue_t q);
bool isFull(Queue_t q);
int enqueue(Queue_t *q, int new_data);
int dequeue(Queue_t *q);
int get_front(Queue_t q);
int get_rear(Queue_t q);
void print_queue(Queue_t q);
void free_queue(Queue_t *q);

int main ()
{
    Queue_t q1;

    create_queue(&q1, 5);

    enqueue(&q1,1);
    enqueue(&q1,2);
    enqueue(&q1,3);
    enqueue(&q1,4);
    enqueue(&q1,5);
    enqueue(&q1,6);
    enqueue(&q1,7);

    dequeue(&q1);
    dequeue(&q1);
    dequeue(&q1);
    dequeue(&q1);
    dequeue(&q1);

    enqueue(&q1,1000);

    print_queue(q1);
    printf("Front: %d\n", get_front(q1));
    printf("Rear: %d\n", get_rear(q1));

    free_queue(&q1);

    return 0;
}

void create_queue(Queue_t *q, int data)
{
    q->items = (int*)malloc(data * sizeof(int));
    if (q->items == NULL)
    {
        q->front = q->rear = -1;
        q->size = 0;

        return;
    }

    q->front = q->rear = -1;
    q->size = data;
}

bool isEmpty(Queue_t q)
{
    return q.front == -1;
}

bool isFull(Queue_t q)
{
    return q.rear == q.size -1;
}

int enqueue(Queue_t *q, int new_data)
{
    if (isFull(*q))
    {
        printf("Queue full!\n");
        return -1;
    }

    if (q->front == -1)
    {
        q->front = 0;
    }

    // Tăng giá trị trước, ghi data sau
    // int a = b; --> đọc b  
    // int a;
    // b = a; --> ghi a
    q->items[++q->rear] = new_data;
    
    return new_data;
}

int dequeue(Queue_t *q)
{
    if (isEmpty(*q))
    {
        printf("Queue empty!\n");
        return -1;
    }

    // Đọc data trước, tăng front
    int val = q->items[q->front++];

    // Kiểm tra lại
    if (q->front > q->rear)
    {
        q->front = q->rear = -1;
    }
    
    return val;
}

int get_front(Queue_t q)
{
    if (isEmpty(q))
    {
        printf("Queue empty");
        return -1;
    }
    else
        return q.items[q.front];
}

int get_rear(Queue_t q)
{
    if (isEmpty(q))
    {
        printf("Queue empty");
        return -1;
    }
    
    return q.items[q.rear];
}

void print_queue(Queue_t q)
{
    if (isEmpty(q))
    {
        printf("Queue empty!\n");
        return;
    }

    else
    {
        printf("Queue: ");
        for (int i = q.front; i <= q.rear; i++)
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
