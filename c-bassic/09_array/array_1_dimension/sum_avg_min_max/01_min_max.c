#include <stdio.h>

int main()
{
    int arr[5] = {11,43,54,22,55};

    int n = sizeof(arr)/sizeof(arr[0]);
    printf("n = %d\n", n);

    int max = arr[0],
        min = arr[0];

    for (int i = 0; i < n; i++)
    {
        if (max > arr[i])
        {
            max = arr[i];
        }

        else if(min < arr[i])
        {
            min = arr[i];
        }
        
    }

    printf("Min: %d\n", min);
    printf("Max: %d\n", max);
    
}