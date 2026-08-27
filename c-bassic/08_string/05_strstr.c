#include <stdio.h>
#include <string.h>

int main ()
{
    char *s1 = "Thuan";
    char *s2 = "an";
    char *s = strstr(s1, s2);

    if (s != NULL)
    {
        printf("Tìm thấy chuỗi: %s\n", s);
        printf("Vị trí: %d\n", s-s1);
    }
    else printf("Không tìm thấy kí tự!\n");
    

    return 0;
}
