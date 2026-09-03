#include <stdio.h>

int main ()
{
    int arr[] = {11,24,21,53,75,35,45,1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int max = arr[0],
        min = arr[0];

    for (int i; i < n; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
        else if (min > arr[i])
        {
            min = arr[i];
        }   
    }

    printf("min: %d\n", min);
    printf("max: %d\n", max);
}