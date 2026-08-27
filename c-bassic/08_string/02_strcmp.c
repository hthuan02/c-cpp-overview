#include <stdio.h>
#include <string.h>

int main ()
{
    char *s1 = "ThuanNe";
    char *s2 = "Thuan";

    int s = strcmp(s1,s2);
    if (s>0)
    {
        printf("s1>s2");
    }
    else if (s < 0)
    {
        printf("s1 < s2");
    }
    else
    {
        printf("s1=s2");
    }

    return 0;
}