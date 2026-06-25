#include <stdio.h>

int main ()
{
    int arr[] = {11,24,14,54,24,111,75};
    int arr1[10], arr2[10];
    int n,num1 = 0, num2 = 0, index;

    // Tính số phần tử
    n = sizeof(arr) / sizeof(arr[0]);

    printf("Nhập index tách: "); scanf("%d", &index);

    // tách mảng
    for (int i = 0; i < n; i++)
    {
        if (i <= index)
            arr1[num1++] = arr[i];   
        
        else    
            arr2[num2++] = arr[i];
    }

    // in mảng con
    for (int i = 0; i < num1; i++)
    {
        printf("mang[%d] = %d\n", i, arr1[i]);
    }
    printf("\n");

    for (int i = 0; i < num2; i++)
    {
        printf("mang[%d] = %d\n", i , arr2[i]);
    }

    return 0;
}