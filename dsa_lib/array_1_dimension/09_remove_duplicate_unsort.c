#include <stdio.h>

int main ()
{
    int arr[] = {1,2,243,2,63,4,63,5};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Tạo biến ghi giá trị không duplicate val_new
    // for(i)
    //      -> tạo biến cờ = 0
    //      for(j) j < val_new
    //          if(arr[i] == arr[j]) -> cờ = 1; break;
    //      if( cờ = 0)
    //          val_new++
    
    int val_new = 0;

    for (int i = 0; i < n; i++)
    {
        int val_duplicate_flags = 0;
        for (int j = 0; j < val_new; j++)
        {
            if (arr[i] == arr[j])
            {
                val_duplicate_flags = 1;
                break;
            }
            
        }

        if (val_duplicate_flags == 0)
        {
            arr[val_new] = arr[i];
            val_new++;
        }
    }

    for (int i = 0; i < val_new; i++)
    {
        printf("%d ", arr[i]);
    }
    
    

    
    return 0;
}