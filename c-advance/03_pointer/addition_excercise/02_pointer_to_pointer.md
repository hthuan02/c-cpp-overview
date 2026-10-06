# Bài tập Pointer-to-Pointer (`**`) trong C

> Tập trung vào `int **`, nhiều mức dereference, thay đổi dữ liệu thông qua `**pp`, thay đổi chính pointer thông qua `*pp`, NULL safety và cấp phát động.

---

# Nhóm 1 — Nhận biết cấp pointer

# Câu 1

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

---

# Câu 2

```c
int x = 10;

int *p = &x;
int **pp = &p;
```

**Hỏi:**

- `p` chứa gì?
- `&p` là gì?
- `pp` chứa gì?
- `*pp` là gì?
- `**pp` là gì?

---

# Câu 3

```c
#include <stdio.h>

int main()
{
    int x = 100;

    int *p = &x;
    int **pp = &p;

    printf("%p\n", (void *)&x);
    printf("%p\n", (void *)p);
    printf("%p\n", (void *)*pp);

    return 0;
}
```

**Hỏi:** Các địa chỉ nào giống nhau?

---

# Nhóm 2 — Thay đổi dữ liệu qua `**pp`

# Câu 4

```c
#include <stdio.h>

int main()
{
    int x = 10;

    int *p = &x;
    int **pp = &p;

    **pp = 200;

    printf("%d\n", x);

    return 0;
}
```

---

# Câu 5

```c
#include <stdio.h>

int main()
{
    int x = 10;

    int *p = &x;
    int **pp = &p;

    (*p)++;
    **pp += 10;

    printf("%d\n", x);

    return 0;
}
```

---

# Câu 6 — `(*pp)++` hay `(**pp)++`?

```c
#include <stdio.h>

int main()
{
    int x = 10;

    int *p = &x;
    int **pp = &p;

    (*pp)++;

    printf("%d\n", x);

    return 0;
}
```

**Hỏi:** Code này có hợp lệ về mặt cú pháp/ý nghĩa không? `(*pp)++` đang tăng cái gì?

---

# Câu 7

```c
#include <stdio.h>

int main()
{
    int x = 10;

    int *p = &x;
    int **pp = &p;

    (**pp)++;

    printf("%d\n", x);

    return 0;
}
```

**Hỏi:** So sánh `(*pp)++` và `(**pp)++`.

---

# Nhóm 3 — Thay đổi chính pointer

# Câu 8

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

**Hỏi:** `*pp = &y` làm thay đổi `x`, `y`, hay `p`?

---

# Câu 9

```c
#include <stdio.h>

int main()
{
    int x = 10;
    int y = 20;

    int *p = &x;
    int **pp = &p;

    *pp = &y;

    **pp = 50;

    printf("%d %d\n", x, y);

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

    int *p = &x;
    int **pp = &p;

    *pp = &y;
    *p = 100;

    printf("%d %d\n", x, y);

    return 0;
}
```

---

# Nhóm 4 — Pointer-to-pointer trong function

# Câu 11

```c
#include <stdio.h>

void set_value(int **pp)
{
    static int value = 100;

    *pp = &value;
}

int main()
{
    int x = 10;
    int *p = &x;

    set_value(&p);

    printf("%d\n", *p);

    return 0;
}
```

---

# Câu 12

```c
#include <stdio.h>

void change(int **pp)
{
    **pp = 500;
}

int main()
{
    int x = 10;
    int *p = &x;

    change(&p);

    printf("%d\n", x);

    return 0;
}
```

---

# Câu 13 — Vì sao cần `**`?

```c
#include <stdio.h>

void allocate(int **p)
{
    *p = (int *)malloc(sizeof(int));
}

int main()
{
    int *p = NULL;

    allocate(&p);

    return 0;
}
```

**Hỏi:**

1. Vì sao truyền `&p`?
2. Vì sao function nhận `int **`?
3. `*p` trong function là gì?
4. Sau `allocate(&p)`, `p` có thể chứa gì?

---

# Câu 14 — Hoàn thiện chương trình

Hoàn thiện function:

