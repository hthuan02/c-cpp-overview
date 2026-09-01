#include <stdio.h>
#include <string.h>

int main ()
{
    char s1[100] = {0};

    printf("Nhập chuỗi:");
    fgets(s1, sizeof(s1), stdin);
    s1[strcspn(s1, "\n")] = '\0';

    printf("%s\n", s1);


    return 0;
}