// Tìm Max của 3 số a b c được nhập từ bàn phím 
#include<stdio.h>

int main()
{
    int a,b,c,max,min;
    printf("Nhập 3 số a,b,c: \n");
    scanf("%d %d %d",&a, &b, &c);

    // max = (a > b) ? ((a > c) ? a : c)
    //               : ((b > c) ? b : c);

    // max = (a > b) ? ((a > c) ? a : c)
    //               : ((c > b) ? c : b);

    max = (b>c) ? ((b>a)?b:a)
                : ((a>c)?a:c);

    min = (a<b) ? ((a<c)?a:c)
                : ((b<c)?b:c);

    printf("Max = %d\n",max);
    printf("Min = %d\n",min);
}