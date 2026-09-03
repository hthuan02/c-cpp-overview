#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct Stack_t
{
    int32_t *items;
    int32_t top;
    uint32_t size;
}Stack_t;

typedef enum
{
    STACK_OK = 0,
    STACK_MALLOC_FAIL,
    STACK_EMPTY,
    STACK_FULL
}StackStatus_t;

StackStatus_t init_stack(Stack_t *s1, int32_t new_data);

bool isEmpty(Stack_t s1);
bool isFull(Stack_t s1);

StackStatus_t push_stack(Stack_t *s1, int32_t data);
StackStatus_t pop_stack(Stack_t *s1, int32_t *data);
StackStatus_t top_stack(Stack_t s1, int32_t *data);

void print_stack(Stack_t s1);
void free_stack(Stack_t *s1);

#endif // STACK_H