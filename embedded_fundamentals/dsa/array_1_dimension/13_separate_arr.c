#include <stdio.h>

int main ()
{
    int arr[] = {1,2,3,4,5,6,7,8,8,9};
    int num = sizeof(arr) / sizeof(arr[0]);

    int arr1[50] = {0};
    int arr2[50] = {0};
    int n1 = 0, n2 = 0;
    int index = 2;

    // duyệt arr1[] -> 0 -> trước index
    // duyệt arr2[] -> index -> n
    // in mảng

    for (int i = 0; i < index; i++)
    {
        arr1[n1++] = arr[i];
    }
    
    for (int i = index; i < num; i++)
    {
        arr2[n2++] = arr[i];
    }

    // in mảng
    for (int i = 0; i < n1; i++)
    {
        printf("%d ", arr1[i]);
    }

    printf("--------\n");
    for (int i = 0; i < n2; i++)
    {
        printf("%d ", arr2[i]);
    }
    
    
    

    return 0;
}