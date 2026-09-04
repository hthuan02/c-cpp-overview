#include <stdio.h>
#include <stdint.h>

void print_binary(uint8_t reg)
{
    printf("0b");
    for (int i = 7; i >= 0; i--)
    {
        uint8_t val_reg = (reg >> i) & 1U;
        printf("%u", val_reg);
    }
    
    printf("\n");
}

uint8_t set_bit(uint8_t *reg, uint8_t pos)
{
    return *reg |= (1U << pos);
}

uint8_t reset_bit(uint8_t *reg, uint8_t pos)
{
    return *reg &= ~(1U << pos);
}

uint8_t toggle_bit(uint8_t *reg, uint8_t pos)
{
    return *reg ^= (1U << pos);
}

uint8_t read_bit(uint8_t *reg, uint8_t pos)
{
    return *reg = ((1U << pos)& *reg) != 0;
}

int main ()
{
    uint8_t reg = 0x1e;

    print_binary(reg);

    set_bit(&reg, 0);
    print_binary(reg);

    reset_bit(&reg,2);
    print_binary(reg);

    toggle_bit(&reg, 4);
    print_binary(reg);

    uint8_t val_check_bit = read_bit(&reg, 2);
    printf("Check bit: %u\n", val_check_bit);

    return 0;
}