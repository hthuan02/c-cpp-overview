# TỔNG ÔN LẠI TOÀN BỘ C 

## 1. Pointer
- khái niệm?
- ptr - variables?
VD: int *ptr = &a;
- ptr - array?
VD: 
```c
int arr[] = {0x00,0x01,0x02,0x3};
int *ptr = arr;

// Giá trị - %d
// *ptr = arr[0];
// *(ptr + 1) = arr[1];
// *(ptr + 2) = arr[2];

// Ngoài ra
// arr[2] = 2[arr] = *(arr+2);

// Địa chỉ - %p
// ptr = &arr[0];
// (ptr+1) = &arr[1];
// (ptr+2) = &arr[2];
```
- ptr - size?
```c
int arr[] ={0x00, 0x01, 0x02, 0x03};
int *ptr = arr;

printf("%d\n",sizeof(ptr));  // 8, kích thước con trỏ
printf("%d\n",sizeof(*ptr)); // 4, kích thước của 1 biến giá trị trong mảng
printf("%d\n",sizeof(arr));  // 16, kích thước của mảng
```
- ptr - decrease/increase operator?
int arr[] ={0x00, 0x01, 0x02, 0x03};
int *ptr = arr; 

- phân loại: void ptr, func ptr, const to ptr, ptr const, ptr to ptr, null
X_void ptr?

X_func ptr? call back? isr?

ptr to ptr, null --> linked list: ÔN CÁI NÀY....