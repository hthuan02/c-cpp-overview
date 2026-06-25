#include <stdio.h>

void tong3soTN(int a, int b, int c)
{
    int result;
    result = a + b + c;
    printf("Tổng 3 số: %d + %d + %d = %d\n",a,b,c,result);
}



int main ()
{   
    tong3soTN(1,2,3);
    tong3soTN(4,5,6);
    return 0;
}