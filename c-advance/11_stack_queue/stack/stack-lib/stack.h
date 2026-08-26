#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct Stack_t
{
    int32_t *items;
    int32_t top;
    uint32_t size;
}Stack_t;

typedef enum
{
    STACK_OK,
    STACK_EMPTY,
    STACK_FULL,
    STACK_MALLOC_FAIL
}StackStatus_t;

StackStatus_t stack_init(Stack_t *stack, uint32_t new_data);
bool isEmpty(Stack_t stack);
bool isFull(Stack_t stack);

StackStatus_t push(Stack_t *stack, int32_t data);
StackStatus_t pop(Stack_t *stack, int32_t *data);
StackStatus_t top(Stack_t stack, int32_t *data);

void print_stack(Stack_t stack);
void free_stack(Stack_t *stack);

#endif // STACK_H