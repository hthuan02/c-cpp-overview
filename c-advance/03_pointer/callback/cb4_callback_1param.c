#include <stdio.h>
#include <stdint.h>

// Hàm xử lý UART
void UARTtx_Transmit(uint8_t data)
{
    printf("Data: %c\n", data);
    printf("UART Transmit sucessful.\n");
}

// func_ptr cho callback
static void (*Callback_UART)(uint8_t) = NULL;

// Hàm đăng ký callback
void RegisterCallback (void (*fp)(uint8_t))
{
    Callback_UART = fp;
}

// Hàm kích hoạt callback
void UARTtx_Handler(uint8_t data)
{
    if (Callback_UART == NULL)
    {
        return;
    }

    Callback_UART(data);
}

int main ()
{
    uint8_t arr = 'a';
    RegisterCallback(UARTtx_Transmit);
    UARTtx_Handler(arr);

    return 0;
} 