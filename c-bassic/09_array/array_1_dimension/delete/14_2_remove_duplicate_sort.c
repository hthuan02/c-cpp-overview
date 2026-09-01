/* REMOVE DUPLICATE, ARRAY CHƯA ĐƯỢC XẾP -> SORT LẠI TOÀN BỘ */

#include <stdio.h>

int main ()
{
    int arr[] = {100,33,33,45,23,53,45,15};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Xóa phần tử trùng nhau với arr chưa xếp
    // B1: Sắp xếp tăng dần
    // - duyệt 2 for
    // - hoán vị

    // B2: xét phần tử arr[0] và arr[1]
    // VD: 1 2 3 4 5 6 -> Xét 1 vs 2, 
    // - Nếu khác k++, arr[0] = arr[1]
    // - Giống thì k làm gì, chỉ lấy phần tử trước

    // Kết quả: mảng đã được sắp xếp


    for (int i = 0; i < n-1; i++)
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
    
    // 1 2 3 4 5 6
    // ^  --> 1 là int k
    //   ^ --> 2 là for(int i
    //                  arr[k] != arr[i] -> k++ (nếu ==, lấy thằng đầu bỏ cuối)

    int k = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[k]!=arr[i])
        {
            k++;
            arr[k] = arr[i];
        }
        
    }

    printf("-------------\n");
    for (int i = 0; i < k + 1; i++)
    {
        printf("%d ", arr[i]);
    }
    
    

    

    return 0;
}