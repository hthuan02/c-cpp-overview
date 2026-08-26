// in ra số chẵn 1-> 100, tới số 10 thì break
#include<stdio.h>

int main ()
{
    int i =0;
    while (i <= 100)
    {   
        i++;
        if(i%2!=0){
            continue;
        }
        if(i>10){
            break;
        }

        printf("%d\n",i);
        
    }
}