// Xóa phần tử trong mảng

/** 
 *  12 3 4 54 2
 *  0  1 2  3 4 
 * 
 *  --> index = 2
 *  --> delete 4 --> mảng bị thu nhỏ
 *  
 *  ==> Dịch trái
 *  for (i ++)
 *      arr[i] = arr[i+1]
 * 
 *  n-- (giảm phần tử mảng)
 * 
 * 
 */


#include <stdio.h>

int main ()
{
    int arr[10] = {11,3,43,24,65,45,87};
    int n = 7, index;

    printf("Nhập vị trí xóa: "); scanf("%d", &index);

    for (int i = index; i < n; i++)
    {
        arr[i] = arr[i + 1];
    }
    n--;

    // In mảng đã xóa
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}