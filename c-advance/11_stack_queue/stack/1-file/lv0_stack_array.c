
#include <stdio.h>

#define MAX_SIZE 5
int main ()
{
    int items[MAX_SIZE];
    int top = -1;

    items[++top] = 1;
    items[++top] = 2;
    items[++top] = 3;
    items[++top] = 4;
    items[++top] = 5;
    items[++top] = 1;
    items[++top] = 4;
    items[++top] = 5;
    items[++top] = 1;


    printf("Stack: ");
    for (int i = 0; i < top; i++)
    {   
        if (top == MAX_SIZE -1)
        {
            printf("stack full!\n");
            break;
        }
        
        printf("%d ", items[i]);
    }
    printf("-------------\n");


    return 0;
}