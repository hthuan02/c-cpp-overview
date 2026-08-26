// Nhập vào thông tin (tên, tuổi, sđt) và in ra 3 thông tin trên.
#include<stdio.h>

char ten[30];
int tuoi;
char sdt[20]; 

void nhapthongtinCaNhan(void)
{
    printf("Nhập thông tin cá nhân:\n");
    printf("Nhập tên: ");
    scanf("%s",ten);

    printf("Nhập tuổi: ");
    scanf("%d",&tuoi);

    printf("Nhập sđt: ");
    scanf("%s",sdt); //scanf với %s không cần ký tự &
}

void inthongtinCaNhan(void)
{
    printf("*******************\n");
    printf("Họ & tên: %s\n",ten);
    printf("Tuổi: %d\n",tuoi);
    printf("Sđt: %s\n",sdt);

}

int main ()
{
    nhapthongtinCaNhan();
    inthongtinCaNhan();
    return 0; 
    // fget(): Nhập vào chuỗi có khoảng cách
    // Để khắc phục warning get(): Tìm hiểu fget(), getchar()
}