#include <stdio.h>

int main ()
{
    int arr[] ={11,23,43,56,24};
    int n = sizeof(arr) / sizeof(arr[0]);
    int index = 2;
    int val_new = 12345;

    arr[2] = val_new;
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    

    return 0;
}