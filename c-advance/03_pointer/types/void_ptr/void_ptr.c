#include <stdio.h>

int main ()
{
    int arr[] = {0x01, 0x02, 0x03, 0x04};
    void *ptr = arr;
    printf("%p\n", arr);        // 0x00
    printf("%p\n", arr + 1);    // 0x04 // tăng lên 4 byte vì tăng lên theo byte <data_type>

    // printf("%p\n", &arr);       // 0x00 -> <sizeof(int) * 4 = 16
    // printf("%p\n", &arr + 1); // 0x10 

    printf("%p\n", ptr + 1);        // 0x01 // Tăng lên 1 byte hoặc lỗi, vì con trỏ kiểu void (không có kích thước)
    printf("%p\n",(int*)ptr + 1);   // ép kiểu để tính kích thước như vầy là đúng hơn

    return 0;
}