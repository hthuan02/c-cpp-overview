#include <stdio.h>
#include <string.h>

int main ()
{
    char *s1 = "THUAN";
    char s2[] = "THUAN";

    printf("length s1: %d\n", strlen(s1)); //5
    printf("Sizeof s1: %d\n", sizeof(s1)); // 8, vì ptr tính size theo kiến trúc máy tính 64 bit

    printf("length s2: %d\n", strlen(s2)); // 5
    printf("sizeof s2: %d\n", sizeof(s2)); // 6


    return 0;
}