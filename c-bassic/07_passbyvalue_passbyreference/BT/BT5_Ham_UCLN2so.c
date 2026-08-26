/**
 * Viết hàm tìm USCLN của 2 số nguyên
 * 
 * UCLN(a,b) 
 *   Khi b != 0, a và b > 0 
 *          -> a = b; b = a mod b
 * 
 *   Khi a == 0 -> Thoát 
 * 
 * BCNN(a,b) = (a * b) / UCLN, (a,b là giá trị ban đầu)
 * 
 */

#include <stdio.h>

void nhap2so(int *a, int *b)
{
    printf("Nhập 2 số a,b:\n");
    scanf("%d%d",a,b);
}

int uocSoChung_LN(int a, int b)
{   
    int r; // 12 // 16
    while(b != 0)
    {   
        r = a % b; //12     //4     //0
        a = b;     //16     //12    //4
        b = r;     //12     //4     //0 -> thoát
    }

    return a;
}

int main()
{
    int a,b,UCLN, BCNN;

    nhap2so(&a, &b);
    int x = a, y = b; // Nhập a,b rồi mới có giá trị gán vào x,


    UCLN = uocSoChung_LN(a,b);
    printf("USCLN(%d,%d) = %d\n",x,y,UCLN);

    BCNN = (x * y) / UCLN;
    printf("BSCNN(%d,%d) = %d\n",x,y,BCNN);

    return 0;
}