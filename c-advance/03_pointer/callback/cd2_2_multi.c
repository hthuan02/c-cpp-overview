#include <stdio.h>

int SumHandler(int a, int b)
{
    return a+b;
}

int SubHandler(int a, int b)
{
    return a-b;
}

int MulHandler(int a, int b)
{
    return a*b;
}

static int (*CallbackSum)(int, int) = NULL;
static int (*CallbackSub)(int, int) = NULL;
static int (*CallbackMul)(int, int) = NULL;

void RegisterSum_Callback(int (*fp)(int, int))
{
    CallbackSum = fp;
}

void RegisterSub_Callback(int (*fp)(int, int))
{
    CallbackSub = fp;
}

void RegisterMul_Callback(int (*fp)(int, int))
{
    CallbackMul = fp;
}

int SumCall(int a, int b)
{
    if (CallbackSum == NULL)
    {
        return -1;
    }
    
    return CallbackSum(a,b);
}

int SubCall(int a, int b)
{
    if (CallbackSub == NULL)
    {
        return -1;
    }
    
    return CallbackSub(a,b);
}

int MulCall(int a, int b)
{
    if(CallbackMul == NULL)
    {
        return -1;
    }

    return CallbackMul(a,b);
}

int main ()
{
    RegisterSum_Callback(SumHandler);
    RegisterSub_Callback(SubHandler);
    RegisterMul_Callback(MulHandler);

    printf("%d\n", SumCall(1,2));
    printf("%d\n", SubCall(1,2));
    printf("%d\n", MulCall(1,2));

    return 0;
}