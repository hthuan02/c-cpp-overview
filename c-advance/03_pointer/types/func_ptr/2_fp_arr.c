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
    int(*fp[])(int,int) = {sum, sub, mul};

    for (int i = 0; i < 3; i++)
    {
        printf("%d\n",fp[i](1,2));
    }
    

    return 0;
}