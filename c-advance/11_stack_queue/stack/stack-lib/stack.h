#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdbool.h>

typedef struct 
{
    int *items;
    int size;
    int top;
}Stack;

void stack_init(Stack *stack, int new_data);
bool isEmpty(Stack stack);
bool isFull(Stack stack);
int push(Stack *stack, int data);
int pop(Stack *stack);
int top(Stack stack);
void display(Stack stack);

#endif // STACK_H