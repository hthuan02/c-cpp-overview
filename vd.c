#include <stdio.h>

int main ()
{
    int arr[] = {0x01, 0x02, 0x03, 0x04};
    int *ptr = arr;

    printf("%d\n", sizeof(ptr));  // 8 - kích thước con trỏ phụ thuộc vào kiến trúc máy tính
    printf("%d\n", sizeof(*ptr)); // 4 - kích thước của kiểu dữ liệu mà con trỏ nó trỏ đến
    printf("%d\n", sizeof(arr));  // 16 - kích thước của mảng

    return 0;
}