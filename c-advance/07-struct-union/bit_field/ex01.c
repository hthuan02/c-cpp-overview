#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

typedef union
{
    bool enable:1;
    bool mode:1;
    bool speed:1;
} status_t;

// bit-field cùng kiểu -> compiler gom vào `unsigned int`.
// 32 bit (26 padd)

int main ()
{
    status_t var;

    printf("Size of struct: %d\n", sizeof(var));   

    return 0;
}