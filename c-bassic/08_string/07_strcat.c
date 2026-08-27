#include <stdio.h>
#include <string.h>

int main ()
{
    char arr1[30] = "Huynh ";
    char arr2[10] = "Thuan";
    
    printf("%s\n", strcat(arr1, arr2));

    return 0;
}