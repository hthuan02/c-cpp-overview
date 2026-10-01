#include <stdio.h>

void print_bit(unsigned char *x)
{
    printf("0b");
    for (int i = 7; i >= 0; i--)
    {
        int bit = (*x>>i)& 1;
        printf("%d",bit);
    }
    
}


int main ()
{
    unsigned char x = 0b00001111;

    // Set bit 4
    // x |= (1 <<4);

    // Clear bit 1
    // x &= ~(1<<0);

    // Toggle bit 3
    // x ^= (1 << 3);

    // Check bit 2
    x = (x & (1 << 1)) != 0;
    printf("%d", x);

    // print_bit(&x);

    return 0;
}