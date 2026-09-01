#ifndef LINEAR_QUEUE_H
#define LINEAR_QUEUE_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct Linear_t
{
    int32_t *items;
    int32_t front;
    int32_t rear;
    uint32_t size;
}Linear_t;

typedef enum
{
    LINEAR_OK = 0,
    LINEAR_EMPTY,
    LINEAR_FULL,
    LINEAR_MALLOC_FAIL
}LinearQueueStatus_t;

LinearQueueStatus_t init_linear(Linear_t *q1, uint32_t data);

bool isEmpty(Linear_t q1);
bool isFull(Linear_t q1);

LinearQueueStatus_t enqueue(Linear_t *q1, int32_t data);
LinearQueueStatus_t dequeue(Linear_t *q1, int32_t *data);
LinearQueueStatus_t front(Linear_t q1, int32_t *data);
LinearQueueStatus_t rear(Linear_t q1, int32_t *data);

void print_linear(Linear_t q1);
void free_linear(Linear_t *q1);

#endif // LINEAR_QUEUE_H