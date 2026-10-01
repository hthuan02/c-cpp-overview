#include <stdio.h>

int main ()
{
    int x = 10;
    int y = 5;

    int a = x--;    //x=10      a=10
    int b = ++y;    //x=9 y=6   b=6

    x++;    //x=9
    y--;    //x=10 y=6

    int c = --x; //y=5 x=9      c=9
    int d = y++; //y=5          d=5

    int e = x + y + a + b + c + d; //y=6  //9+6+10+6+9+5
    return 0;   
}