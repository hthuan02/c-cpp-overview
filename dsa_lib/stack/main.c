#include "stack.h"

int main ()
{
    Stack_t s1;
    int32_t val_delete,
            val_top;

    init_stack(&s1, 5);
    push_stack(&s1,1);
    push_stack(&s1,2);
    push_stack(&s1,3);
    push_stack(&s1,4);
    push_stack(&s1,5);
    push_stack(&s1,111);

    print_stack(s1);

    if (pop_stack(&s1,&val_delete) == STACK_OK)
    {
        printf("Pop: %u\n", val_delete);
    }

    print_stack(s1);

    if (top_stack(s1,&val_top) == STACK_OK)
    {
        printf("Top: %u\n", val_top);
    }
    
    free_stack(&s1);
    return 0;
}