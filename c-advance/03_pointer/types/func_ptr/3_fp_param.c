#include  <stdio.h>

int sum (int a, int b)
{
    return a+b;
}

int sub (int a, int b)
{
    return a-b;
}

int mul (int a, int b)
{
    return a*b;
}

int cal (int a, int b, int(*fp)(int, int))
{
    return fp(a,b);
}

int main ()
{
    printf("%d\n", cal(1,2,sum));

    
    return 0;
}