#include <stdio.h>
#include <string.h>

int main ()
{
    char s1[50] = "HUYNH MINH THUAN";
    char sur_name[10],
         mid_name[10],
         first_name[10];
    unsigned char index =0;

    char *separate_s1 = strtok(s1, " ");

    while (separate_s1 != NULL)
    {   
        if (index == 0) strcpy(sur_name, separate_s1);
        else if (index == 1) strcpy(mid_name, separate_s1);
        else if (index == 2) strcpy(first_name, separate_s1);
        index++;
        separate_s1 = strtok(NULL, " ");
    }

    printf("Your surname: %s\n", sur_name);
    printf("Your midname: %s\n", mid_name);
    printf("Your firstname: %s\n", first_name);

    return 0;
}