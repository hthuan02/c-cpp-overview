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
    int(*fp[])(int,int) = {sum, sub, mul};

    const char *s[] = {"Sum", "Sub", "Mul"};

    for (int i = 0; i < 3; i++)
    {
        int result = cal(1,2,fp[i]);
        printf("%s = %d\n",s[i], result);
    }
    

    return 0;
}