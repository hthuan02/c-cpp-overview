#include <stdio.h>

int main ()
{
    int x = 0x1e;   // 0b00011110
    int y = x;
    int z = x;

    /* Set bit 6*/
    //     0b0001 1110
    //     0b0100 0000
    // ----------------
    // OR: 0b0101 1110 -> 0*2^0 + 1*2^1 + 1*2^2 + 1*2^3 + 1*2^4+ 1*2^6 =94
    //  hexan: 0x5e
    x |= (1U << 6);   
    printf("0x%x\n", x); //0x5e


    /* Reset bit 4 */
    //           0b0001 1110
    // (1<<4)    0b0001 0000
    //~(1<<4)    0b1110 1111
    // AND       0b0000 1110 --> 14 
    // hexan     0x0e
    y &= ~(1U <<4);
    printf("0x%02x\n", y); // 0x0e    

    /* Check bit 5*/
    z = ((1U << 5) & x) != 0;
    printf("%d\n", z);

    //IN từng bit
    int val_bit = 0;
    printf("0b");
    for (int i = 7; i >= 0; i--)
    {   
        val_bit = ((1<< i)& x) != 0;
        printf("%d", val_bit);
    }

    printf("-----------\n");   

    return 0;
}