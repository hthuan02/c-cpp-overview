#include <stdio.h>

int main ()
{   
    int arr[100], n;

    printf("Nhập số phần tử của mảng: "); scanf("%d", &n);

    // Nhập từng phần tử mảng
    for (int i = 0; i < n ; i++)
    {
        scanf("%d", &arr[i]);
    }

    // In mảng
    for (int i = 0; i < n; i++)
    {
        printf("mang[%d] = %d\n", i, arr[i]);
    }
    



    return 0;
}