#include <stdio.h>
#include <string.h>

int main()
{
    char s1[] = "Huynh Minh Thuan hoc lop DH20TD ne!";
    char s2[] = "20TD"; //s1[], s2[] Kích thước của mảng tự động đc tính theo chuỗi được khai báo

    // Tìm vị trí của chuỗi"20TD" của s2 trong s1
    char *str = strstr(s1,s2); // trả về địa chỉ của chuỗi s2 trong s1

    printf("%c\n",s1[27]);

    if(str) // hoặc if(str != NULL)
    {
        printf("Đã tìm thấy chuỗi %s, địa chỉ %p\n",s2,str);
        // s2 là địa chỉ gốc (%s)
        // str là địa chị của s2 trong s1(%p)

        printf("Tại vị trí: %d\n",str-s1); 
        // str địa chỉ sau
        // s1 địa chỉ đầu tiên
    }
    else 
    {
        printf("Không tìm thấy!.");
    }

    return 0;
}