#include <stdio.h>

int main ()
{
    int arr1[] = {1,2,3,4};
    int arr2[] = {12,23,34};
    int n1,n2, num = 0, s1[100];

    // Tính kích thước 2 mảng
    n1 = sizeof(arr1) / sizeof (arr1[0]);
    n2 = sizeof(arr2) / sizeof (arr2[0]);

    // Gộp mảng
    for (int i = 0; i < n1; i++)
    {
        s1[num++] = arr1[i];
    }
    
    for (int i = 0; i < n2; i++)
    {
        s1[num++] = arr2[i];
    }

    // In mảng đã gộp
    for (int i = 0; i < num; i++)
    {
        printf("mang[%d] = %d\n", i, s1[i]);
    }
    

    return 0;
}