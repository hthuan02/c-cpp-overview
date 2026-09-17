#include <stdio.h>

int sum(int a, int b)
{
    return a + b;
}

int cal(int a, int b, int (*fp)(int,int))
{
    return fp(a,b);
}

int main ()
{
    int (*fp)(int,int);
    fp = sum;

    int data = cal(1,2, sum);
    printf("%d\n", data);

    return 0;
}