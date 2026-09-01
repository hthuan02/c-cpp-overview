#include <stdio.h>
#include <string.h>

int main ()
{
    char s1[50] = "HUYNH MINH THUAN";
    char *s2 = " DH20TD";

    printf("%s\n", strcat(s1,s2));

    return 0;
}