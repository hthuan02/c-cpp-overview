#include <stdio.h>

int sum(int a, int b)
{
    return a+b;
}

int sub(int a, int b)
{
    return a-b;
}

int mul(int a, int b)
{
    return a*b;
}

static int (*Callback_Cal)(int, int) = NULL;

void RegisterCallback(int (*fp)(int, int))
{
    Callback_Cal = fp;
}

int Cal(int a, int b)
{
    if (Callback_Cal == NULL)
    {
        return -1;
    }
    
    return Callback_Cal(a,b);
}

int main ()
{
    RegisterCallback(sum);
    printf("%d\n", Callback_Cal(1,2));

    return 0;
}