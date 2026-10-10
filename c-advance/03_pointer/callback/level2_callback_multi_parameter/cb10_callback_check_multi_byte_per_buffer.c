/**
 *  Kiểm tra nhiều byte data theo buffer
 *  - Đúng -> 1
 *  - Sai -> 0
 *  - Kết hợp typdef(alias) định nghĩa <func_ptr> thành <data_type>
 * 
 *  @param uint8_t *data length
 *  -> Phát hiện byte đặc biệt 0xAA 0x1E 0xAB,...
 */

/**
 *  CODE BÀI 10 XEM CHO VUI THÔI 
 *  CÁCH DÙNG 1 CALLBACK CHO NHIỀU ĐỐI TƯỢNG VÀ TRUYỀN PARAMATER KIỂU NÀY
 *  --> KHÔNG TỐI ƯU
 *  --> DÙNG STRUCT ĐỂ PHÁT TRIỂN  
 */

#include <stdio.h>
#include <stdint.h>

typedef uint8_t (*callback_t)(const uint8_t *, uint8_t, const uint8_t *, uint8_t);

static callback_t callback_uart = NULL;

uint8_t uart_tx_check_buffer(const uint8_t *data, uint8_t size, const uint8_t *target, uint8_t len)
{   
    // Kiểm tra data, size
    if (data == NULL || size == 0 || target == NULL || len == 0)
    {
        return 0U;
    }
    
    // Tìm thấy byte data
    for (uint8_t i = 0; i < size; i++)
    {
        for (uint8_t j = 0; j < len; j++)
        {
            if (data[i] == target[j])
            {
                return 1U;
            }
        }
        
    }
    
    // Không tìm thấy byte data
    return 0U;
}

void register_callback (callback_t fp)
{
    callback_uart = fp;
}

uint8_t uart_tx_handler(const uint8_t *data, uint8_t size, const uint8_t *target, uint8_t len)
{
    if (callback_uart == NULL)
    {
        return 0U;
    }
    
    return callback_uart(data, size, target, len);
}

int main ()
{
    uint8_t buffer[] = 
    {
        0xAA, 0xFA, 0x44, 0xEE, 0x1E, 0xAB, 0x6B
    };
    uint8_t length = sizeof(buffer) / sizeof(buffer[0]);
    
    uint8_t target[] = 
    {
        0xAA, 0xAB, 0xBB, 0x1E
    };
    uint8_t size = sizeof(target) / sizeof(target[0]); 

    register_callback(uart_tx_check_buffer);
    

    for (uint8_t i = 0; i < size; i++)
    {
        uint8_t result = uart_tx_handler(buffer, length, &target[i], 1U);
        printf("Data: 0x%02X -> Result: %u\n", target[i], result);
    }
    

    return 0;
}