/** 
 * Kiểm tra byte 0xAA trong buffer hay không
 * Có -> 1; Không -> 0
 * 
 *  Callback theo từng buffer.
 *  @param const uint8_t *data, uint16_t length
 *  -> Xử lý packet, checksum, protocol
 */
#include <stdio.h>
#include <stdint.h>

#define DATA_UART_CHECK 0xAA

static uint8_t (*Callback_UART)(const uint8_t*, uint16_t) = NULL;

uint8_t UARTtx_Check_Buffer(const uint8_t *data, uint16_t length)
{
    // Kiểm tra buffer
    if (data == NULL || length == 0)
    {
        return 0U;
    }
    
    // return 1 -> tìm thấy
    for (uint16_t i = 0; i < length; i++)
    {
        if (data[i] == DATA_UART_CHECK)
        {
            return 1U;
        }
        
    }
    
    // return 0 -> không tìm thấy
    return 0U;
}

void RegisterCallback_UART(uint8_t (*fp)(const uint8_t*, uint16_t))
{
    Callback_UART = fp;
}

uint8_t UARTtx_Handler(const uint8_t *data, uint16_t length)
{
    if (Callback_UART == NULL)
    {
        return 0U;
    }
    
    return Callback_UART(data, length);
}


int main ()
{
    uint8_t data[] = {0x12, 0xAB, 0xFF, 0xF1, 0x44, 0xAA};
    uint8_t length = sizeof(data) / sizeof(data[0]);

    RegisterCallback_UART(UARTtx_Check_Buffer);
    uint8_t result = UARTtx_Handler(data, length);

    printf("Buffer contains 0xAA: %u\n", (unsigned int)result);
    


    return 0;
}