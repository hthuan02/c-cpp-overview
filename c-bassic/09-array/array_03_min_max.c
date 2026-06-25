#include <stdio.h>

int main ()
{   
    int arr[] = {11,23,43,53,23,89,78,99};
    int n;
    int max = arr[0];
    int min = arr[0];

    n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++)
    {   
        if (max < arr[i])
            max = arr[i];
        
        if (min > arr[i])
            min = arr[i];
    }

    printf("Max: %d\n", max);
    printf("Min: %d\n", min);

    return 0;
}