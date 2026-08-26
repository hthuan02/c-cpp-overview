/**
 *  Nhập vào 1 chuỗi đổi các ký tự thường thành chữ cái in hoa và ngược lại
 */


#include <stdio.h>
#include <string.h>
#include <ctype.h>

void nhapChuoi(char s1[], int size)
{
    printf("Nhập chuỗi: ");
    fgets(s1,size,stdin);
    s1[strcspn(s1,"\n")] = '\0';

}

void chuyenChuThuong_InHoa(char s1[])
{
    for(int i = 0;i < strlen(s1);i++)
    {
        if(isupper(s1[i]))
            s1[i] = tolower(s1[i]);
        
        else if(islower(s1[i]))
            s1[i] = toupper(s1[i]);
    }
}

int main ()
{
    char s1[100];

    nhapChuoi(s1,sizeof(s1));

    chuyenChuThuong_InHoa(s1);
    printf("Chuỗi mới: %s\n",s1);
    return 0;
}