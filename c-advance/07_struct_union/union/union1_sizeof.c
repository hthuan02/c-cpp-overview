#include <stdio.h>
#include <stdint.h>

typedef union
{
    int a[11];  // 4 -> 4*11 = 44+4pad
    int b;      // 4
    char *c;    // 8
}Union_t;

int main()
{
    Union_t frame;

    printf("Size = %d\n", sizeof(frame));

    return 0;
}