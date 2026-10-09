#include <stdio.h>
#include <stdint.h>

// Hàm UART Transmit
void UARTtx_Transmit(const uint8_t *data, uint16_t length)
{
    printf("Data Binary: ");
    // Duyệt array
    for (uint16_t i = 0; i < length; i++)
    {
        // Chuyển hexan sang binary
        for (int8_t bit = 7; bit >= 0; bit--)
        {   
            // Check bit: (reg >> i) & 1U
            printf("%x",(unsigned int)(data[i] >> bit) & 1U);
        }
        printf(" ");
    }

    printf("\n");
    printf("UART Transmit successful.\n");
}

// func_ptr dùng callback
static void (*Callback_UARTtx)(const uint8_t *, uint16_t) = NULL;

// Hàm đăng ký callback
void RegisterCallback (void (*fp)(const uint8_t *, uint16_t))
{
    Callback_UARTtx = fp;
}

// Hàm kích hoạt callback
void UARTtx_Handler (const uint8_t *data, uint16_t length)
{
    if (Callback_UARTtx == NULL || length == 0)
    {
        return;
    }
    
    Callback_UARTtx (data, length);
}

int main ()
{
    uint8_t data[] = {0x04, 0x01, 0xAA, 0x23, 0xFF};
    
    size_t len = sizeof(data) / sizeof(data[0]);

    RegisterCallback (UARTtx_Transmit);
    UARTtx_Handler(data, len);

    return 0;
}