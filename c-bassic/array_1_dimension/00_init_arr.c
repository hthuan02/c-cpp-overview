#include <stdio.h>

int main ()
{
    int arr[100];
    int n =5;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\n");
    printf("arr[%d] = {", n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);

        if (i < n -1)
        {
            printf(",");
        }
    }
    printf("}");
    
    return 0;
}