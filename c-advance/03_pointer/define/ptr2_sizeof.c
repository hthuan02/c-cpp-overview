#include <stdio.h>

int main ()
{
    int arr[] = {1,2,3,4,5};
    int *ptr = arr;

    // Nó trả về kiểu size_t --> %zu là định dạng đúng
    printf("%zu\n", sizeof(*ptr)); // lấy kích thước data_type mà con trỏ đang trỏ tới: 4
    printf("%zu\n", sizeof(ptr));  // kích thước con trỏ: 8 
    printf("%zu\n", sizeof(arr));  // kích thước mảng: <data_type> * <element_number> = 4 * 5
    printf("\n");
    
    return 0;
}