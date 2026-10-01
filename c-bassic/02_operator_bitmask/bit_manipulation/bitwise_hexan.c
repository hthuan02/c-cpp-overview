#include <stdio.h>

void print_binary(int *x)
{
    printf("0b");
    for (int i = 7; i >=0; i--)
    {
        int bit = (*x >> i) & 1;
        printf("%d", bit);
    }
    printf("\n");
    
}

int main ()
{
    int x = 0x10; // 0b0001 0000 = 16

    // set bit 3
    int set_bit = x;
    set_bit |= (1 << 3);
    print_binary(&set_bit);

    int clear_bit = x;
    clear_bit &= ~(1 << 4);
    print_binary(&clear_bit);

    int toggle_bit = x;
    toggle_bit ^=   (1 << 1) |
                    (1 << 2) |
                    (1 << 7);
    print_binary(&toggle_bit);

    int check_bit = (toggle_bit & (1<< 2)) != 0;
    printf("%d\n", check_bit); 

    return 0;
}