#include <stdio.h>
#include <string.h>

int main ()
{
    char *s1 = "Thuan";
    char val = 'a';
    char *s = strchr(s1, val);

    if (s != NULL)
    {
        printf("Tìm thấy kí tự: %c\n", val);
        printf("Vị trí: %d\n", s-s1);
    }
    else printf("Không tìm thấy kí tự!\n");
    

    return 0;
}
