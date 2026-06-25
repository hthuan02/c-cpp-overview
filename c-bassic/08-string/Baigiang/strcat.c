#include <stdio.h>
#include <string.h>

int main()
{
    char s1[] = "Thuan"; //char[]: kích thước tự động tính theo chuỗi khởi tạo
    char s2[] = "123";

    strcat(s1,s2);
    
    printf("%s\n",s1);


    return 0;
}