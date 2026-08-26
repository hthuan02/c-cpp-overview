#include <stdio.h>
#include <string.h>

int main()
{
    char s1[5] = "Thuan";
    char s2[] = "123456789"; // char[]: kích thước tự động tính theo chuỗi khởi tạo
    char s3[7] ="Huynh";
    char s4[] = ".vn";


    strcpy(s1,s2);
    strcpy(&s3[5],s4);
    
    printf("%s\n",s1);
    printf("%s\n",s3);

    return 0;
}