/* REMOVE DUPLICATE, ARRAY CHƯA ĐƯỢC XẾP -> GIỮ NGUYÊN ARRAY*/
// Dùng biến cờ `val_new`
// For thứ 2 cố tình để không duyệt được -> Lấy phần tử đầu trong các phần tử trùng

#include <stdio.h>

int main ()
{
    int arr[] = {11,34,23,23,76,11,34,67,99};
    int n = sizeof(arr) / sizeof(arr[0]);
    int val_new = 0;

    for (int i = 0; i < n; i++)
    {
        int duplicate_flag = 0;
        for (int j = 0; j < val_new; j++)
        {
            if (arr[i] == arr[j])
            {
                duplicate_flag = 1;
                break;
            }
            
        }

        if (duplicate_flag == 0)
        {
            arr[val_new] = arr[i]; // val_new = 0
            val_new++;             // val_new = 1
        }
        
    }

    for (int i = 0; i < val_new+1; i++)
    {
        printf("%d ", arr[i]);
    }
    
    


    return 0;
}