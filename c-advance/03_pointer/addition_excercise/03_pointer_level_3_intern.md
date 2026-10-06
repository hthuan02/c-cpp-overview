# Pointer Level 3 — Intern

> Bộ 30 bài tập Pointer Level 3.
>
> Nội dung: pointer làm tham số hàm, pointer arithmetic, NULL/null pointer, `void *`, `const` + pointer, pointer-to-pointer, array of pointers vs pointer to array và bài tổng hợp.
>
> **Function pointer chưa nằm trong Level 3; dành cho Level 4.**

---

# Nhóm 1 — Pointer làm tham số hàm

# Câu 1 — Basic

```c
#include <stdio.h>

void change(int *p)
{
    *p = 20;
}

int main()
{
    int x = 10;

    change(&x);

    printf("%d\n", x);

    return 0;
}
```

**Hỏi:** Output là gì? Giải thích vì sao `x` thay đổi.

---

# Câu 2 — Pointer parameter

```c
#include <stdio.h>

void add_one(int *p)
{
    (*p)++;
}

int main()
{
    int x = 10;

    add_one(&x);
    add_one(&x);

    printf("%d\n", x);

    return 0;
}
```

**Hỏi:** Output?

---

# Câu 3 — Hai pointer

```c
#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int x = 10;
    int y = 20;

    swap(&x, &y);

    printf("%d %d\n", x, y);

    return 0;
}
```

**Hỏi:** Output? Giải thích từng bước.

---

# Câu 4 — Pointer + array

```c
#include <stdio.h>

void print_array(int *p, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", *(p + i));
    }
}

int main()
{
    int arr[] = {10, 20, 30, 40};

    print_array(arr, 4);

    return 0;
}
```

**Hỏi:** Vì sao truyền `arr` vào hàm lại có thể nhận bằng `int *p`?

---

# Nhóm 2 — Pointer arithmetic

# Câu 5

```c
#include <stdio.h>

int main()
{
    int arr[] = {10, 20, 30, 40, 50};

    int *p = arr;

    printf("%d\n", *p);
    printf("%d\n", *(p + 2));
    printf("%d\n", *(p + 4));

    return 0;
}
```

**Hỏi:** Output?

---

# Câu 6

```c
#include <stdio.h>

int main()
{
    int arr[] = {10, 20, 30, 40};

    int *p = &arr[3];

    printf("%d\n", *p);
    printf("%d\n", *(p - 2));

    return 0;
}
```

---

# Câu 7

```c
#include <stdio.h>

int main()
{
    int arr[] = {10, 20, 30, 40, 50};

    int *p = arr;

    p += 3;

    printf("%d\n", *p);

    p--;

    printf("%d\n", *p);

    return 0;
}
```

---

# Câu 8 — Pointer difference

```c
#include <stdio.h>
#include <stddef.h>

int main()
{
    int arr[] = {10, 20, 30, 40, 50};

    int *p1 = &arr[1];
    int *p2 = &arr[4];

    printf("%td\n", p2 - p1);

    return 0;
}
```

**Hỏi:** Output là gì?

**Bonus:** Vì sao không phải `12` hoặc `3 * sizeof(int)`?

---

# Nhóm 3 — `NULL` / Null Pointer

# Câu 9 — Basic NULL

```c
#include <stdio.h>

int main()
{
    int *p = NULL;

    if (p == NULL)
    {
        printf("NULL\n");
    }

    return 0;
}
```

**Hỏi:** Output?

**Bonus:** `p = NULL` có nghĩa là gì?

---

# Câu 10

```c
#include <stdio.h>

int main()
{
    int *p = NULL;

    printf("%p\n", (void *)p);

    return 0;
}
```

**Hỏi:** Code này có hợp lệ không?

---

# Câu 11 — Cực kỳ quan trọng

```c
#include <stdio.h>

int main()
{
    int *p = NULL;

    printf("%d\n", *p);

    return 0;
}
```

**Hỏi:** Code này có an toàn không? Có output xác định không? Vì sao?

---

# Câu 12 — NULL check

```c
#include <stdio.h>

void set_value(int *p)
{
    if (p != NULL)
    {
        *p = 100;
    }
}

int main()
{
    int x = 10;

    set_value(&x);
    set_value(NULL);

    printf("%d\n", x);

    return 0;
}
```

**Hỏi:** Output? Tại sao `set_value(NULL)` không làm chương trình dereference `NULL`?

---

# Câu 13

```c
#include <stdio.h>

void set_value(int *p)
{
    *p = 100;
}

int main()
{
    set_value(NULL);

    return 0;
}
```

**Hỏi:** Vấn đề nằm ở đâu?

---

# Nhóm 4 — `void *`

# Câu 14

```c
#include <stdio.h>

int main()
{
    int x = 10;

    void *p = &x;

    printf("%d\n", *(int *)p);

    return 0;
}
```

**Hỏi:** Vì sao phải cast `p` thành `(int *)` trước khi dereference?

---

# Câu 15

