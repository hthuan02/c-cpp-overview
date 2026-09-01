#include <stdio.h>

int main ()
{
    int arr[] = {11,24,21,53,75,35,45,1};
    int n = sizeof(arr) / sizeof(arr[0]);

    int index = 2;
    int val_new =1234;

    // dịch phải từ index
    // ghi val_new
    // tăng n

    for (int i = n; i > index; i--)
    {
        arr[i] = arr[i-1];
    }

    arr[index]= val_new;
    n++;

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    
    return 0;
}