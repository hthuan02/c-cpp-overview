#include <stdio.h>

void check_null(int *a)
{
    printf("Function NULL!\n");
}

int main ()
{
    check_null(NULL);


    return 0;
}