#include <stdio.h>

int main ()
{
    int arr[] = {11,24,21,53,75,35,45,1};
    int n = sizeof(arr) / sizeof(arr[0]);

    // reverse
    // tạo 2 biến
    // left = đầu arr, right = cuối arr
    // duyệt while(left < right)
    //              --> hoán vị (không cần arr[left] < hoặc > arr[right])  left ++; right --

    int left = 0;
    int right = n -1;
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