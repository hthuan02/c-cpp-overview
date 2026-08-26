#include <stdio.h>

int main ()
{
    int arr[] ={11,23,43,56,24};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    // reverse: 24 56 43 23 11
    //          ^            ^
    //         left        right
    //
    // - init val_left & val_right
    // - while (left > right) -> hoán vị 2 đầu
    // - left++ , right --

    int left = 0;
    int right = n - 1;

    while (left < right)
    {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        left++;
        right--;
    }


    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    

    return 0;
}