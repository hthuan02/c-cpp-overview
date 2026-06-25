#include <stdio.h>
#include <string.h>

int main()
{
    char s[] = "Thuan"; // Kích thước của chuỗi được tính tự động theo mảng khởi tạo
    int dodai = strlen(s);
    
    printf("Độ dài chuỗi là: %d",dodai);
    return 0;
}