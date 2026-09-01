#include <stdio.h>

int main ()
{
    int arr[] = {11,24,21,53,75,35,45,1};
    int n = sizeof(arr) / sizeof(arr[0]);

    // dịch phải for(i--) arr[i] = arr[i -1]
    // n++
    // arr[0] = val_new
    int val_new =1234;
    for (int i = n; i > 0; i--)
    {
        arr[i] = arr[i-1];
    }
    arr[0] = 1234;
    n++;

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    

    

    return 0;
}