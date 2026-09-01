#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct Circular_t
{
    int32_t *items;
    int32_t front;
    int32_t rear;
    uint32_t size;
}Circular_t;

typedef enum 
{
    CIRCULAR_OK,
    CIRCULAR_MALLOC_FAIL,
    CIRCULAR_EMPTY,
    CIRCULAR_FULL,
}CircularQueueStatus_t;

CircularQueueStatus_t init_queue(Circular_t *q2, int32_t newSize);
bool isEmpty(Circular_t q2);
bool isFull(Circular_t q2);

CircularQueueStatus_t enqueue(Circular_t *q2, int32_t data);
CircularQueueStatus_t dequeue(Circular_t *q2, int32_t *data);
CircularQueueStatus_t front(Circular_t q2, int32_t *data);
CircularQueueStatus_t rear(Circular_t q2, int32_t *data);

void print_queue(Circular_t q2);
void free_queue(Circular_t *q2);


#endif // CIRCULAR_QUEUE_H