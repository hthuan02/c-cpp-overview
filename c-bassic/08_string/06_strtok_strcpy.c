#include <stdio.h>
#include <string.h>

int main ()
{   
    char s1[30] = "Huynh Minh Thuan";
    char ho[10],
         chulot[10],
         ten[10];
    int index = 0;

    char *token = strtok(s1, " ");

    while (token != NULL)
    {
        if (index == 0)
        {
            strcpy(ho, token);
        }

        else if (index == 1)
        {
            strcpy(chulot, token);
        }

        if (index == 2)
        {
            strcpy(ten, token);
        }
        
        index++;
        token = strtok(NULL, " ");
    }
    
    printf("Họ: %s\n", ho);
    printf("Chữ lót: %s\n", chulot);
    printf("Tên: %s\n", ten);


    return 0;
}