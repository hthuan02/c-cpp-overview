#ifndef __LINEAR_H
#define __LINEAR_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Linear_t
{
    int32_t *items;
    int32_t front;
    int32_t rear;
    uint32_t size;
}Linear_t;

typedef enum
{
    LINEAR_OK,
    LINEAR_EMPTY,
    LINEAR_FULL,
    LINEAR_MALLOC_FAIL
}LinearQueueStatus_t;

bool isEmpty(Linear_t q);
bool isFull(Linear_t q);

LinearQueueStatus_t create_queue(Linear_t *q, uint32_t data);
LinearQueueStatus_t enqueue(Linear_t *q, int32_t data);
LinearQueueStatus_t dequeue(Linear_t *q, int32_t *data);
LinearQueueStatus_t get_front(Linear_t q, int32_t *data);
LinearQueueStatus_t get_rear(Linear_t q, int32_t *data);

void print_queue(Linear_t q);
void free_queue(Linear_t *q);

#endif // __LINEAR_H