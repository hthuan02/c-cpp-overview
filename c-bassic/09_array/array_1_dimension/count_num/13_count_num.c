#include <stdio.h>

int main ()
{   
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int count_even = 0, // số chẵn
        count_odd = 0,  // số lẻ
        sum_even,
        sum_odd;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 0)
        {
            count_even++;
            sum_even += arr[i];
        }
        else if (arr[i] % 2 != 0)
        {
            count_odd++;
            sum_odd += arr[i];
        }
        
    }

    printf("Số chẵn(even): %d\n", count_even);
    printf("Tổng giá trị phần tử chẵn: %d\n", sum_even);
    printf("Số lẻ (Odd): %d\n", count_odd);
    

    return 0;
}