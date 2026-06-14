#include <stdio.h>

int main ()
{
    int arr[] = {0x00, 0x01, 0x02, 0x03, 0x04};
    int *ptr = arr;

    // Truy cập giá trị của mảng
    printf("%d\n", *(ptr+1));
    printf("%d\n", arr[1]);
    printf("%d\n", ptr[1]);

    // Truy cập địa chỉ của mảng
    printf("%p\n", (ptr + 0)); 
    printf("%p\n", (ptr + 1)); // tăng lên 4 byte vì kiểu int
    printf("%p\n", (ptr + 2));

    printf("\n");
    printf("%p\n", &arr[0]);
    printf("%p\n", &arr[1]);
    printf("%p\n", &arr[2]);


    
    /** Nhắc lại kiến thức về mảng
     * 
     *  - `arr` là tên mảng cũng là phần đầu tien của mảng `arr[0]` 
     *  --> Nếu `arr + 1` thì địa chỉ của mảng dịch lên 1 phần tử `int` 4 byte
     * 
     *  - `&arr` là đại diện cho toàn bộ mảng `arr[]`
     *  --> Nếu `&arr + 1` thì địa chỉ của mảng dịch 20 byte (kích thước của mảng)
     */

    // int arr[5];

    // printf("%p\n", arr);      // 0x1000
    // printf("%p\n", arr + 1);  // 0x1004

    // printf("%p\n", &arr);     // 0x1000
    // printf("%p\n", &arr + 1); // 0x1014

    printf("%p\n", &arr[0]);
    printf("%p\n", arr); 
    printf("%p\n", &arr);
    printf("\n");

    /** Các cách truy cập mảng
     *  arr[i] = *(arr + i) =  i[arr]  
     */
    printf("%d\n", arr[2]);
    printf("%d\n", 2[arr]);
    printf("%d\n", *(arr + 2));


    return 0;
}