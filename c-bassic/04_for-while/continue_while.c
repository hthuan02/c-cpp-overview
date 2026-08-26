// In ra các số chẵn 1-> 10

#include<stdio.h>

int main ()
{       
    int i = 0;
    while( i <= 10)
    {   
        i++;
        if(i % 2 == 0){
            continue;
        }
        printf("%d\n",i);
        // Nếu để i tăng dưới này, thì nó chưa kịp tăng thì gián đoạn r
        
    }
}