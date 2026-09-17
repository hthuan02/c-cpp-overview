#include <stdio.h>

int main()
{
    int a = 10;
    printf("%p\n", &a);
    int b = 20;
    int c = 30;
    int *p[5] = {&a, &a, &c};

    for (int i = 0; i < 3; i++)
    {
        printf("%p, %p, Data = %d\n", (void*)(p+i),(void*)p[i], *p[i]);
    }
    

    return 0;
}