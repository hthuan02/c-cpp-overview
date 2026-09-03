#include <stdio.h>
#include <stdint.h>

uint8_t packing_bit(uint8_t enable, uint8_t direction, uint8_t fault)
{
    uint8_t status_bit = 0;

    status_bit = (enable << 0)
               | (direction << 1)
               | (fault << 2);

    return status_bit;
}

int main ()
{
    uint8_t enable = 1;
    uint8_t direction = 0;
    uint8_t fault = 1;

    uint8_t val_packing_bit = packing_bit(enable, direction, fault);

    printf("0x%02x\n", val_packing_bit);
    // 0x05 // 0b00000101

    return 0;
}