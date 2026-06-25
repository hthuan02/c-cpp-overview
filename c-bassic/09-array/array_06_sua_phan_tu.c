// Sửa phần tử trong mảng

/**
 *  1 22 4 14 54
 *  0  1 2  3  4
 * 
 *  --> Index: 2 , arr[2] = 4 
 *                 arr[2] = new_var
 * 
 *  ==> arr[i] = new_var
 * 
 */

#include <stdio.h>

int main ()
{
    int arr[] = {11,34,24,25,75,98,46};
    int n = 7, index, var;
    // printf("%d\n", sizeof(arr) / sizeof(arr[0]));

    printf("Nhập vị trí sửa (index): ");     scanf("%d", &index); 
    printf("Nhập giá trị mới (variable): "); scanf("%d", &var); 

    arr[index] = var; 
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    

    return 0;
}