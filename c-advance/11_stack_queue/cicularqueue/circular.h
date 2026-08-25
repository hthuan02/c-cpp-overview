#ifndef _CIRCULAR_QUEUE_H
#define _CIRCULAR_QUEUE_H

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
}Circle;

void queue_init(Circle *q1);
bool isEmpty(Circle q1);
bool isFull(Circle q1);
int enqueue(Circle *q1, int data);
int dequeue(Circle *q1);
int front(Circle q1);
int rear(Circle q1);
void display(Circle *q1);
void queue_free(Circle *q1);

#endif 