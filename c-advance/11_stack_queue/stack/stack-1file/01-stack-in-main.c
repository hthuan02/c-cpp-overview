#include <stdio.h>

int main ()
{
    int items[5];
    int top = -1;

    // push
    items[++top] = 10;
    items[++top] = 20;
    items[++top] = 30;
    items[++top] = 40;
    items[++top] = 50;

    printf("Top = %d\n", items[top]);
    printf("Pop = %d\n", items[top--]);

    printf("Element of Stack is: ");
    for (int i = 0; i <= top; i++)
    {
        printf("%d ", items[i]);
    }
    printf("\n");
    

    return 0;
}