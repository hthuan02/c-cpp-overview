#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Stack_t
{
    int *items;
    int top;
    int size;
}Stack_t;

/* Prototype Function */
/* Tạo stack */
void create_stack(Stack_t *stack, int new_data);

/* Kiểm tra stack đầy & rỗng */
bool isEmpty(Stack_t stack);
bool isFull(Stack_t stack);

/* Thêm & xóa stack */
int push_stack(Stack_t *stack, int new_data);
int pop_stack(Stack_t *stack);

/* Lấy giá trị top */
int top(Stack_t stack);

/* In stack */
void display_stack(Stack_t stack);

/* Thu hồi địa chỉ stack */
void free_stack(Stack_t *stack);

int main ()
{   
    Stack_t s1;
    create_stack(&s1, 5);

    push_stack(&s1, 1);
    push_stack(&s1, 2);
    push_stack(&s1, 3);
    push_stack(&s1, 4);
    push_stack(&s1, 5);
    push_stack(&s1, 6);
    push_stack(&s1, 7);

    // pop_stack(&s1);
    // pop_stack(&s1);

    display_stack(s1);

    printf("Top: %d\n", top(s1));

    free_stack(&s1);

    return 0;
}

/* Tạo stack */
void create_stack(Stack_t *stack, int new_data)
{
    stack->items = (int*)malloc(new_data * sizeof(int));

    // Kiểm tra malloc thành công không?
    if (stack->items == NULL)
    {
        stack->top = -1;
        stack->size = 0;

        return;
    }

    stack->top = -1;
    stack->size = new_data;
}

/* Kiểm tra stack đầy & rỗng */
bool isEmpty(Stack_t stack)
{
    return stack.top == -1;
}

bool isFull(Stack_t stack)
{
    return stack.top == stack.size - 1;
}

/* Thêm & xóa stack */
int push_stack(Stack_t *stack, int new_data)
{
    if (isFull(*stack))
    {
        printf("Stack full!\n");
        return -1;
    }

    else
    {
        stack->items[++stack->top] = new_data; // đọc giá trị new_data(thêm vào ở main) -> ghi vào stack
        return new_data;
    }
}

int pop_stack(Stack_t *stack)
{
    if (isEmpty(*stack))
    {
        printf("Stack empty!\n");
        return -1;
    }

    else
    {
        int val = stack->items[stack->top--];
        return val;
    }
    
}

int top (Stack_t stack)
{
    if (isEmpty(stack))
    {
        printf("Stack empty!\n");
        return -1;
    }
    
    return stack.items[stack.top];
}

/* In stack */
void display_stack(Stack_t stack)
{
    if (isEmpty(stack))
    {
        printf("Stack empty!\n");
        return;
    }

    else
    {   
        printf("Stack: ");
        for (int i = 0; i <= stack.top; i++)
        {
            printf("%d ", stack.items[i]);
        }
        printf("------------\n");
    }
}

/* Thu hồi địa chỉ stack */
void free_stack(Stack_t *stack)
{
    if (stack->items)
    {
        free(stack->items);
        stack->items = NULL;
    }
    
}