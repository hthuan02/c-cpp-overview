#include <stdio.h>

// Hàm xử lý, sử dụng callback
void UART_Transmit(void)
{
    printf("Transit data sucessful.\n");
}

// Tạo *fp cho callback
static void (*Callback_UART)(void) = NULL;

// Đăng ký callback
void RegisterCallback (void (*fp)(void))
{
    Callback_UART = fp;
}

// Yêu cầu thực thi callback
void UART_Transmit_Handler(void)
{
    if (Callback_UART == NULL)
    {
        return ;
    }

    Callback_UART();    
}

int main ()
{
    RegisterCallback(UART_Transmit);
    UART_Transmit_Handler();

    return 0;
}