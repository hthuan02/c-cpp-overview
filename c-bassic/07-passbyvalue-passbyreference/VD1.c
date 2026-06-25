#include<stdio.h>
#include<stdlib.h>

void giam1donvi(int *var) // var = 100
{
    *var = *var - 1;  // var = 99 // 0x00 0x01 0x02 0x3
    // var: địa chỉ truyền vào
    // *var: giá trị tại vùng địa chỉ truyền vào
}
int main()
{
    int x = 100; // 0x00 0x02 0x03 0x03
    printf("Trước: x = %d\n",x); // 100
    giam1donvi(&x); 
    // &x: truyền vùng địa chỉ của x  
    // x: truyền giá trị của x
    printf("Sau: x = %d\n",x); // 99

    return 0;
}