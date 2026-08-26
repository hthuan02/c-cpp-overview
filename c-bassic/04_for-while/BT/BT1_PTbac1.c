// Giải phương trình bậc I

#include<stdio.h>   

int main()
{
    int a,b;
    printf("Cho phương trình: ax + b = 0\n");
    // x+b =

    printf("Nhập a,b:\n");
    scanf("%d %d",&a, &b);
    
    printf("PT: %dx + %d = 0\n",a,b);
    if(a == 0)
    {
        if(b == 0)
            printf("PT vô số nghiệm!\n");
        else
            printf("PT vô nghiệm!\n");
    }
    else
        printf("PT có 1 nghiệm: x = %d\n",-b/a);
}