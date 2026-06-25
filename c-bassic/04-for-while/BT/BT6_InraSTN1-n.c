// STN: > 1, Chia hết cho 1 và chính nó
// 2 3 5 7 11 13 15

#include <stdio.h>
#include <stdbool.h>

int main ()
{
    int n=10;

    // printf("Nhập n: ");
    // scanf("%d", &n);
    for(int i = 1 ; i <= n; i++)        
    {
        if(i >=2)                     //i=1; 2; 3; 4; 5; 6; 7....
        {   
            bool laSTN = true;
            for (int j=2; j < i; j++) // j=2-cấp thoát; 2-cấp thoát; 2-break-cấp thoát; 2-lặp tiếp(3-4)-cấp thoát;
            {                         // j=2-cấp thoăt; 2-lặp tiếp(3)....
                if (i % j == 0){
                    laSTN = false;
                    break;
                }
            }
            if (laSTN == true){
                printf("%d\n",i); // in 2; in 3; 5; 7...

            }
  
        }

    }
}