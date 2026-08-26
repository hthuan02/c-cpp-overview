// Giải phương trình bậc II

#include<stdio.h>   
#include<math.h>
#include<complex.h>

int main()
{
    double a,b,c;
    double phanThuc, phanAo;
    double delta, x1, x2;
    printf("Cho phương trình: ax^2 + bx + c = 0\n");

    printf("Nhập a,b,c:\n");
    scanf("%lf %lf %lf",&a, &b, &c);
    
    printf("PT: %0.2lfx^2 %+0.2lfx %+0.2lf = 0\n",a,b,c);
    if(a == 0)
    {
        if(b == 0)
            if (c == 0)
                printf("PT vô số nghiệm!\n");
            else    
                printf("PT vô nghiệm!\n");
        else
            printf("PT có 1 nghiệm: x = %lf\n",-b/a); 
    }
    else
    {
        delta = b*b - 4*a*c;
        if(delta < 0)
        {   
            phanThuc = -b/(2*a);
            phanAo   = sqrt(abs(delta))/(2*a);

            printf("PT có 2 nghiệm phức:\n");
            printf("x1 = %0.3lf + %0.3lfi\n", phanThuc,phanAo);
            printf("x2 = %0.3lf - %0.3lfi\n", phanThuc,phanAo); 
        }

        else if(delta == 0)
            printf("PT có nghiệm kép: x = %d",-b/(2*a));
        
        else
        {   
            x1 = (-b + sqrt(delta))/(2*a);
            x2 = (-b - sqrt(delta))/(2*a);

            printf("PT có 2 nghiệm phân biệt:\n");
            printf("x1 = %0.3lf\n", x1);
            printf("x2 = %0.3lf\n", x2); 
        }
    }
}