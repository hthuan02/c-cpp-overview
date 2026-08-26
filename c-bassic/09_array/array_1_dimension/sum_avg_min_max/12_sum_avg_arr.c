#include <stdio.h>

int main ()
{   
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 0,
        avg = 0,
        count = 0;
   
    // sum
    for (int i = 0; i < n; i++)
    {
        sum += arr[i]; 
        count++;
    }
    printf("%d\n",sum);
    printf("%d\n", count);
    printf("%d\n", sum/count);

    

    return 0;
}