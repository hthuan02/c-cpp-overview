#include <stdio.h>

int sum (int a, int b)
{
    return a + b;
}

int sub (int a, int b)
{
    return a - b;
}

int mul (int a, int b)
{
    return a * b;
}

int div (int a, int b)
{
    return a /b;
}

int main ()
{
    int (*fp[])(int, int) = {sum, sub, mul, div};

    for (size_t i = 0; i < 4; i++)
    {
        fp[i](1,2);
        printf("%p\n",&fp[i]);
    }

    // Địa chỉ các hàm trong fp[](int,int) được xếp liền kề nhau, cách 8 byte
    //i=0   0x5ffe20
    //i=-1  0x5ffe28
    //i=2   0x5ffe30
    //i=3   0x5ffe38
    
    // data_type of fp
    // fp        → int (**)(int,int)    // sizeof = 32
    // *fp       → int (*)(int,int)     //8
    // fp[0]     → int (*)(int,int)     //8
    // &fp[0]    → int (**)(int,int)    //8


    return 0;
}