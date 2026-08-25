#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Stack_t
{
    int *items;
    int top;
    int size;
}Stack_t;

typedef enum
{
    STACK_OK,
    STACK_EMPTY,
    STACK_FULL,
    STACK_MALLOC_FAIL
}StackStatus_t;

/* Prototype Function */
/* Tạo stack */

/* Kiểm tra stack đầy & rỗng */
bool isEmpty(Stack_t stack);
bool isFull(Stack_t stack);

/* Các hàm thao tác với stack, dùng kiểu enum */
StackStatus_t create_stack(Stack_t *stack, int new_data);
StackStatus_t push_stack(Stack_t *stack, int new_data);
StackStatus_t pop_stack(Stack_t *stack, int *val);
StackStatus_t top(Stack_t stack, int *data);

/* In stack */
void display_stack(Stack_t stack);

/* Thu hồi địa chỉ stack */
void free_stack(Stack_t *stack);

int main ()
{   
    Stack_t s1;
    int val;
    int top_val;
    if (create_stack(&s1, 5) != STACK_OK)
    {
        printf("Stack create fail!\n");
        return -1;
    }
    
    ;

    push_stack(&s1, 1);
    push_stack(&s1, 2);
    push_stack(&s1, 3);
    push_stack(&s1, 4);
    push_stack(&s1, 5);
    push_stack(&s1, 6);
    push_stack(&s1, 7);

    display_stack(s1);
    if (pop_stack(&s1, &val) == STACK_OK)
    {
        printf("Pop: %d\n", val);
    }

    if (top(s1, &top_val) == STACK_OK)
    {
        printf("Top: %d\n", top_val);

    }
     
    free_stack(&s1);

    return 0;
}

/* Tạo stack */
StackStatus_t create_stack(Stack_t *stack, int new_data)
{
    stack->items = (int*)malloc(new_data * sizeof(int));

    // Kiểm tra malloc thành công không?
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
// Đọc dữ liệu truyền từ main vào hàm-> ko dùng PTR
StackStatus_t push_stack(Stack_t *stack, int new_data)
{
    if (isFull(*stack))
    {
        // printf("Stack full!\n");
        return STACK_FULL;
    }

    else
    {
        stack->items[++stack->top] = new_data; // đọc giá trị new_data(thêm vào ở main) -> ghi vào stack
        return STACK_OK;
    }
}

// Ghi dữ liệu - Lấy dữ liệu ra -> dùng PTR 
StackStatus_t pop_stack(Stack_t *stack, int *val)
{
    if (isEmpty(*stack))
    {
        // printf("Stack empty!\n");
        return STACK_EMPTY;
    }

    else
    {
        *val = stack->items[stack->top--];
        return STACK_OK;
    }
    
}

StackStatus_t top(Stack_t stack, int *data)
{
    if (isEmpty(stack))
    {
        // printf("Stack empty!\n");
        return STACK_EMPTY;
    }
    
    *data = stack.items[stack.top];

    return STACK_OK;
}

/* In stack */
void display_stack(Stack_t stack)
{
    if (isEmpty(stack))
    {
        // printf("Stack empty!\n");
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
        stack->top = -1;
        stack->size = 0;
    }
    
}