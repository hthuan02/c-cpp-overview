#include <stdio.h>

int main ()
{
    int arr[] = {1,2,2,3,3,3,4,5,5};
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

    // k xem như là index -> k + 1 để duyệt new_arr
    for (int i = 0; i < k+1; i++)
    {
        printf("%d ", arr[i]);
    }
    
    


    return 0;
}