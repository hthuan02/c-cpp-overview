#include<stdio.h>

int main()
{
    int giave;
    int tuoi_nguoixem;
    
    printf("Nhập tuổi người xem: ");
    scanf("%d",&tuoi_nguoixem);

    giave = (tuoi_nguoixem>18)? 100000:39999;
    printf("Giá vé là: %d\n", giave);

    return 0;
}