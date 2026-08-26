// Nhập và in ra thông tin cá nhân (tên, tuổi, sđt )
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ten[30];
    char sdt[20];
    int tuoi;

    printf("Nhập các thông tin sao:\n");
    printf("Nhập tên: ");
    gets(ten);

    printf("Nhập tuổi: ");
    scanf("%d",&tuoi);

    printf("Nhập sđt: ");
    scanf("%s",&sdt);

    printf("*************\n");
    printf("Tên: %s\n",ten);
    printf("Tuổi: %d\n",tuoi);
    printf("Sđt: %s\n",sdt);
    return 0;
}