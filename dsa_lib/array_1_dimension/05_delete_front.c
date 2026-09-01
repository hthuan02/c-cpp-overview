#include <stdio.h>

int main ()
{
    int arr[] = {11,24,21,53,75,35,45,1};
    int n = sizeof(arr) / sizeof(arr[0]);

    // dịch trái
    // n--
    for (int i = 0; i < n; i++)
    {
        arr[i] = arr[i + 1];
    }
    n--;
    

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    
    return 0;
}