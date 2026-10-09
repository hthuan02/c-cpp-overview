#include <stdio.h>
#define CHECK_DATA 5

int ternary_func(int value)
{
    return (value == CHECK_DATA)? 1: 0; 
}

int main ()
{
    int arr[] = {1,2,11,5,2};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++)
    {
        int result = ternary_func(arr[i]);
        printf("Data: %d -> Result: %d\n", arr[i], result);
    }

    return 0;
}