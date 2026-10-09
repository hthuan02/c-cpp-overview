#include <stdio.h>

int ternary_func(int a, int b)
{
    return (a > b) ? 1 : 0;
}

int main ()
{
    int a = 10;
    int b = 20;

    printf("%d\n",ternary_func(a,b));



    return 0;
}