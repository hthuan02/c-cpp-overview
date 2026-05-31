#include <stdio.h>      // Thư viện cho phép sử dụng printf,scanf
#include <stdbool.h>    // Thư viện cho phép sử dụng kiểu boolean
#include <stdlib.h>     // Thu viện dùng để cấp phát động malloc, calloc, realooc

#define MAX_STACK 5

typedef struct 
{
    int *items;
    int size;
    int top;
}Stack;


void stack_init(Stack *stack)
{
    stack->items = (int *)malloc( MAX_STACK * sizeof(int));
    stack->size = MAX_STACK;
    stack->top = -1;
}

bool isEmpty(Stack stack)
{
    return stack.top == -1;
}

bool isFull(Stack stack)
{
    return stack.top == stack.size - 1;
}

int push(Stack *stack, int data)
{    
    stack->items[++stack->top] = data;
    return data;
}

int pop(Stack *stack)
{
    return stack->items[stack->top--];
}

int top(Stack stack)
{
    return stack.items[stack.top];
}

void display(Stack *stack)
{
    if (isEmpty(*stack))
    {
        printf("Stack empty!\n");
    }

    else
    {
        printf("Element of Stack is: ");
        for (int i = 0; i <= stack->top; i++)
        {
            printf("%d ", stack->items[i]);
        }
        printf("\n");       
    }

}

void stack_free(Stack *stack)
{
    if (stack->items)
    {
        free(stack->items);
        stack->items = NULL;
        stack->top   = -1;
    }
    
}

int main()  
{
    Stack s1;
    stack_init(&s1);

    push(&s1, 1);
    push(&s1, 2);
    push(&s1, 3);
    push(&s1, 4);
    push(&s1, 5);
    display(&s1);

    printf("Top: %d\n", top(s1));
    pop(&s1);

    display(&s1);

    stack_free(&s1);

    return 0;
}