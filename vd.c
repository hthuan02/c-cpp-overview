#include <stdio.h>

void hoan_vi(int *x, int *y)
{
    int temp;

    // tăng dần
    if (*x > *y)
    {
        temp = *x;
        *x = *y;
        *y = temp;
    }
    
}

int main ()
{   
    int arr[] = {11,43,13,75,35,34,65,22,356};

    int n = sizeof(arr) / sizeof(arr[0]);

    // Sắp xếp trực tiếp (interchange Sort)
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            hoan_vi(&arr[i], &arr[j]);
        }
        
    }

    // In mảng đã sắp xếp
    for (int i = 0; i < n ; i++)
    {
        printf("%d", arr[i]);
        if (i < n -1 )
        {
            printf(", ");
        }
        
    }
    


    


    return 0;
}