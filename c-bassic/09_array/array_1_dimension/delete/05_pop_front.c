#include <stdio.h>

int main ()
{
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr) / sizeof(arr[0]);

    // dịch trái for(++) -> dè mất arr[0]
    // n--
    for (int i = 0; i < n; i++)
    {
        arr[i] = arr[i + 1]; // 2 = 3
    }
    n--;

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    
    

    return 0;
}