/**
 *  Tìm kí tự nhập từ bàn phím trong chuỗi "Deviot.vn" và trả về vị trí của nó trong chuỗi "Deviot.vn"
 * 
 */

#include <stdio.h>
#include <string.h>

int main()
{
    char s1[] = "Deviot.vn";
    char s2[2];

    printf("Nhập ký tự: ");
    fgets(s2,sizeof(s2),stdin);
    s2[strcspn(s2,"\n")] = '\0';

    char *str = strstr(s1,s2);

    if(str)
    {
        printf("Tìm thấy ký tự %s, vị trí %d.\n",s2,str-s1);
    }

    else
        printf("Không tìm thấy ký tự.\n");

    return 0;
}