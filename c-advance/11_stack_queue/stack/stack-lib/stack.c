#include "stack.h"

StackStatus_t stack_init(Stack_t *stack, uint32_t new_data)
{
    stack->items = (uint32_t*)malloc(new_data * sizeof(uint32_t));
    if (stack->items == NULL)
    {   
        stack->top = -1;
        stack->size = 0;
    
        return STACK_MALLOC_FAIL;
    }
    stack->top = -1;
    stack->size = new_data;

    return STACK_OK;
}
bool isEmpty(Stack_t stack)
{
    return stack.top == -1;
}

bool isFull(Stack_t stack)
{
    return stack.top == stack.size - 1;
}

StackStatus_t push(Stack_t *stack, int32_t data)
{
    if (isFull(*stack))
    {
        return STACK_FULL;
    }

    // Tăng trước - đọc/ghi sau
    // Ghi data vào stack
    stack->items[++stack->top] = data;
    
    return STACK_OK;
}

StackStatus_t pop(Stack_t *stack, int32_t *data)
{
    if (isEmpty(*stack))
    {
        return STACK_EMPTY;
    }

    // Đọc/Ghi trước - giảm sau
    // Ghi stack vào biến data, để xóa
    *data = stack->items[stack->top--];
    
    return STACK_OK;
}

StackStatus_t top(Stack_t stack, int32_t *data)
{
    if (isEmpty(stack))
    {
        return STACK_EMPTY;
    }

    // Đọc/Ghi trước - giảm sau
    // Ghi stack vào biến data, để xóa
    *data = stack.items[stack.top];
    
    return STACK_OK;
}

void print_stack(Stack_t stack)
{
    if (isEmpty(stack))
    {
        return;
    }

    else
    {
        printf("Stack: ");
        for (int i = 0.; i <= stack.top; i++)
        {
            printf("%d ", stack.items[i]);
        }
        printf("---------\n");
    }
    
}

void free_stack(Stack_t *stack)
{
    if (stack->items)
    {
        free(stack->items);
        stack->items = NULL;
        stack->top = -1;
    }
    
}
