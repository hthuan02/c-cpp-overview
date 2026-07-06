#include "stack.h"

void stack_init(stack_t *s1, int newSize)
{
    s1->items = (int *)malloc(newSize * sizeof(int));
    s1->size = newSize;
    s1->top = -1;
}

bool isEmpty(stack_t s1)
{
    return s1.top == -1;
}

bool isFull(stack_t s1)
{
    return s1.top == s1.size - 1;
}

int push(stack_t *s1, int data)
{
    if (isFull(*s1)) return -1;
    else
    {
        // tăng trước, đoc/ghi sau
        s1->items[++s1->top] = data;
        return data;
    }    

}

int pop(stack_t *s1)
{
    if(isEmpty(*s1)) return -1;
    else
    {
        // đọc/ghi trước, giảm sau
        int value = s1->items[s1->top--];
        return value;
    } 
}

int top(stack_t s1)
{
    if(isEmpty(s1)) return -1;
    else return s1.items[s1.top];
}

void display(stack_t *s1)
{
    if(isEmpty(*s1)) printf("Stack is empty!\n");
    else
    {
        printf("Element is Stack: ");
        for (int i = 0; i <= s1->top; i++)
        {
            printf("%d ", s1->items[i]);
        }
        
    }

}

void stack_free(stack_t *s1)
{   
    // Trước khi thu hồi phải kiểm tra vùng nhớ của item có tồn tại hay không
    if (s1->items != NULL)
    {   
        free(s1->items); // Sau khi kiểm tra thì thu hồi
        s1->items = NULL;// Thu hồi xong thì gán lại = NULL
    }
    
}