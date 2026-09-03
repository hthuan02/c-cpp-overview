#include <stdio.h>
#include <stdint.h>

void unpacking_bit(uint8_t packet)
{
    uint8_t enable = (packet >> 0) & 1U;
    uint8_t direction = (packet >> 1) & 1U;
    uint8_t fault = (packet >> 2) & 1U;

    printf("Enable: %u\n", enable);
    printf("Direction: %u\n", direction);
    printf("Fault: %u\n", fault);
}

void print_packet(uint8_t packet)
{
    for (int i = 7; i >= 0; i--)
    {
        int status_bit = (packet >> i) & 1U;
        printf("%u", status_bit);
    }
    printf("\n");
    
}

int main ()
{
    uint8_t packet = 0x1e;

    printf("Packet: ");
    print_packet(packet);

    unpacking_bit(packet);


    return 0;
}