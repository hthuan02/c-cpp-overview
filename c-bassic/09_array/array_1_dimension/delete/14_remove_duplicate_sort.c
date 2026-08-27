#include <stdio.h>

int main ()
{
    int arr[] = {1,1,2,3,4,4,5};
    int n = sizeof(arr) / sizeof(arr[0]);

    int k = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[k] != arr[i])
        {   
            k++;
            arr[k] = arr[i];
        }
        
    }
    
    for (int i = 0; i < k+1; i++)
    {
        printf("%d ", arr[i]);
    }
    
    return 0;
}