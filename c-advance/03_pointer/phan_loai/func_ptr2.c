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
    // Mảng function-pointer, địa chỉ function liền kề nhau trên RAM
    int (*fp[])(int,int) =
    {
        sum,
        sub,
        multi
    };

    const char *str[] = 
    {
        "sum",
        "sub",
        "multi"
    };

    for (int i = 0; i < 3; i++)
    {
        printf("%p - %s=%d\n",
                fp+i,
                str[i],
                fp[i](1,2));
    }

    return 0;
}