#include <stdio.h>

int tong3soTN(int a, int b, int c)
{
    int result;
    result = a + b + c;
    return result; // Hàm trả về mà không return có thể nhận giá trị rác hoặc giá trị ngẫu nhiên
}

int main ()
{   
    int res;    // Tạo biến res để gán, giữ lại giá trị return
    res = tong3soTN(12,14,20);
    
    printf("Tổng 3 số: %d + %d + %d = %d\n",12,14,20,res);
    return 0;
}