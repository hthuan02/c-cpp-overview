# Bài tập toán tử tăng giảm `++/--` và con trỏ trong C

> Bộ bài tập luyện `++`, `--`, tiền tố, hậu tố và cách chúng kết hợp với pointer/array.
>
> **Quy tắc:** Tự làm trước, chưa xem đáp án. Với mỗi câu hãy ghi cả **output** và **trạng thái cuối của biến/con trỏ** nếu có.

---

# Nhóm 1 — Tiền tố và hậu tố cơ bản

# Câu 1 — Postfix increment

```c
#include <stdio.h>

int main()
{
    int x = 10;
    int y = x++;

    printf("x = %d\n", x);
    printf("y = %d\n", y);

    return 0;
}
```

**Hỏi:** Output?

---

# Câu 2 — Prefix increment

```c
#include <stdio.h>

int main()
{
    int x = 10;
    int y = ++x;

    printf("x = %d\n", x);
    printf("y = %d\n", y);

    return 0;
}
```

---

# Câu 3 — Postfix decrement

```c
#include <stdio.h>

int main()
{
    int x = 10;
    int y = x--;

    printf("x = %d\n", x);
    printf("y = %d\n", y);

    return 0;
}
```

---

# Câu 4 — Prefix decrement

```c
#include <stdio.h>

int main()
{
    int x = 10;
    int y = --x;

    printf("x = %d\n", x);
    printf("y = %d\n", y);

    return 0;
}
```

---

# Câu 5 — Prefix/postfix trong phép cộng

```c
#include <stdio.h>

int main()
{
    int x = 10;
    int y;

    y = x++ + 5;

    printf("x = %d\n", x);
    printf("y = %d\n", y);

    return 0;
}
```

---

# Câu 6 — Prefix trong phép cộng

```c
#include <stdio.h>

int main()
{
    int x = 10;
    int y;

    y = ++x + 5;

    printf("x = %d\n", x);
    printf("y = %d\n", y);

    return 0;
}
```

---

# Câu 7 — Postfix decrement

```c
#include <stdio.h>

int main()
{
    int x = 10;
    int y = x-- - 3;

    printf("x = %d\n", x);
    printf("y = %d\n", y);

    return 0;
}
```

---

# Câu 8 — Prefix decrement

```c
#include <stdio.h>

int main()
{
    int x = 10;
    int y = --x - 3;

    printf("x = %d\n", x);
    printf("y = %d\n", y);

    return 0;
}
```

---

# Nhóm 2 — Kết hợp hai biến

# Câu 9

```c
#include <stdio.h>

int main()
{
    int x = 10;
    int y = 20;

    int z = x++ + y;

    printf("%d %d %d\n", x, y, z);

    return 0;
}
```

---

# Câu 10

```c
#include <stdio.h>

int main()
{
    int x = 10;
    int y = 20;

    int z = ++x + y;

    printf("%d %d %d\n", x, y, z);

    return 0;
}
```

---

# Câu 11

```c
#include <stdio.h>

int main()
{
    int x = 10;
    int y = 20;

    int z = x + y++;

    printf("%d %d %d\n", x, y, z);

    return 0;
}
```

---

# Câu 12

```c
#include <stdio.h>

int main()
{
    int x = 10;
    int y = 20;

    int z = x + ++y;

    printf("%d %d %d\n", x, y, z);

    return 0;
}
```

---

# Câu 13

```c
#include <stdio.h>

int main()
{
    int x = 10;
    int y = 20;

    int z = x++ + ++y;

    printf("%d %d %d\n", x, y, z);

    return 0;
}
```

---

# Câu 14

```c
#include <stdio.h>

int main()
{
    int x = 10;
    int y = 20;

    int z = ++x + y++;

    printf("%d %d %d\n", x, y, z);

    return 0;
}
```

---

# Câu 15

```c
#include <stdio.h>

int main()
{
    int x = 10;
    int y = 20;

    int z = x-- + --y;

    printf("%d %d %d\n", x, y, z);

    return 0;
}
```

---

# Câu 16

```c
#include <stdio.h>

int main()
{
    int x = 10;
    int y = 20;

    int z = --x + y--;

    printf("%d %d %d\n", x, y, z);

    return 0;
}
```

---

# Nhóm 3 — Nhiều bước và theo dõi trạng thái

# Câu 17

```c
#include <stdio.h>

int main()
{
    int x = 5;
    int y;

    y = x++;
    y += ++x;

    printf("x = %d\n", x);
    printf("y = %d\n", y);

    return 0;
}
```

---

# Câu 18

```c
#include <stdio.h>

int main()
{
    int x = 5;

    x++;
    ++x;
    x--;
    --x;

    printf("%d\n", x);

    return 0;
}
```

---

# Câu 19

```c
#include <stdio.h>

int main()
{
    int x = 5;
    int a = x++;
    int b = ++x;
    int c = x--;
    int d = --x;

    printf("%d %d %d %d %d\n", x, a, b, c, d);

    return 0;
}
```

