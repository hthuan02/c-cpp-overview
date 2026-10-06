/** HÀM CALLBACK CƠ BẢN GỒM
 *  1. Hàm sử dụng callback 
 *  2. func_ptr để lưu callback
 *  3. Hàm đăng ký callback
 *  4. Hàm kích hoạt/yêu cầu thực thi callback
 */

#include <stdio.h>

// Hàm sử dụng cho callback
int sum(int a, int b)
{
    return a+b;
}

// *fp để lưu callback
static int (*Callback_Sum)(int, int) = NULL;

// Đăng ký callback
void RegisterCallback(int (*fp)(int, int))
{
    Callback_Sum = fp;
}

// Trigger callback execute/Hàm yêu cầu callback thực thi
int SUM(int a, int b)
{
    if (Callback_Sum == NULL)
    {
        return -1;
    }
    
    return Callback_Sum(a,b);
}

int main ()
{
    RegisterCallback(sum);
    printf("%d\n", SUM(1,2));

    return 0;
}