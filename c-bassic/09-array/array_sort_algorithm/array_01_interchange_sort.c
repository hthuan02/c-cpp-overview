/** TĂNG DẦN
 *  13 53 65 25 6 
 * 
 * TH1: i < n
 *  -> i = 0, 13 & [53 65 25 6] ==> Lặp 4 lần, số nào bé hoán vị ra trước
 *  -> i = 1, 53 & [65 25 6] ==> Lặp 3 lần, hoán vị
 *  -> i = 2, 65 & [25 6] ==> Lặp 2 lần, hoán vị
 *  -> i = 3, 25 & [6] ==> Lặp 1 lần, hoán vị
 *  -> i = 4, hết giá trị để lặp, 0 lần
 * 
 * TH2: i < n-1
 *  -> i = 0, 13 & [53 65 25 6] ==> Lặp 4 lần, số nào bé hoán vị ra trước
 *  -> i = 1, 53 & [65 25 6] ==> Lặp 3 lần, hoán vị
 *  -> i = 2, 65 & [25 6] ==> Lặp 2 lần, hoán vị
 *  -> i = 3, 25 & [6] ==> Lặp 1 lần, hoán vị
 *  ==> Không có i = 4, AN TOÀN - ĐÚNG THUẬT TOÁN 
 * 
 *  GIẢI THÍCH CÁCH KHÁC:
 *  n-1 vì phần từ cuối cùng không cần so sánh, còn 1 phần tử mặc nhiên nó đã được sắp xếp rồi. 
 *
 *  Sắp xếp trực tiếp: So sánh arr[i] với tất cả số phía sau. Hoán vị ngay khi thấy số nhỏ hơn
 *
 */

#include <stdio.h>

void hoan_vi (int *x, int *y)
{
    int temp;
    if (*x > *y)
    {
        temp = *x;
        *x = *y;
        *y = temp;
    }
    
}

int main ()
{
    int arr[] = {11,34,76,45,99,102,35,25,56};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n-1; i++) 
    {
        for (int j = i + 1; j < n; j++)
        {
            hoan_vi(&arr[i],&arr[j]);
        }
        
    }

    printf("arr[] = {");
    for (int i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
        if (i < n -1) printf(", ");
        
    }
    printf("}");
    
    

    return 0;
}