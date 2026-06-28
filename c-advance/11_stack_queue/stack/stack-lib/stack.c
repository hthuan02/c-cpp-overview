#include "stack.h"

void stack_init(Stack *stack)
{
    stack->size = MAX_STACK;
    stack->top  = -1;
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
    if (isFull(*stack))
    {
        printf("Stack full.\n");
    }

    else 
    {
        // tăng trước, đọc/ghi sau
        stack->items[++stack->top] = data;
        // printf("Added element: %d\n", data);
        return data;
    }
    
}

int pop(Stack *stack)
{
    if (isEmpty(*stack))
    {
        printf("Stack empty.\n");
    }

    else
    {
        // đọc/ghi trước, xóa sau
        int var = stack->items[stack->top--];
        // printf("Remove element: %d\n", var);
        return var;
    }
    
}

int top(Stack stack)
{
    if (isEmpty(stack))
    {
        printf("Stack empty.\n");
    }

    else
    {
        // đọc/ghi trước, xóa sau
        return stack.items[stack.top];
    }

}

void display(Stack *stack)
{
    if (isEmpty(*stack))
    {
        printf("Stack empty.\n");
    }

    else
    {   
        printf("Element of stack: ");
        for (int i = 0; i <= stack->top; i++)
        {
            printf("%d ", stack->items[i]);
        }
        printf("\n");
    }
}
