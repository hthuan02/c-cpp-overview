#include <stdio.h>
#include <stdint.h>

// Hàm transmit UART
void UARTtx_Transmit(uint8_t *data, uint16_t length)
{
    printf("Data Binary:");

    // Duyệt mảng
    for (uint16_t i = 0; i < length; i++)
    {
        // Chuyển hexan sang binary
        for (int8_t bit = 7; bit > 0; bit--)
        {
            printf("%u", (unsigned int)((data[i] >> bit) & 1U));
        }
        
        printf(" ");
    }
    
    printf("\n");
    printf("UART Transmit successful.\n");
}

// func_ptr dùng cho callback
static void (*CallbackUART)(uint8_t *, uint16_t) = NULL;

// Hàm đăng ký callback
void RegisterCallback(void (*fp)(uint8_t *, uint16_t))
{
    CallbackUART = fp;
}

// Hàm kích hoạt callback
void UARTtx_Handler (uint8_t *data, uint16_t length)
{
    if (CallbackUART == NULL)
    {
        return;
    }

    CallbackUART(data, length);    
}

int main ()
{
    uint8_t data[] = {0x12, 0xff, 0xaa, 0xca, 0x44};
    uint16_t len = sizeof(data) / sizeof(data[0]);

    RegisterCallback(UARTtx_Transmit);
    UARTtx_Handler(data, len);

    return 0;
}