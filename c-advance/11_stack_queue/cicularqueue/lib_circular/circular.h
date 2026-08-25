#ifndef __CIRCULAR_H
#define __CIRCULAR_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
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
    CIRCULAR_OK,
    CIRCULAR_EMPTY,
    CIRCULAR_FULL,
    CIRCULAR_MALLOC_FAIL
}QueueCircularStatus_t;

/* Hàm khởi tạo queue, thêm, xóa queue */
QueueCircularStatus_t create_queue(Queue_t *q, uint32_t data);
QueueCircularStatus_t enqueue(Queue_t *q, int32_t data);
QueueCircularStatus_t dequeue(Queue_t *q, int32_t *data);
QueueCircularStatus_t front(Queue_t q, int32_t *data);
QueueCircularStatus_t rear(Queue_t q, int32_t *data);

/* Hàm kiểm tra queue */
bool isEmpty(Queue_t q);
bool isFull(Queue_t q);

/* Hàm display queue */
void print_queue(Queue_t q);

/* Hàm thu hồi queue */
void free_queue(Queue_t *q);

#endif // __CIRCULAR_H