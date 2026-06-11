#include <stdio.h>

int main ()
{
    int a = 10;
    int *ptr = &a;

    printf("%p\n", &a);     // địa chỉ của biến a
    printf("%p\n", ptr);    // địa chỉ mà con trỏ nó trỏ đến, cũng là địa chỉ biến a

    *ptr = 200; 
    printf("%d\n", *ptr);   // dereferences: giải tham chiếu con trỏ, để truy cập giá trị của con trỏ mà nó trỏ đến

    return 0;
}