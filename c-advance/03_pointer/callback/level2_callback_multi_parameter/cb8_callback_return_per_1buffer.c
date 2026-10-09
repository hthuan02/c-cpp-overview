/**
 *  Kiểm tra từng buffer
 *  Đúng -> 1
 *  Sai -> 0
 * 
 *  Callback theo từng buffer một.
 *  @param const uint8_t *data, uint16_t length
 *  -> Xử lý packet, checksum, protocol
 */
#include <stdio.h>
#include <stdint.h>

#define DATA_UART_CHECK 0xAA

static uint8_t (*Callback_UART)(uint8_t) = NULL;

uint8_t UARTtx_Check_Data(uint8_t data)
{
    return (data == DATA_UART_CHECK)? 1U: 0U;
}

void RegisterCallback_UART(uint8_t (*fp)(uint8_t))
{
    Callback_UART = fp;
}

uint8_t UARTtx_Handler(uint8_t data)
{
    if (Callback_UART == NULL)
    {
        return 0U;
    }
    
    return Callback_UART(data);
}


int main ()
{
    uint8_t data[] = {0x12, 0xAB, 0xFF, 0xF1, 0x44, 0xAA};
    uint16_t length = sizeof(data) / sizeof(data[0]);

    RegisterCallback_UART(UARTtx_Check_Data);
    
    // Duyệt buffer
    for (uint16_t i = 0; i < length; i++)
    {
        uint8_t result = UARTtx_Handler(data[i]);
        printf("Data: 0x%02X -> Result: %u\n", 
                            (unsigned int) data[i],
                            (unsigned int) result);
    }
    


    return 0;
}