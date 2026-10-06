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

int cal (int a, int b, int (*fp)(int, int))
{
    return fp(a,b);
}

int main ()
{   
    int (*fp[])(int, int) = {sum, sub, mul, div};

    for (int i = 0; i < 4; i++)
    {
        cal(1,2,fp[i]);
        &fp[i];
        (void *)fp[i];
    }
    // 0x7ff6a8b21490
    

    return 0;
}