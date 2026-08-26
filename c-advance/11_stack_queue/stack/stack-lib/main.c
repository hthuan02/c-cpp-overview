#include "stack.h"

int main ()
{
    Stack_t s1;
    int32_t val_top,
            val_pop;

    stack_init(&s1, 5);

    push(&s1, 1);
    push(&s1, 2);
    push(&s1, 3);
    push(&s1, 4);
    push(&s1, 5);
    push(&s1, 6);
    push(&s1, 7);

    print_stack(s1);
    
    
    if (pop(&s1, &val_pop) == STACK_OK)
    {
        printf("Pop: %d\n", val_pop);
    }

    print_stack(s1);

    if (top(s1, &val_top) == STACK_OK)
    {
        printf("Top: %d\n", val_top);
    }
    return 0;
}