// Thêm phần tử mảng

/**
 *  1,2,3,4,5 
 *  0 1 2 3 4 
 *  --> Thêm 111 vào index = 2
 * 
 *  1 2 3 [index = 2] 4 5
 *  
 * --> dịch phải, dịch từ vị trí index qua phải 1 đơn vị
 * for (i--)
 *  arr[i] = arr[i - 1]
 * 
 * ==> Để thêm mảng thì phải tăng kích thước mảng ++, phải khai báo mảng có kích thước cụ thể arr[100], arr[50], arr[10],...
 * ==> Trong EMBEDDED lỗi nghiêm trọng, không có kích thước cụ thể thì compiler không biết cấp phát bộ nhớ kích thước bn byte trên RAM
 * 
 */

#include <stdio.h>

int main ()
{
    int arr[10] = {11,24,13,64,866,98};
    int index, var, n=6;
    // Cách làm này bị kẹt "cứng" giá trị n=6, cách fix lầ tạo for tự nhập mảng

    printf("Nhập vị trí thêm (index): "); scanf("%d", &index);
    printf("Nhập giá trị (variable): ");  scanf("%d", &var);

    for (int i = 10; i > index; i--)
    {
        arr[i] = arr[i-1]; 
    }
    arr[index] = var;
    n++;  

    // in mảng
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    n++;
    




    return 0;
}