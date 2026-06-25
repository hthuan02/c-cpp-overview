// 0 - 20

#include<stdio.h>

int main ()
{   
    int i = 1;
    while(i <= 20)                  
    {   
        if(i%2!=0)
        {
            printf("%d\n",i);
    
        }
        i++; // Để biến đếm ở phía sau

    }
}
// Nếu để biến đếm ở phía trước, i = 0
// Nếu để biến đếm ở phía sau, i = 1