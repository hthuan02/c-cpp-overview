/**
 *  Nhập 1 chuỗi và đếm số lần xuất hiện của 1 ký tự đc nhập từ bàn phím.
 */

#include <stdio.h>
#include <string.h>

void nhapChuoi(char s1[], int size)
{   
    printf("Nhập chuỗi:");
    fgets(s1,size,stdin);
    s1[strcspn(s1, "\n")] = '\0';
}

char timKyTu()
{   
    char kytu;
    printf("Tìm ký tự: ");
    scanf("%c",&kytu);
    return kytu;
}

int demKyTu(char s1[], char KQ)
{
    int index = 0;
    for(int i = index;i < strlen(s1);i++)
    {
        if(s1[i] == KQ)
            index++;
    }

    return index;
}

int main ()
{
    char s1[100];
    char KQ, SoLan;

    nhapChuoi(s1,sizeof(s1));

    KQ = timKyTu();

    SoLan = demKyTu(s1,KQ);
    printf("Số lần xuất hiện ký tự '%c' là %d\n", KQ, SoLan);



    return 0;
}