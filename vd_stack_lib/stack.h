#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct 
{
    int *items;
    int size;
    int top;
}stack_t;

// prototype
void stack_init(stack_t *s1, int newSize);
bool isEmpty(stack_t s1);
bool isFull(stack_t s1);
int push(stack_t *s1, int data);
int pop(stack_t *s1);
int top(stack_t);
void display(stack_t *s1);
void stack_free(stack_t *s1);

#endif // STACK_H