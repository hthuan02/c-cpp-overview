/**
 * Tìm 1 ký tự trong chuỗi
 */
#include <stdio.h>
#include <string.h>



int main()
{   
    char s1[] = "Deviot.vn";
    char ch;

    printf("Tìm ký tự: ");
    scanf("%c",&ch);

    char *str = strchr(s1,ch);

    printf("Ký tự '%c', vị trí %d ",*str,str-s1);
    return 0;
}   