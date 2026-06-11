#include <stdio.h>

int main ()
{
    int arr[] = {1,2,3,4,5};
    int *ptr = arr;

    // Toán tử sizeof (tính kích thước) không trả về kiểu dữ liệu thông thường: int, float, double,...
    // Nó trả về kiểu size_t --> %zu là định dạng đúng
    printf("%zu\n", sizeof(*ptr)); // tính kích thước của giá trị mà con trỏ trỏ tới: 4
    printf("%zu\n", sizeof(ptr));  // tính kích thước của con trỏ: 8
    printf("%zu\n", sizeof(arr));  // kích thước mảng: <data_type> * <element_number> = 4 * 5
    printf("\n");
    
    return 0;
}