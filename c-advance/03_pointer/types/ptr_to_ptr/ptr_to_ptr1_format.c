#include <stdio.h>

int main()
{
    int x = 10;
    int y = 20;

    int *p = &x;
    int **pp = &p;

    *pp = &y; 

    // x  -> 10
    // &x -> địa chỉ x
    // p  -> &x
    // *p -> x
    // pp -> &p
    // &pp -> địa chỉ p
    // *pp -> p -> &x
    // **pp -> x

    // *pp, &x, &y kiểu (int *) 
    // pp kiểu (int **)
    // x kiểu (int)


    printf("%d\n", *p); //20
    printf("%d\n", x); // 10
    printf("%d\n", y); //20

    return 0;
}