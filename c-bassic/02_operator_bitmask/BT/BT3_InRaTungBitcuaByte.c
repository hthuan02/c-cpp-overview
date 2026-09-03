#include<stdio.h>
#include<string.h>

int main()
{

    unsigned char x = 0b11101110;
    unsigned char y;

    for(int i = 7;i >= 0;i--)
    {   
        y = ((1 << i) & x) != 0;
        printf("Bit %d: %d\n",i,y);
    }

    return 0;
}

