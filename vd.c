#include <stdio.h>

// Hàm xử lý, tính toán, truyền data,...
void tx_UART_Transmit(void)
{
    printf("Data transmit sucessful.\n");
}

// funv_ptr lưu callback
static void (*UART_Callback)(void) = NULL;

// Đăng ký hàm callback
void RegisterCallback(void (*fp)(void))
{   
    // Lưu vào UART_Callback
    UART_Callback = fp; 
}

// Yêu cầu/ Kích hoạt callback
void tx_UART_Handler(void)
{
    if(UART_Callback == NULL)
    {
        return;
    }

    UART_Callback();
}

int main ()
{   
    // Đăng ký hàm, truyền param
    RegisterCallback(tx_UART_Transmit);
    // Truyền 14c4 vào 


    tx_UART_Handler();


    return 0;
}