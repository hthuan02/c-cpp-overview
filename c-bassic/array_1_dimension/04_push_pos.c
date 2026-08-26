#include <stdio.h>

int main ()
{
    int arr[] ={11,23,43,56,24};
    int n = sizeof(arr) / sizeof(arr[0]);
    int index = 2;
    int val_new = 12345;

    // dịch phải for(--) arr từ index
    // ghi val_new
    // n++
    for (int i = n; i > index; i--)
    {
        arr[i] = arr[i-1];
    }
    arr[index] = val_new;
    n++;

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}