```c
#include <stdio.h>

int main()
{
    int x = 10;

    void *p = &x;

    *(int *)p = 20;

    printf("%d\n", x);

    return 0;
}
```

**Hỏi:** Output?

---

# Câu 16 — Sai kiểu dữ liệu

```c
#include <stdio.h>

int main()
{
    int x = 10;

    void *p = &x;

    printf("%f\n", *(float *)p);

    return 0;
}
```

**Hỏi:** Có vấn đề gì với code này?

---

# Câu 17 — Generic function

```c
#include <stdio.h>

void set_int(void *p)
{
    *(int *)p = 50;
}

int main()
{
    int x = 10;

    set_int(&x);

    printf("%d\n", x);

    return 0;
}
```

**Hỏi:** Output? `void *` ở đây có tác dụng gì?

---

# Nhóm 5 — `const` + pointer

# Câu 18

```c
int x = 10;
const int *p = &x;
```

**Hỏi:** Dòng nào hợp lệ?

```c
*p = 20;
```

hay:

```c
p = NULL;
```

Giải thích.

---

# Câu 19

```c
int x = 10;
const int *p = &x;

x = 20;

printf("%d\n", *p);
```

**Hỏi:** Output?

---

# Câu 20

```c
int x = 10;
int y = 20;

const int *p = &x;

p = &y;
```

**Hỏi:** Code có hợp lệ không?

---

# Câu 21

```c
int x = 10;

int *const p = &x;
```

**Hỏi:** Hai dòng dưới đây, dòng nào hợp lệ?

```c
*p = 20;
```

```c
p = NULL;
```

---

# Câu 22 — Phân biệt

Giải thích sự khác nhau giữa:

```c
const int *p;
```

```c
int *const p = &x;
```

```c
const int *const p = &x;
```

Bạn phải trả lời được:

> Cái gì không được thay đổi trong từng trường hợp?

---

# Nhóm 6 — Pointer-to-pointer `**`

# Câu 23 — Basic

```c
#include <stdio.h>

int main()
{
    int x = 10;

    int *p = &x;
    int **pp = &p;

    printf("%d\n", x);
    printf("%d\n", *p);
    printf("%d\n", **pp);

    return 0;
}
```

**Hỏi:** Ba dòng `printf` cho ra gì?

---

# Câu 24

```c
#include <stdio.h>

int main()
{
    int x = 10;

    int *p = &x;
    int **pp = &p;

    **pp = 50;

    printf("%d\n", x);

    return 0;
}
```

**Hỏi:** Vì sao `x` thay đổi?

---

# Câu 25 — Thay đổi pointer

```c
#include <stdio.h>

int main()
{
    int x = 10;
    int y = 20;

    int *p = &x;
    int **pp = &p;

    *pp = &y;

    printf("%d\n", *p);
    printf("%d\n", x);
    printf("%d\n", y);

    return 0;
}
```

**Hỏi:** Output?

**Đây là câu rất quan trọng:** `*pp = &y` thay đổi **data** hay thay đổi **p**?

---

# Nhóm 7 — Array of pointers vs pointer to array

# Câu 26

```c
int *p[3];
```

**Hỏi:** `p` là:

A. Pointer tới array 3 phần tử  
B. Array gồm 3 pointer  
C. Pointer tới pointer  
D. Array gồm 3 integer

---

# Câu 27

```c
int (*p)[3];
```

**Hỏi:** `p` là gì?

A. Array gồm 3 pointer  
B. Pointer tới array gồm 3 `int`  
C. Pointer tới `int`  
D. Pointer-to-pointer

---

# Câu 28

```c
#include <stdio.h>

int main()
{
    int arr[3] = {10, 20, 30};

    int (*p)[3] = &arr;

    printf("%d\n", (*p)[0]);
    printf("%d\n", (*p)[2]);

    return 0;
}
```

**Hỏi:** Output?

**Bonus:** Vì sao phải dùng `(*p)[0]` thay vì `*p[0]`?

---

# Nhóm 8 — Tổng hợp Intern

# Câu 29

```c
#include <stdio.h>

void update(int **pp)
{
    static int value = 100;

    *pp = &value;
}

int main()
{
    int x = 10;

    int *p = &x;

    update(&p);

    printf("%d\n", *p);

    return 0;
}
```

**Hỏi:** Output?

Giải thích chính xác:

```text
p
↓
pp
↓
value
```

---

# Câu 30 — Tổng hợp

```c
#include <stdio.h>

void process(int *p)
{
    if (p == NULL)
    {
        return;
    }

    (*p)++;
    p++;
    (*p)++;
}

int main()
{
    int arr[] = {10, 20, 30};

    process(arr);

    printf("%d %d %d\n",
           arr[0],
           arr[1],
           arr[2]);

    return 0;
}
```

**Hỏi:** Output?

Đặc biệt giải thích 4 phần:

```c
if (p == NULL)
```

```c
(*p)++;
```

```c
p++;
```

```c
(*p)++;
```

