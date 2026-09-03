#include <stdio.h>
#include <string.h>

int main ()
{
    char s1[50] = "HUYNH MINH THUAN";
    char ch = 'T';
    
    char *val_find_char = strchr(s1, ch);
    if (val_find_char != NULL)
    {
        printf("Found character: %c\n", ch);
        printf("Position: %d\n", val_find_char - s1);
    }
    else printf("Cant find character!\n");
    

    return 0;
}