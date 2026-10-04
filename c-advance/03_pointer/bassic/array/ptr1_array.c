#include <stdio.h>

int main ()
{
    int arr[] = {1,2,3,4,5};
    int *p = arr; 
    
    // tên của mảng là phần tử đầu tiên của mảng
    // p = arr = &arr[0]

    // Giá trị phần tử
    printf("%d %d %d\n", *p, p[0], arr[0]);    
    printf("%d %d %d\n", *(p + 1), p[1], arr[1]);
    printf("%d %d %d\n", *(p + 2), p[2], arr[2]);
    
    // Địa chỉ phần tử
    printf("%p %p\n", p, &arr[0]);    
    printf("%p %p\n", p + 1, &arr[1]);
    printf("%p %p\n", p + 2, &arr[2]);
    
    // Cách truy cập giá trị khác của array
    printf("%d %d\n", *(arr+2), 2[arr]);

    // arr, &arr
    // arr = &arr[0] địa chỉ phần tử đầu tiên của mảng
    // &arr địa chỉ toàn bộ mảng

    // arr: 0x00
    // arr + 1 : 0x04
    // &arr + 1: 0x14
    printf("%p\n", arr+1);
    printf("%p\n", &arr+1);


    return 0;
}