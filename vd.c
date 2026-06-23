#include <stdio.h>

int main()
{
    int arr[100], arr1[50], arr2[50];
    int n, index, num1=0, num2=0;


    printf("Nhap so phan tu: "); scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // in mảng
    for (int i = 0; i < n; i++)
    {
        printf("mang[%d] = %d\n", i, arr[i]);
    }
    printf("\n");

    printf("Nhập vị trí muốn tách: "); scanf("%d", &index);

    // Tách mảng
    for (int i = 0; i < n; i++)
    {
        if (i <= index)
        {
            arr1[num1++] = arr[i];
        }

        else
        {
            arr2[num2++] = arr[i];
        }
        
    }

    // in mảng con
    for (int i = 0; i < num1; i++)
    {
        printf("mang1[%d] = %d\n", i, arr1[i]);
    }
    printf("\n");

    for (int i = 0; i < num2; i++)
    {
        printf("mang2[%d] = %d\n", i, arr2[i]);
    }
    
    

    return 0;
}