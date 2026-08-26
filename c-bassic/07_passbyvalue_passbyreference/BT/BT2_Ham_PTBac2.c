/**
 * PT Bậc 2 dùng hàm 
 * Dùng float return được 1 nghiệm, thiếu 1 nghiệm -> cách khắc phục là dùng struct
 * Vì vậy, dùng hàm hàm void() không return
 */

#include <stdio.h>
#include <math.h>

/* Hàm nhập 3 số a,b,c */
void nhap3so(float *a, float *b, float *c)
{
    printf("Nhập 3 số a,b,c:\n");
    printf("a = "); scanf("%f",a);
    printf("b = "); scanf("%f",b);
    printf("c = "); scanf("%f",c);

    printf("PT: %.2gx^2 %+.2gx %+.2g = 0\n", *a, *b, *c); // +%g có thể bị dấu + - dư      // %+g
}

/* Hàm giải PT bậc 1 */
void giaiPTbac1(float b, float c)
{   
    float x;
    if(b == 0)
    {
        if (c == 0)
            printf("PT vô số nghiệm!\n");
        else    
            printf("PT vô nghiệm!\n");
    }
    
    else
    {
        x = -c / b;
        printf("PT có nghiệm duy nhất: x = %g\n", x);

    }
}
/* Hàm giải PT bậc 2 */
void giaiPTbac2(float a, float b, float c)
{
    float x1, x2, phanThuc, phanAo;
    float delta = b*b - 4*a*c;


    if(delta < 0)
    {   
        phanThuc = -b/(2*a);
        phanAo   = sqrt(fabs(delta))/(2*a); // abs() -> int //fabs -> float

        printf("PT có 2 nghiệm phức:\n");
        printf("x1 = %g + %gi\n", phanThuc,phanAo);
        printf("x2 = %g - %gi\n", phanThuc,phanAo); 
    }

    else if(delta == 0)
        printf("PT có nghiệm kép: x = %g",-b/(2*a));
    
    else
    {   
        x1 = (-b + sqrt(delta))/(2*a);
        x2 = (-b - sqrt(delta))/(2*a);

        printf("PT có 2 nghiệm phân biệt:\n");
        printf("x1 = %g\n", x1);
        printf("x2 = %g\n", x2); 
    }

}

int main ()
{
    float a,b,c;

    nhap3so(&a, &b, &c);

    if (a == 0) 
        giaiPTbac1(b,c);
    
    else 
        giaiPTbac2(a,b,c);

    return 0;
}