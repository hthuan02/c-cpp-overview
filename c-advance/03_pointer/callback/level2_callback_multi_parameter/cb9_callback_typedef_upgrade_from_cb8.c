/**
 *  Kiểm tra 1 byte data theo buffer
 *  - Đúng -> 1
 *  - Sai -> 0
 *  - Kết hợp typdef(alias) định nghĩa <func_ptr> thành <data_type>
 * 
 *  @param uint8_t *data length
 *  -> Phát hiện byte đặc biệt 0xAA
 */

#include <stdio.h>
#include <stdint.h>

#define UART_DATA_CHECK 0x44

typedef uint8_t (*callback_t)(const uint8_t *, uint8_t );

static callback_t callback_uart = NULL;

uint8_t uart_tx_check_buffer(const uint8_t *data, uint8_t size)
{   
    // Kiểm tra data, size
    if (data == NULL || size == 0)
    {
        return 0U;
    }
    
    // Tìm thấy byte data
    for (uint8_t i = 0; i < size; i++)
    {
        if (data[i] == UART_DATA_CHECK)
        {
            return 1U;
        }
    }
    
    // Không tìm thấy byte data
    return 0U;
}

void register_callback (callback_t fp)
{
    callback_uart = fp;
}

uint8_t uart_tx_handler(const uint8_t *data, uint8_t size)
{
    if (callback_uart == NULL)
    {
        return 0U;
    }
    
    return callback_uart(data, size);
}

int main ()
{
    uint8_t buffer[] = {0xAA, 0xFA, 0x44, 0xEE, 0xAB, 0x6B};
    uint8_t length = sizeof(buffer) / sizeof(buffer[0]);

    register_callback(uart_tx_check_buffer);
    uint8_t result = uart_tx_handler(buffer, length);

    printf("Buffer contains 0x44: %u\n", (unsigned int)result);

    return 0;
}