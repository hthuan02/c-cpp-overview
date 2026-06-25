// Tính tổng bình phương các số lẻ từ 1 đén n
// S = 1^2 + 2^2 + 3^2 + ... + n^2, Với n nhập từ bàn phím
// C1: dùng for, C2: Dùng while


#include <stdio.h>

// int main()
// {
//     int n, S = 0;
//     printf("Nhập n: ");
//     scanf("%d", &n);
//     for(int i = 1; i <= n; i++)
//     {
//         if(i%2 == 0){
            
//             continue;
//         }

//         printf("%d\n",i);
//         S = S + i*i;
        
       
//     }
//      printf("S = %d\n",S);
// }

int main()
{
    int i = 0;
    int S = 0,n;
    printf("Nhập n: ");
    scanf("%d",&n);

    while(i <= n)
    {
        i++;
        if(i % 2 == 0)
        {
            continue;
        }
        
        printf("i = %d\n",i);
        S = S +i*i;
        
    }
    printf("Tổng = %d",S);

}