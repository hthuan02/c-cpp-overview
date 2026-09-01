#include <stdio.h>

int main ()
{
    int arr[] = {11,24,21,53,75,35,45,1};
    int n = sizeof(arr) / sizeof(arr[0]);

    // for(i = 0) i < n -1 --> trừ ra được phần tử cuối (ptu cuối mặc định đã đc sắp xếp rồi)
    //      for(j = 1)
    //          hoán vị

    // 1 2 3 4 5 6
    // [1] vs [2 3 4 5 6] --> for(j = i)

    for (int i = 0; i < n -1; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (arr[i] > arr[j])
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