```c
void allocate(int **p)
{
    // TODO
}
```

để chương trình sau hoạt động:

```c
#include <stdio.h>
#include <stdlib.h>

void allocate(int **p)
{
    // TODO
}

int main()
{
    int *p = NULL;

    allocate(&p);

    if (p != NULL)
    {
        *p = 100;
        printf("%d\n", *p);
    }

    free(p);

    return 0;
}
```

---

# Nhóm 5 — NULL safety

# Câu 15

```c
#include <stdio.h>

int main()
{
    int **pp = NULL;

    if (pp == NULL)
    {
        printf("NULL\n");
    }

    return 0;
}
```

---

# Câu 16

```c
#include <stdio.h>

int main()
{
    int *p = NULL;
    int **pp = &p;

    printf("%p\n", (void *)*pp);

    return 0;
}
```

**Hỏi:** Có an toàn không?

---

# Câu 17

```c
#include <stdio.h>

int main()
{
    int *p = NULL;
    int **pp = &p;

    **pp = 100;

    return 0;
}
```

**Hỏi:** Lỗi nằm ở đâu?

---

# Câu 18 — NULL check đúng cách

```c
void set_value(int **pp)
{
    if (pp == NULL)
    {
        return;
    }

    if (*pp == NULL)
    {
        return;
    }

    **pp = 100;
}
```

**Hỏi:** Tại sao cần kiểm tra cả:

```c
pp == NULL
```

và:

```c
*pp == NULL
```

?

---

# Nhóm 6 — Theo dõi nhiều mức

# Câu 19

```c
#include <stdio.h>

int main()
{
    int x = 10;

    int *p = &x;
    int **pp = &p;

    *p = 20;
    **pp = 30;

    printf("%d\n", x);

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
    int y = 20;

    int *p = &x;
    int **pp = &p;

    **pp = 100;
    *pp = &y;
    **pp = 200;

    printf("%d %d\n", x, y);

    return 0;
}
```

**Hãy vẽ trạng thái của `p` sau từng dòng.**

---

# Nhóm 7 — Interview / Embedded C

# Câu 21

Phân biệt:

```c
*p
```

```c
*pp
```

```c
**pp
```

với:

```c
&x
&p
&pp
```

---

# Câu 22

Cho:

```c
int x = 10;
int *p = &x;
int **pp = &p;
```

Viết biểu thức để:

1. Đổi `x` thành `100`.
2. Đổi `p` để nó trỏ tới biến `y`.
3. Đọc giá trị của `x` thông qua `pp`.
4. Đọc địa chỉ của `p` thông qua `pp`.

---

# Câu 23

Cho:

```c
int x = 10;
int *p = &x;
int **pp = &p;
```

Hãy xác định biểu thức nào tác động lên:

- `x`
- `p`
- `pp`

trong các biểu thức:

```c
*p = 20;
```

```c
*pp = NULL;
```

```c
**pp = 30;
```

```c
pp = NULL;
```

---

# Câu 24 — Debug

Tìm lỗi:

```c
#include <stdio.h>
#include <stdlib.h>

void allocate(int **pp)
{
    pp = malloc(sizeof(int *));
}

int main()
{
    int *p = NULL;

    allocate(&p);

    *p = 100;

    printf("%d\n", *p);

    free(p);

    return 0;
}
```

**Hỏi:** Vì sao cách cấp phát trong `allocate()` không làm `p` nhận địa chỉ vùng nhớ mong muốn?

---

# Câu 25 — Tổng hợp

```c
#include <stdio.h>
#include <stdlib.h>

void allocate(int **pp)
{
    *pp = malloc(sizeof(int));

    if (*pp != NULL)
    {
        **pp = 123;
    }
}

int main()
{
    int *p = NULL;

    allocate(&p);

    if (p != NULL)
    {
        printf("%d\n", *p);
    }

    free(p);

    return 0;
}
```

**Hãy giải thích toàn bộ luồng:**

```text
p
↓
&p
↓
pp
↓
*pp
↓
**pp
```

và giải thích tại sao `free(p)` là đúng.

