
#include <stdio.h>
#include <string.h>

int main ()
{
    char s1[50] = "HUYNH MINH THUAN";
    char *s2 = "THUAN";
    
    char *val_find_char = strstr(s1, s2);
    if (val_find_char != NULL)
    {
        printf("Found character: %s\n", s2);
        printf("Position: %d\n", val_find_char - s1);
    }
    else printf("Cant find character!\n");
    

    return 0;
}