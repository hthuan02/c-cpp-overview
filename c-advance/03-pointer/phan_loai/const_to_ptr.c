#include<stdio.h>

int a = 10;
int b = 3;
int *const ptr = &a;

int main()
{
    printf("%p\n", ptr);  // &a
    printf("%d\n", *ptr); // 10

    *ptr = 15; // thay đổi dược giá trị
    // ptr = &b;  // LỖI! Không thể thay đổi được được chỉ, chỉ trỏ đến 1 địa chỉ duy nhất

    printf("%p\n", ptr); 
    printf("%d\n", *ptr); // 15

    return 0;
}