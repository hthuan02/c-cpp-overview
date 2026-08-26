#include <stdio.h>
#include <string.h>

int main()
{
    char s1[] = "Thuan";
    char s2[] = "thuan";
    int sosanh = strcmp(s1,s2);
    
    if (sosanh > 0)
        printf("s1 > s2\n");
    
    else if (sosanh < 0)
        printf("s1 < s2\n");

    else 
        printf("s1 = s2\n");    


    return 0;
}