---

# Câu 20

```c
#include <stdio.h>

int main()
{
    int x = 10;

    x = x++ + 1;

    printf("%d\n", x);

    return 0;
}
```

**Hỏi:** Code này có vấn đề gì theo chuẩn C?

---

# Nhóm 4 — 16 tổ hợp prefix/postfix giữa hai biến

> Với các câu dưới đây, tập trung vào việc phân biệt **giá trị được sử dụng** và **giá trị sau khi tăng/giảm**.

# Câu 21

```c
int x = 10;
int y = 20;

int z = ++x + ++y;
```

---

# Câu 22

```c
int x = 10;
int y = 20;

int z = ++x + y++;
```

---

# Câu 23

```c
int x = 10;
int y = 20;

int z = ++x + y--;
```

---

# Câu 24

```c
int x = 10;
int y = 20;

int z = ++x + ++y;
```

**Hỏi:** So sánh với câu 21 nếu đổi phép toán thành:

```c
int z = ++x - ++y;
```

---

# Câu 25

```c
int x = 10;
int y = 20;

int z = x++ + ++y;
```

---

# Câu 26

```c
int x = 10;
int y = 20;

int z = x++ + y++;
```

---

# Câu 27

```c
int x = 10;
int y = 20;

int z = x++ - y++;
```

---

# Câu 28

```c
int x = 10;
int y = 20;

int z = x-- + --y;
```

---

# Câu 29

```c
int x = 10;
int y = 20;

int z = --x + y--;
```

---

# Câu 30

```c
int x = 10;
int y = 20;

int z = x-- - --y;
```

---

# Câu 31

```c
int x = 10;
int y = 20;

int z = --x - y--;
```

---

# Câu 32

```c
int x = 10;
int y = 20;

int z = x++ * ++y;
```

---

# Câu 33

```c
int x = 10;
int y = 20;

int z = ++x * y++;
```

---

# Câu 34

```c
int x = 10;
int y = 20;

int z = x-- / --y;
```

---

# Câu 35 — Interview

```c
int x = 10;
int y = 20;

int z = x++ + y++ + ++x + ++y;
```

**Hỏi:** Code này có được phép kết luận output theo cách đọc trái → phải không? Phân tích theo chuẩn C.

---

# Nhóm 5 — Pointer + `++/--`

# Câu 36

```c
#include <stdio.h>

int main()
{
    int arr[] = {10, 20, 30};
    int *p = arr;

    printf("%d\n", (*p)++);

    return 0;
}
```

---

# Câu 37

```c
#include <stdio.h>

int main()
{
    int arr[] = {10, 20, 30};
    int *p = arr;

    printf("%d\n", ++(*p));

    return 0;
}
```

---

# Câu 38

```c
#include <stdio.h>

int main()
{
    int arr[] = {10, 20, 30};
    int *p = arr;

    printf("%d\n", *p++);
    printf("%d\n", *p);

    return 0;
}
```

---

# Câu 39

```c
#include <stdio.h>

int main()
{
    int arr[] = {10, 20, 30};
    int *p = arr;

    printf("%d\n", *++p);

    return 0;
}
```

---

# Câu 40

```c
#include <stdio.h>

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int *p = arr;

    printf("%d\n", *p++);
    printf("%d\n", *p++);
    printf("%d\n", *p);

    return 0;
}
```

---

# Câu 41

```c
#include <stdio.h>

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int *p = arr;

    printf("%d\n", (*p)++);
    printf("%d\n", (*p)++);
    printf("%d\n", *p);

    return 0;
}
```

---

# Câu 42

```c
#include <stdio.h>

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int *p = arr;

    printf("%d\n", ++(*p));
    printf("%d\n", ++(*p));
    printf("%d\n", *p);

    return 0;
}
```

---

# Câu 43

```c
#include <stdio.h>

int main()
{
    int arr[] = {10, 20, 30};
    int *p = arr;

    int a = (*p)++;
    int b = *p++;

    printf("%d %d %d\n", a, b, *p);

    return 0;
}
```

---

# Câu 44

```c
#include <stdio.h>

int main()
{
    int arr[] = {10, 20, 30};

    int *p = arr;

    int a = *p++;
    int b = (*p)++;
    int c = *p;

    printf("%d %d %d\n", a, b, c);

    return 0;
}
```

---

# Câu 45 — Tổng hợp

```c
#include <stdio.h>

int main()
{
    int arr[] = {10, 20, 30, 40};
    int *p = arr;

    int a = ++(*p);
    int b = *++p;
    int c = (*p)++;

    printf("%d %d %d\n", a, b, c);
    printf("%d %d %d %d\n",
           arr[0], arr[1], arr[2], arr[3]);

    return 0;
}
```

**Mục tiêu:** Phân biệt hoàn toàn:

```c
++(*p)
*p++
(*p)++
*++p
```

