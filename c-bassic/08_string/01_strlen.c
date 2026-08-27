#include <stdio.h>
#include <string.h>

int main ()
{
    char *arr = "ThuanNe";
    
    printf("Length: %d\n", strlen(arr));    //7
    printf("Size: %d\n", sizeof(arr));      //8 (tính luôn '\0')


    return 0;
}