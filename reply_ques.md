# Level 1
# 1.
1. p địa chỉ x
2. *p lưu giá trị của x = 10
3. giá trị sau cùng 20

# 2.
2 địa chỉ giống nhau
&x là địa chỉ x
p là địa chỉ con trỏ trỏ đến x = &x

# 3.
x vẫn = 10, p = NULL nên không trỏ đến x

# 4.
giải tham chiếu con trỏ *p = 4, còn &x = là địa chỉ của x -> giải tham chiếu = *p = 4

# Level 2
# 5. 
*(p+2) = 30

# 6. 
là 4 byte vì arr[5] là mảng kiểu int, nên mỗi phần tử lưu giá trị vào vùng nhớ 4 byte

# 7.
khoảng cách mỗi vùng nhớ là 1 byte, bài trên là 4 byte

# 8.

```c
for (int i = 0;i < 5; i++)
{
    printf("%d\n", p[i]);
}
```
# Level 3
# 9. 
arr = &arr[0]

# 10.

int arr[5];
sizeof(arr) = 20; // Kích thước mảng: 5 (số phần  tử) * 4(data_type) = 20


int *arr[5]
sizeof(&arr) = 5; // Kích thước số phần tử 5

# 11. 
không tính được kích thước đúng của mảng, vì parameter là con trỏ (truyền tham chiếu) - nên sizeof tính theo kích thước pointer, phụ thuộc vào kiến trúc máy tính hoặc compiler = 8 byte

# Level 4
# 12.

```c
typedef struct
{
    int id;
    float temp;
}Sensor_t;

Sensor_t sensor;
Sensor_t *p = &sensor;

// Truy cập temp
p->temp = 20;
(*p).temp
```
# 13. 

`p -> temp` = `(*p).temp`

# 14.
```c
Sensor_t arr[10];
Sensor_t *p = arr;

// lấy địa chỉ phần tử thứ 5
p + 4 
&arr[4]

// truy cập temp phần tử thứ 5
(p+4) -> temp
arr[4].temp
(*(p+4)).temp

```
# Level 5
# 15.
khai báo ptr đến func_sum
int (*fp)(int, int) = sum;

# 16.
fp(a,b);
(*fp)(a,b);

# 17. 
int (*fp)(int, int);

đây là còn trỏ hàm tên `fp` có kiểu trả về int, parameter là 2 data_type kiểu int

# 18.
func_ptr làm nhiệm vụ là parameter

```c
#include <stdio.h>
int sum (int a, int b)
{
    return a+b;
}

int sub(int a, int b)
{
    return a-b;
}

int mul(int a, int b)
{
    return a*b;
}

int calculator(int a, int b, int(*fp)(int, int))
{
    return fp(a,b);
}

int main ()
{   
    int a = 10;
    int b = 20;

    calculator(a,b, sum);
    calculator(a,b, sub);
    calculator(a,b, mul);

    return 0;
}
```


```c
int arr[5];
int *p = arr;

sizeof(int) = 4
sizeof(arr) = 20 -> 5*sizeof(int)
sizeof(&arr) = 8 -> kiểu int (*)[5]
sizeof(&arr[0]) = 8
sizeof(arr[0])=4 -> kiểu int
sizeof(p) = 8 -> kiểu int *
sizeof(*p) = 4 -> kiểu int

// arr, &arr[0], &arr
giống nhau: địa chỉ và giá trị

nhưng sizeof tính khác nhau
arr -> 20
arr[0] -> 4, tính theo data_type int
&arr -> 8, theo data_type int *
 
khi + 1
arr + 1 -> 0x00 -> 0x04
&arr + 1 -> 0x00 -> 0x14
&arr[0] + 1 -> 0x00 -> 0x04

```