#ifndef __LINEAR_QUEUE_H__
#define __LINEAR_QUEUE_H__

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

void queue_init(Queue *q);
bool isEmpty(Queue q);
bool isFull(Queue q);
int enqueue(Queue *q, int data);
int dequeue(Queue *q);
int front(Queue q);
int rear(Queue q);
void display(Queue q);
void queue_free(Queue *q);

#endif // __LINEAR_QUEUE_H