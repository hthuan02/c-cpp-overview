#include <stdio.h>
#include <stdint.h>

void print_bit(uint32_t bit)
{
    for(int i = 31; i >= 0 ; i--)
    {
        uint32_t val_status_bit = ((1UL << i) & bit) != 0;
        printf("%u", val_status_bit);
    }
    printf("\n");
    
}

void set_bit(uint32_t *bit, uint8_t pos)
{
    *bit |= (1UL << pos);
}

void reset_bit(uint32_t *bit, uint8_t pos)
{
    *bit &= ~(1UL << pos);
}

void toggle_bit(uint32_t *bit, uint8_t pos)
{
    *bit ^= (1UL << pos);
}

int main ()
{
    uint32_t val_bit = 0x1e;  
    uint8_t val_pos;  
    print_bit(val_bit);

    set_bit(&val_bit, 3);
    print_bit(val_bit);

    reset_bit(&val_bit,5);
    print_bit(val_bit);

    toggle_bit(&val_bit,4);
    print_bit(val_bit);

    return 0;
}