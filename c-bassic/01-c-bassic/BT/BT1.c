// BT1: Viết chưonwg trình nhập vào 3 giá trị và in ra tổng bình phương của 3 số đó

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,c,S;

    printf("Nhập lần lượt 3 số a, b, c:\n");
    scanf("%d%d%d",&a,&b,&c);
    
    S=a*a+b*b+c*c;
    printf("Tổng bình phương của 3 số: %d\n",S);
    return 0;


}