/**
 *  Tại sao gọi &p mà không gọi p? 
 */

// a
// │
// ├── a    : int
// └── &a   : int *

// p
// │
// ├── p    : int *
// ├── *p   : int
// └── &p   : int **

// p1
// │
// ├── p1   : int **
// ├── *p1  : int *
// ├── **p1 : int
// └── &p1  : int ***

#include <stdio.h>

void change(int **pp)
{
    static int y = 20;
    *pp = &y;   // *pp = p = &y
}

int main()
{
    int x = 10;     //0x4c
    int *p = &x;    //0x4c // p -> &x; *p = x 

    change(&p);     // p -> &y 

    
    // gọi &p -> địa chỉ của p
    // p      -> địa chỉ biến x

    printf("%d\n", *p); // *p = y

    return 0;
}