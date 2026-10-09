#include <stdio.h>
#include <stdint.h>

// Hàm xử lý UART
void UARTtx_Transmit(const uint8_t *data)
{
    printf("Data: %s\n", data);
    printf("UART Transmit sucessful.\n");
}

// func_ptr cho callback
static void (*Callback_UART)(const uint8_t *) = NULL;

// Hàm đăng ký callback
void RegisterCallback (void (*fp)(const uint8_t *))
{
    Callback_UART = fp;
}

// Hàm kích hoạt callback
void UARTtx_Handler(const uint8_t *data)
{
    if (Callback_UART == NULL)
    {
        return;
    }

    Callback_UART(data);
}

int main ()
{
    uint8_t arr[] = "Hello";
    RegisterCallback(UARTtx_Transmit);
    UARTtx_Handler(arr);

    return 0;
} 