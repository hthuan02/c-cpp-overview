// In 1->10 từ số 3,7,9

#include <stdio.h>

int main()
{
    for(int i = 1; i<=10; i++)
    {
        if(i == 3){
            continue;
        }

        else if(i == 7){
            continue;
        }
        
        else if(i == 9){
            continue;
        }
        printf("%d\n",i);
    }
}