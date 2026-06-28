#include "stack.h"

int main ()
{
    Stack s1;
    stack_init(&s1);

    push(&s1, 1);
    push(&s1, 2);
    push(&s1, 3);
    push(&s1, 4);
    push(&s1, 5);
    push(&s1, 6);
    push(&s1, 7);

    display(&s1);
    printf("Top: %d\n", top(s1));
    printf("Pop: %d\n", pop(&s1));

    display(&s1);

    return 0;
}