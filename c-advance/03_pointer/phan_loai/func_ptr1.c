#include <stdio.h>

int sum(int a, int b)
{
    return a+b;
}

int sub(int a, int b)
{
    return a-b;
}

int multi(int a, int b)
{
    return a*b;
}

int main ()
{
    int (*fp)(int, int) = NULL;
    // Địa chỉ function-pointer rời rạc, ở vị trí bất kỳ

    fp = sum;
    printf("%p - sum=%d\n",fp,fp(1,2));

    fp = sub;
    printf("%p - sub=%d\n",fp,fp(1,2));
    
    fp = multi;
    printf("%p - multi=%d\n",fp,fp(1,2));
    return 0;
}