#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdbool.h>

#define MAX_STACK 5

typedef struct 
{
    int items[MAX_STACK];
    int size;
    int top;
}Stack;

void stack_init(Stack *stack);
bool isEmpty(Stack stack);
bool isFull(Stack stack);
int push(Stack *stack, int data);
int pop(Stack *stack);
int top(Stack stack);
void display(Stack *stack);

#endif // STACK_H