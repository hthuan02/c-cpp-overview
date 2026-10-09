// callback cơ bản
// 1. Tạo hàm xử lý, dùng cho callback
// 2. Tạo *fp = NULL
// 3. Đăng ký callback, gán *regis_fp vào *fp
// 4. Hàm thực thu callback, check NULL

#include <stdio.h>

// Hàm xử lý, dùng cho callback
int sum (int a, int b)
{
    return a+b;
}

// Tạo *fp cho callback
static int (*Callback_Sum)(int, int) = NULL;

// Đăng ký callback
void RegisterCallback_Sum(int (*fp)(int, int))
{
    Callback_Sum = fp;
}

// Hàm yêu cầu thực thi callback, kiểm tra null
int SumHandler(int a, int b)
{
    if (Callback_Sum == NULL)
    {
        return -1;
    }
    
    return Callback_Sum(a,b);
}

int main ()
{
    RegisterCallback_Sum(sum);

    SumHandler(1,2);


    return 0;
}