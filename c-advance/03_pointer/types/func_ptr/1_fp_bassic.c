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

int main ()
{
    int(*fp)(int,int) = sum;
    printf("%d\n", fp(1,2));

    fp = sub;
    printf("%d\n", fp(1,2));

    fp = mul;
    printf("%d\n", fp(1,2));


    return 0;
}