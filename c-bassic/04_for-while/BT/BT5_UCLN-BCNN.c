#include <stdio.h>

int main()
{
    int a=18, b=12, x, y, r, UCLN, BCNN;

    // printf("Nhập a, b: ");
    // scanf("%d %d", &a, &b);

    // Lưu lại giá trị ban đầu để tính BCNN sau
    x = a;
    y = b;

    // Thuật toán Euclid tìm UCLN
    /***************************************************
    *   Nếu b != 0 và a,b > 0 thì:
    *       UCLN(a,b) = UCLN(b,a mod b)
    *   và:
    *       khi b = 0, UCLN(a,b) = a
    **************************************************/
    
    while (b != 0) 
    {   
        // 15 % 75 == ? = r 

        r = a % b; // biến tạm để lưu giá trị dư
        a = b;
        b = r;
    }

    UCLN = a;             
    BCNN = (x * y) / UCLN;

    printf("UCLN(%d, %d) = %d\n", x, y, UCLN);
    printf("BCNN(%d, %d) = %d\n", x, y, BCNN);

    return 0;
}
