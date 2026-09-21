#include<stdio.h>

int a = 10;
int b = 3; //Khai bao ptr_const cua b duoc.
const int *ptr_const = &a;

int main(int argc, char const *argv[])
{
    printf("%p\n", ptr_const);  // &a
    printf("%d\n", *ptr_const); // 10

    // *ptr_const = 5;
    // Dong nay sai, chi co the thay doi gia tri tai a. Khong the thay doi gia tri *ptr

    a = 15;
    ptr_const = &b;
    
    printf("%p\n", ptr_const);  // &b
    printf("%d\n", *ptr_const); // 15

    return 0;
}