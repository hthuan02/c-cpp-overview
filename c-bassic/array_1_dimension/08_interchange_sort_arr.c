#include <stdio.h>

int main ()
{
    int arr[] = {1,23,13,54,25,76};
    int n = sizeof(arr) / sizeof(arr[0]);

    // duyệt arr for (i < n-1) --> n-1 để đúng với algorithm
    // duyệt arr nhỏ for(j < n)
    for (int i = 0; i < n -1; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (arr[i] < arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
            
        }
        
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    
    
    return 0;
}