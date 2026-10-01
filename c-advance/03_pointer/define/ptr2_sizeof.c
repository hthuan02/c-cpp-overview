#include <stdio.h>

int main ()
{
    int arr[] = {1,2,3,4,5};
    int *ptr = arr;

    // Nó trả về kiểu size_t --> %zu là định dạng đúng
    printf("%zu\n", sizeof(*ptr));      // là int -> 4
    printf("%zu\n", sizeof(ptr));       // là int * -> con trỏ 8
    printf("%zu\n", sizeof(arr));       // là 5 * sizeof(int) = 5 *4
    printf("%zu\n", sizeof(&arr));      // là int (*)[5] -> con trỏ trỏ đến mảng 5 ptử int = 8
    printf("%zu\n", sizeof(&arr[0]));   // là int *
    printf("%zu\n", sizeof(arr[0]));    // là int = 4
    printf("%zu\n", sizeof(arr[1]));    // 4
      
    // | Biểu thức | Kiểu         |
    // | --------- | ------------ |
    // | `arr`     | `int *`      |
    // | `&arr[0]` | `int *`      |
    // | `&arr`    | `int (*)[5]` |


    return 0;
}