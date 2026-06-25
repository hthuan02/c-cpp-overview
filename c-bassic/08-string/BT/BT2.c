/**
 *  Nhập vào 1 chuỗi và nhập vào ký tự cần tìm
 *  -> Trả về các vị trí của ký tự đó trong chuỗi.
 *
 *  - Nhập chuỗi có khoảng trắng _ fgets()
 *  - Tìm ký tự or chuỗi _ strstr()
 *  
 */

#include <stdio.h>
#include <string.h>

int main()
{
    char s1[100];
    char s2[20];
    printf("Nhập vào ký tự hoặc chuỗi: ");

    fgets(s1,sizeof(s1),stdin);
    s1[strcspn(s1,"\n")] = '\0';

    // printf("Chuỗi vừa nhập: %s\n",s1);
    printf("Tìm ký tự: ");
    fgets(s2,sizeof(s2),stdin);
    s2[strcspn(s2,"\n")] = '\0';

    char *str = strstr(s1,s2);

    if(str)
        printf("Đã tìm thấy ký tự '%s', vị trí %d\n",s2,str-s1);
    
    else
        printf("Không tìm thấy ký tự.\n");

    return 0;
}