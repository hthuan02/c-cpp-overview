#include<stdio.h>
#include<stdlib.h>

void giam1donvi(int var) // var = 100
{
    var = var - 1;  // var = 99 // 0x09 0x10 0xd 0xe
}// rời khỏi hàm, biến var bị cấp thoát địa chỉ, giá trị bị mất

int main()
{
    int x = 100; // 0x01 0x02 0x03 0x04
    printf("Trước: x = %d\n",x); // 100
    giam1donvi(x);  // Để thay đổi được thì phải truyền địa chỉ của biến x, truyền tham chiếu 
    printf("Sau: x = %d\n",x); // 100

    return 0;
}