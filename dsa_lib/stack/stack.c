#include "stack.h"

StackStatus_t init_stack(Stack_t *s1, int32_t new_data)
{
    s1->items = (int32_t*)malloc(new_data*sizeof(int32_t));
    if (s1->items == NULL)
    {
        s1->size = 0;
        s1->top = -1;
        return STACK_MALLOC_FAIL;
    }

    s1->size = new_data;
    s1->top = -1;
    return STACK_OK;
}

bool isEmpty(Stack_t s1)
{
    return s1.top == -1;
}

bool isFull(Stack_t s1)
{
    return s1.top == s1.size -1;
}

StackStatus_t push_stack(Stack_t *s1, int32_t data)
{
    if (isFull(*s1))
    {
        return STACK_FULL;
    }

    // Tăng trước, ghi data -> stack sau
    s1->items[++s1->top] = data;
    return STACK_OK;
}

StackStatus_t pop_stack(Stack_t *s1, int32_t *data)
{
    if (isEmpty(*s1))
    {
        return STACK_EMPTY;
    }
    
    // Ghi trước, giảm sau
    *data = s1->items[s1->top--];

    return STACK_OK;
}

StackStatus_t top_stack(Stack_t s1, int32_t *data)
{
    if (isEmpty(s1))
    {
        return STACK_EMPTY;
    }

    *data = s1.items[s1.top];
    return STACK_OK;
}

void print_stack(Stack_t s1)
{
    if (isEmpty(s1))
    {
        return;
    }

    printf("Stack: ");
    for (int i = 0; i <= s1.top; i++)
    {
        printf("%d ", s1.items[i]);
    }
    printf("-------------\n");
    
}

void free_stack(Stack_t *s1)
{
    if (s1->items)
    {
        free(s1->items);
        s1->items = NULL;
        s1->size = 0;
        s1->top = -1;
    }
}