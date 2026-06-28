// thêm/xóa/sửa mảng
#include <stdio.h>

/** Thêm
 * index --> dịch trái
 * 
 * for(i++)
 *      arr[i] = arr[i+1];
 * 
 * - giảm kích thước mảng
 */

int main ()
{
    int arr[10] = {11,32,43,54,25,75,245,64};
    int n = 10, index, var;
    
    printf("Nhập index: ");     scanf("%d", &index);
    printf("Nhập variables: "); scanf("%d", &var);    

    arr[index] = var;
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    
    




    return 0;
}