# Roadmap to Learning C Programming
---

<details>
  <summary><h3>Lesson 1: Basics of C Progamming  </h3></summary>

## 1. IDE, Text Editor, Complier ?

-> Quá trình Complier?

## 2. Byte & Bit

## 3. Data types

> Xác định kích thước số byte của biến đó.
>
> Giúp xác định giá trị 1 biến có thể nhận hoặc giá trị 1 hàm có thể trả về.

### 3.1 Interger 

| Type           | Kích thước (byte) | Phạm vi giá trị                                         |
|----------------|-------------------|----------------------------------------------------------|
| `char`         | 1                 | -128 tới 127                                             |
| `unsigned char`| 1                 | 0 tới 255                                                |
| `int`          | 2 or 4            | -32,768 tới 32,767 hoặc -2,147,483,648 tới 2,147,483,647 |
| `unsigned int` | 2 or 4            | 0 tới 65,535 hoặc 0 tới 4,294,967,295                    |
| `short`        | 2                 | -32,768 tới 32,767                                       |
| `long`         | 8 bytes           | -9223372036854775808 tới 9223372036854775807             |
| `unsigned long`| 8 bytes           | 0 tới 18,446,744,073,709,551,615                         |


### 3.2 Real number

| Type    | Kích thước (byte) | Phạm vi giá trị                          |
|---------|-------------------|------------------------------------------|
| `float` | 4                 | Chính xác tới 6 chữ số thập phân         |
| `double`| 8                 | Chính xác tới 10 chữ số thập phân        |

### 3.3 Character

| Type           | Kích thước (byte) | Phạm vi giá trị     |
|----------------|-------------------|----------------------|
| `char`         | 1                 | -128 to 127          |
| `unsigned char`| 1                 | 0 to 255             |

### 3.4 Void

> Là kiểu k có giá trị, kiểu k trả về.

> Không dùng kiểu `void` khai báo biến, mà dùng `void` khai báo hàm.

- Kiểu trả về
```c
    #include <stdio.h>

    int main()
    {
        const char x = 300;
        printf("%d", x);
        return 0;
    }
```

- Kiểu không trả về

```c
    #include <stdio.h>

    void main()
    {
        const char x = 300;
        printf("%d", x);
    }
```

## 4. ASCII code

> Là bảng mã hóa trao đổi thông tin theo chuẩn Hoa Kỳ.
>
> Sử dụng 7 bit nhị phân (0 đến 127) dùng biểu diễn thông tin ký tự.

## 5. Format in C

`%c`  : Ký tự đơn

`%hhu`: Số nguyên không dấu, 1 byte (unsigned char)

`%hd` : Số nguyên có dâu, 2 byte  (short),

`%s`  : Chuỗi

`%d`  : Số nguyên có dấu, 4 byte (int)

`%f`  : Số thực, (VD: 6.33) float

`%lf` : Số thực dài, (VD: 6.3314141414) double

`%ld` : Sử dụng cho long

`%x`  : Số nguyên hex không dấu (VD: 0xAB)

```c
    #include <stdio.h>

    void main()
    {
        unsigned char a = 18;
        float b = 22.6;
        char c = 'B';
        int d = 3333;
        unsigned char e = 0xAB;
        char str[] = "deviot.vn";

        printf("%d\n", a);     // In số nguyên unsigned char
        printf("%.1f\n", b);   // In số thực với 1 chữ số thập phân
        printf("%c\n", c);     // In ký tự
        printf("%d\n", d);     // In số nguyên int
        printf("%x\n", e);     // In số hex không dấu
        printf("%s\n", str);   // In chuỗi
    }
```
 ## 6. Variables

> Biến là thông tin được lưu trữ trên RAM.
>
> Trong quá trình chạy chương trình thì có thể thay đổi được -> gọi là biến số.
>
> Khai báo biến mà không khởi tạo, địa chỉ sẽ = 0 hoặc địa chỉ rác.

3 đặc trưng của biến:

- Kiểu dữ liệu

- Địa chỉ trên RAM

- Giá trị của biến

## 7. Constant

> Là 1 biến không được thay đổi giá trị trong quá trình chạy.
>
> Khai báo bằng luôn luôn đi kèm khởi tạo giá trị.

- Global const: .rodata (Read-Only) PC hoặc ROM/Flash MCU

```c
    #include<stdio.h>

    const int MAX = 100; // .rodata Read-Only
   
    void cong2so()
    {}

    int main()
    {
        return 0;
    }
```
- Local const: compile-time & run-time
    - Lưu ở Stack đối với compile-time có truy cập địa chỉ `&` hoặc giá trị run-time

```c
    #include <stdio.h>

    void test()
    {
        const int x = 10;   // local const (compile-time)

        int *p = (int*)&x;  // LẤY ĐỊA CHỈ của x

        printf("x = %d\n", *p);
    }

    int main()
    {
        test();
        return 0;
    }
```

#### Thay đổi giá trị của biến hằng số bằng con trỏ được không?

`Con trỏ` lưu ở RAM, mà `biến hằng số` có 2 dạng: Toàn cục và cục bộ.

- Con trỏ -> Lưu vào địa chỉ trong vùng nhớ trên RAM.

- Hằng số là biến toàn cục  -> `.rodata` trên PC hoặc `Flash/ROM` trên MCU.

- Hằng số là biến cục bộ có 2 dạng

    - Giá trị biết trước(compile-time) `const float PI = 3.14;` -> Không lưu ở đâu hết -> Biên dịch ra mã máy luôn.

    - Giá trị biết khi chạy hàm(run-time) `const float x = n + 1;;` -> Stack trên RAM 100%.

=> Trên PC: Có thể thay đổi được nhưng in kết quả không đảm bảo, không an toàn (undefined behavior - hành vi không xác định).

=> Trên MCU: Crash chương trình, nguy hiểm.

## 8. Macro
> Macro là tên do lập trình viên tự đặt, được định nghĩa bằng chỉ thị tiền xử lý `#define`, dùng để thay thế một giá trị hoặc đoạn mã trước khi chương trình được biên dịch.

```c
    #define PI 3.14
```

#### INTERVIEW1: Macro & Constant, Fuction khác nhau như thế nào?

```c
`Macro`

- Không có biến thực sự, câu lệnh ở sau thay cho text ở trước, ở giai đoạn tiền xử lý.

- Tốc độ thực thi nhanh, trên PC macro không tốn bộ nhớ RAM. Nhưng trên MCU macro tốn bộ nhớ Flash vì thực thi chương trình nhiều lần -> copy code nhiều lần.

- Biến mất sau preprocessor, khó debug.

`Const`: 

- Là biến hằng số được khai báo, có kiểu dữ liệu.

- Có có tên biến cụ thể, dễ debug khi phát lỗi.

- Tiêu tốn bộ nhớ, tốc độ truy xuất: 
    
Hằng số là biến toàn cục: Nằm ở vùng nhớ hằng .rodata trên RAM(read-only)-> Tốc độ chậm hơn macro

Hằng số là biến cục bộ:

    - Có giá trị run-time hoặc biến cục bộ có giá trị compile-time có sử dụng `&` truy cập địa chỉ -> Lưu ở Stack trên RAM, tốc độ truy xuất chậm hơn macro.

    - Hằng số là biến cục bộ có giá trị complie-time không được sử dụng `&` truy cập địa chỉ -> Không lưu ở bộ nhớ nào hết,biên dịch thẳng ra mã máy và tốc độ truy xuất xấp xỉ macro.

`Function`

- Hàm được biên dịch thành mã máy và tồn tại trong phân vùng text/code segment -> Không ảnh hưởng bộ nhớ RAM, nhưng tốn nhớ Flash/ROM (đối với MCU).

- Biến được khai báo trong hàm là biến cục bộ lưu ở phân vùng Stack của bộ nhớ RAM - Stack Frame (Nếu có static thì lưu data segment).

- Tốc độ thực thi chương trình chậm hơn macro, vì hàm cần thực hiện tác vụ phụ khi gọi hàm (Overhead call) gồm: push (đẩy tham số lên), jump (nhảy đến địa chỉ hàm), tạo stack frame, return (trả về). 
```

data segment: khởi tạo giá trị

bss segment: chưa khởi tạo giá trị

#### inline???(Tìm hiểu inline, mảng vs chuỗi về phân  nha!)

## 9. PRINTF, SCANF, GETS

### 9.1 PRINTF

### 9.2 SCANF

### 9.3 GETS -> FGETS

> Là lệnh dùng để nhập vào 1 chuỗi, và **cho phép** nhập có khoảng trắng.

#### NHƯNG VẤN ĐỀ LÀ: tiêu chuẩn của VSCode hiện nay, hàm `gets` đã bị loại bỏ khỏi C11

-> Đổi hàm `gets()` -> `fgets()`

`scanf()` không coi `ENTER` là kí tự nhập vào. Nhưng ở `fgets()` thì ngược lại, vì vậy cần loại bỏ `ENTER` gây ra `\n`


```c
    #include <stdio.h>
    #include <string.h>  

    int main()
    {
        char ten[30];

        printf("Nhap ten: ");
        
        // strcspn(ten, "\n") tìm vị trí của ký tự \n.
        // fgets(<tên mảng>,<kích thước>, stdin)

        fgets(ten, sizeof(ten), stdin);  

        // <tên mảng>[strcspn(<tên mảng>, "\n")]
        // Xóa `\n`
        ten[strcspn(ten, "\n")] = '\0';  

        printf("Ten: %s\n", ten);

        return 0;
    }
```
</details>

<details>
  <summary><h3>Lesson 2: Operators & Bitmask  </h3></summary>

Các toán tử trong C:

`+`
`-`
`*`
`/`
`%`
## 1. Toán tử tăng giảm

Toán tử tăng:

- `x++`: Thực hiện lệnh trước, tăng giá trị sau.

- `++x`: Tăng giá trị trước, thực hiện lệnh sau.

Toán tử giảm:

- `y--`: Thực hiện lệnh trước, giảm giá trị sau.

- `--y`: Giảm giá trị trước, thực hiện lệnh sau.

## 2. Toán tử quan hệ

`==`

`!=`

`<`

`<=`

`>`

`>=`

## 3. Toán tử logic

`&&`: AND

`||`: OR

`!`: NOT

## 4. Toán tử thao tác với Bit

`|`: OR

`&`: AND

`~`: NOT

`^`: X-OR (0 vs 1 = 1)

`<<`: Shift Left

`>>`: Shift Right

</details>

<details>
  <summary><h3>Lesson 3: Control Structures </h3></summary>

<details>
  <summary><h2>I. Conditional Statements </h2></summary>

## 1. Điều kiện if else

- `if`

- `if ... else`

- `if ... else if ... else`

## 2. Toán tử 3 ngôi

`bieuthuc_1 ? bieuthuc_2: bieuthuc_3;`

- Dạng viết tắt của if else

- Kiểm tra `bieuthuc_1` đúng hay sai? Nếu đúng thì gán giá trị cho `bieuthuc_2`. Nếu sai gán giá trị cho `bieuthuc_3`.
fun
```c
    #include<stdio.h>

    int main ()
    {
        int a = 10, b = 1, max;
        max = (a>b)? a:b;

        // In ra số lớn nhất
        printf("Max = %d\n",max);

        return 0;
    }
```
## 3. Switch case 

> Cấu trúc rẽ nhánh dùng để chọn 1 trong nhiều trường hợp khác nhau.

- `expession`có thể là biểu thức bắt buộc kết quả hằng và được so sánh với các `case`.

- `case` nào có giá trị tương ứng thì sẽ thực thi case đó cho đến khi gặp `break` để thoát.

- Nếu không có `case` nào tương ứng, thì thực hiện case `default`.

```c
switch(expression)
{
    case const1;
        // Câu lệnh 1
        break;
    
    case const2;
        // Câu lệnh 2
        break;
    .
    .
    .
    default:
        // Câu lệnh default

}
```

</details>


<details>
  <summary><h2>II. Loops </></summary>

## 1. For 

> Sử dụng khi biết trước số lần lặp

```c
    for(khởi tạo giá trị; điều kiện; cập nhật biến)
    {
        // Các lệnh cần 
    }
```

`flowchart`: Khởi tạo -> Kiểm tra điều kiện -> Thực hiện nội dung lặp -> Cập nhật biến lặp.

## 2. While

> Sử dụng khi không  biết trước số lần lặp

```c
    while (Expression)
    {
        // Code
    }


```
`flowchart`: Kiểm tra điều kiện (Expression) đúng (!=0) tiếp tục lặp, Expression sai(==0) thoát vòng lặp.

## 3. Do...while

> Dùng để kiểm tra những giá trị input

```c
    do
    {
        // code
    } while (Expression);

```


`flowchart`: Thực hiện câu lệnh trước, rồi mới kiểm tra điều kiện (Expression) sau. Nên lặp ít nhất 1 lần.

### Từ khóa `continue`

> Nếu vòng lặp đang chạy mà gặp từ khóa `continue`, thì sẽ bỏ qua các lệnh dưới `continue` ở vòng lặp hiện tại. Và chương trình sẽ tiếp tục thực thi lại vòng lặp lần tiếp theo.

```c
    // In 1->10 trừ số 3,7,9

    #include <stdio.h>

    int main()
    {
        for(int i = 1; i<=10; i++)
        {
            if(i == 3){
                continue;
            }

            else if(i == 7){
                continue;
            }
            
            else if(i == 9){
                continue;
            }
            printf("%d\n",i);
        }
    }
```
### Từ khóa `break`

> Nếu chương trình trong vòng lặp đang chạy gặp `break` thì nó thoát ra khỏi vòng.

```c
    // in ra số chẵn 1-> 100, tới số 10 thì break
    #include<stdio.h>

    int main ()
    {
        int i =0;
        while (i <= 100)
        {   
            i++;
            if(i%2!=0){
                continue;
            }
            if(i>10){
                break;
            }

            printf("%d\n",i);
            
        }
    }
```

### Flag

> Flag là cờ được xem như biến tạm, để ghi nhớ trạng thái True/False (0 1). Thường áp dụng "biến tạm" để kiểm tra giá trị, kiểm tra điều kiện.

```c
#include<stdbool.h>
int main() 
{
    /*code*/
    bool laSNT = true;
}
```

</details>

</details>

<details>
  <summary><h3>Lesson 4: Local Variables, Global Variables, Static  </h3></summary>

## I. Local variables
(Biến cục bộ)

> Phạm vi khai báo sử dụng trong 1 hàm, địa chỉ bị cấp thoát sau khi gọi hàm.
>
> Cấp phát vào vùng nhớ `Stack` trên RAM. 


```c
    #include<stdio.h>

    int main()
    {
        int x = 10;

        return 0;
    }
```

## II. Global variables
(Biến toàn cục)

> Phạm vi khai báo bên ngoài tất cả hàm.
>
> Tồn tại trong suốt quá trình chạy chương trình.
>
> Cấp phát vào vùng nhớ `Data segment` nếu biến được khởi tạo, `Bss segment` nếu biến không được khởi tạo. 


```c
    #include<stdio.h>

    int x = 10;

    int main()
    {
        return 0;
    }
```
## III. Static variables

### 1. Static với biến cục bộ (C-advance)

> Được khởi tạo 1 lần duy nhất trong cả chương trình.
>
> Phạm vi sử dụng bên trong 1 hàm khai .
>
> Giá trị/Vùng  được giữ lại sau khi thoát khỏi hàm (lưu vào `Data segment`/`Bss segment`), địa chỉ tồn tại xuyên suốt chương trình.

```c
    #include <stdio.h>

    int in_so_thu_tu(void)
    {
        static int x = 0;
        x = x + 1;
        printf("%d\r\n", x);
    }

    int main() {
        in_so_thu_tu(); // 0
        in_so_thu_tu(); // 1
        in_so_thu_tu(); // 2
        in_so_thu_tu(); // 3 
        in_so_thu_tu(); // 4
        return 0;
    }
```
- Ứng dụng: Lọc nhiễu blink led

### 2. Static với biến toàn cục (C-advance)

> Phạm vi sử dụng bên ngoài tất cả hàm.
>
> Khóa cái biến toàn cục đó lại chỉ được sử dụng trong File khai báo, các File khác không thể truy cập (Không thể dùng từ khóa `extern` gọi ra được, không thể liên kết File).

- Ứng dụng: Thiết kế thư viện, ẩn đi quá trình trung gian tính ra kết 

### 3. Static trong khai báo hàm

> Chỉ sử dụng trong File khai báo nó, các File khác không thể truy cập (giống static toàn cục)


</details>

<details>
  <summary><h3>Lesson 5: Function in C  </h3></summary>

## I. Hàm là gì?

> Nhóm những khối lệnh cùng thực hiện 1 chức năng, tên của hàm thể hiện chức năng của hàm.

Hàm có 2 dạng chính: hàm có giá trị trả về, hàm không có giá trị trả về 

```c
    <Kiểu dữ liệu trả về> <Tên hàm> ( <Tham số nếu có> )
    {
        // Code
        // ...

        <return Giá trị trả về nếu có>
    }
```

## 1. Hàm không có giá trị trả về (return void)

```c
    // Hàm không có tham số, không có giá trị trả về
    void hello()
    {
        printf("Hello world");
    }
```

```c
    // Hàm có tham số, không có giá trị trả về
    void add(int a, int b)
    {
        printf("%d + %d = %d", a, b, a + b);
    }
```

- void không truyền tham số & void truyền tham số (không có trả về)

## 2. Hàm có giá trị trả về (return <....>)

```c
    // Hàm không có tham số, có giá trị trả về
    int add()
    {
        int a;
        return a;
    }
```

```c
    // Hàm có tham số, có giá trị trả về
    int add(int a, int b)
    {
        return a+b;
    }
```
- int không truyền tham số & int truyền tham số (có trả về)


<details>
  <summary><h2>VD1: Hàm không trả về không truyền tham số, hàm có trả về không truyền tham số/h2></summary>

```c
    #include <stdio.h>

    void nhapten(void)
    {
        char ten[30];
        printf("Nhập tên: ");
        scanf("%s",ten);
        printf("Tên: %s\n",ten);
    }

    int nhaptuoi(void)
    {
        int tuoi;
        printf("Nhập tuổi: ");
        scanf("%d",&tuoi);
        return tuoi; // return về cái biến mình khởi tạo, giá trị trả về 1 số, thoát khỏi hàm là bị cấp thoát
    }

    int main ()
    {   
        int tuoithucte; // tạo biến tuoithucte, để gán giá trị return
        nhapten();
        tuoithucte = nhaptuoi(); 
        printf("Tuổi: %d\n",tuoithucte);
        
        return 0;
    }
```
</details>

<details>
  <summary><h2>VD2: Hàm không trả về, có truyền tham số</h2></summary>

Hàm có `return` thì ở `main()` phải tạo 1 biến trung gian gán giá trị `return`. Nếu gọi hàm trực tiếp mà không gán giá trị thì `return` sẽ bị bỏ đi -> return vô nghĩa.

```c
    // Hàm không trả về
    #include <stdio.h>

    void tong3soTN(int a, int b, int c)
    {
        int result;
        result = a + b + c;
        printf("Tổng 3 số: %d + %d + %d = %d\n",a,b,c,result);
    }

    int main ()
    {   
        tong3soTN(1,2,3); // 2 hàm này địa chỉ hoàn toàn khác 
        tong3soTN(4,5,6);
        return 0;
    }
    
```
</details>

<details>
  <summary><h2>VD3: Hàm có kiểu dữ liệu trả về, có truyền tham số</h2></summary>

```c
    // Hàm có trả về
    #include <stdio.h>

    int tong3soTN(int a, int b, int c)
    {
        int result;
        result = a + b + c;
        return result;
    }

    int main ()
    {   
        int res; // Khởi tạo biến gán giá trị return
        res = tong3soTN(1,2,3);
        
        printf("Tổng 3 số: %d + %d + %d = %d\n",1,2,3,res);
        return 0;
    }
```
</details>

</details>

<details>
  <summary><h3>Lesson 6: Pass by Value, Pass by Reference   </h3></summary>

## I. Pass by Value (Truyền tham trị)
(Truyền vào 1 giá trị)

- **Truyền giá trị** của biến vào hàm.

- Trong hàm, biến mới được tạo **có địa chỉ khác** với biến gốc.

- Nếu thay đổi giá trị biến mới trong hàm, **biến gốc ngoài hàm không bị ảnh hưởng**. 

```c
    #include<stdio.h>
    #include<stdlib.h>

    void giam1donvi(int var) // var = 100
    {
        var = var - 1;  // var = 99 // 0xe5 0xe6 0xe7 0xe8
    }// rời khỏi hàm, biến var bị cấp thoát địa chỉ, giá trị bị mất

    int main()
    {
        int x = 100; // 0x00 0x01 0x02 0x03
        printf("Trước: x = %d\n",x); // 100
        giam1donvi(x); 
        printf("Sau: x = %d\n",x); // 100

        return 0;
    }
```

- Để thay đổi được thì phải truyền địa chỉ của biến x -> Truyền tham chiếu 

## II. Pass by Reference (Truyền tham chiếu)
(Truyền vào 1 địa chỉ)

_Trong C không có reference, pass by reference chỉ có ở C++. Ta mượn con trỏ pointer để lưu và truyền địa chỉ
=> Gọi chính xác. pass by pointer in C_

- **Truyền địa chỉ** ô nhớ của biến vào hàm.

- Nếu thay đổi giá trị của biến trong hàm, thì **biến gốc bên ngoài cũng thay đổi**. Bởi vì nó cùng địa chỉ

```c
    #include<stdio.h>
    #include<stdlib.h>

    void giam1donvi(int *var) // var = 100
    {
        *var = *var - 1;  // var = 99 // 0x00 0x01 0x02 0x3
        // var: địa chỉ truyền vào
        // *var: giá trị tại vùng địa chỉ truyền vào
    }
    int main()
    {
        int x = 100; // 0x00 0x02 0x03 0x03
        printf("Trước: x = %d\n",x); // 100
        giam1donvi(&x); 
        // &x: truyền vùng địa chỉ của x  
        // x: truyền giá trị của x
        printf("Sau: x = %d\n",x); // 99

        return 0;
    }
```
</details>

<details>
  <summary><h3>Lesson 7: String </h3></summary>

# I. String(Chuỗi)

> Chuỗi là tập hợp các ký tự nằm liền nhau, lưu liên tiếp vào ô nhớ RAM. Luôn có 1 ký tự `null`(`\0`) kết thúc chuỗi.

Có 2 cách khai báo chuỗi: {V i e t N a m \0}

- C1: Dùng con trỏ kiểu char

`char *x = "VietNam";`

```c
#include <stdio.h>

int main ()
{
    char *x = "VietNam";

    /**
     *  Bời vì chuỗi "VietNam" lưu ở vùng nhớ hằng (.rodata) 
     *  -> Không thể thay đổi giá trị chuỗi trực tiếp, phải trung gian qua địa chỉ con trỏ
     * 
     *  - Chuỗi "VietNam"                // 0x08
     *  - Con trỏ `*x` sẽ trỏ đến lưu địa chỉ 0x08
     * 
     *  - Thay bằng chuỗi mới "ABC"      // 0x04
     *  - Con trỏ `*x`  0x08  -> 0x04 
     *  => "ABC"
     */ 

    x = "ABC";          
    printf("%s",x);     
    return 0;
}
```

- C2: Mảng ký tự
`char y[] = "VietNam";`

```c
#include <stdio.h>

int main ()
{
    char y[] = "VietNam"; 
    
    /**
     *  Vì cả chuỗi "VietNam" và mảng lưu ở stack nên thay vào trực tiếp luôn
     */
    y[0] = 'A';
    y[1] = 'B';
    y[2] = 'C';
    y[3] = 0; // hoặc '\0'
    printf("%s",x);
    return 0;
}
```

#### So sánh khai báo chuỗi bằng con trỏ char & khai báo chuỗi bằng mảng có gì khác nhau?

**Khai báo chuỗi bằng con trỏ kiểu char**

- Giá trị của chuỗi lưu ở vùng nhớ hằng(.rodata) không thể thay đổi giá trị được.

- Chỉ có thể dùng con trỏ để trỏ đến địa chỉ của chuỗi khác, hoàn toàn không thể thay đổi từng giá trị của chuỗi.
 -> Có thể lỗi nếu cố gắng ghi đè. 

**Khai báo chuỗi bằng mảng**

- Giá trị của chuỗi lưu ở stack(biến cục bộ), data(biến toàn cục) -> lưu trong RAM(ghi/đọc). Nên dễ dàng thay đổi từng phần tử của chuỗi.

## II. Thao tác với chuỗi

- Hàm `strlen`: tính độ dài 1 chuỗi(đếm từ phần tử đầu đến khi gặp phần tử kết thúc chuỗi `\0`).

```c
    int strlen(const char *str);
    // hoặc
    int strlen(char s[]);
```

```c
    #include <stdio.h>
    #include <string.h>

    int main()
    {
        char s[] = "Thuan";
        // char[]: kích thước tự động tính theo chuỗi khởi tạo

        int dodai = strlen(s);
        
        printf("Độ dài chuỗi là: %d",dodai);
        return 0;
    }
```

- Hàm `strcmp`: Dùng để so sánh **độ lớn/giá trị** 2 chuỗi str1 và str2, độ dài so sánh tính theo chuỗi ASCII

```c
    int strcmp(const char *str1, const char *str2);
```

```c
    #include <stdio.h>
    #include <string.h>

    int main()
    {
        char s1[] = "Thuan"; 
        char s2[] = "thuan";
        int sosanh = strcmp(s1,s2);
        
        if (sosanh > 0)
            printf("s1 > s2\n");
        
        else if (sosanh < 0)
            printf("s1 < s2\n");

        else 
            printf("s1 = s2\n");    


        return 0;
    }
```

**Ứng dụng:** Truyền dữ liệu trong IoT

- Hàm `strcpy`: Hàm dùng để **ghi đè** giá trị của chuỗi nguồn vào chuỗi đích. Chuỗi đích phải có kích thước đủ lớn để không bị tràn dữ liệu.


```c
    char *strcpy(char *dest,  const char *src);
```
`dest`: là con trỏ trỏ tới mảng chứa chuỗi vừa được sao chép

`src`: Chuỗi để được sao chép.

```c
#include <stdio.h>
#include <string.h>

int main()
{
    char s1[] = "Thuan";
    char s2[] = "123456789"; // char[]: kích thước tự động tính theo chuỗi khởi tạo
    char s3[7] ="Huynh";
    char s4[] = ".vn";


    strcpy(s1,s2);
    strcpy(&s3[5],s4);
    
    printf("%s\n",s1); // 123456789
    printf("%s\n",s3); // Huynh.vn

    return 0;
}
```

#### INTERVIEW2: Ghi đè chuỗi "abc" của mảng vào chuỗi "Thuan" của con trỏ được hay không?

```c
#include <stdio.h>
#include <string.h>

int main()
{
    char *ten = "Thuan";
    char s2[] = "123";

    strcpy(s1,s2);
    
    printf("%s\n",s1);


    return 0;
}
```
```c
-> Không được, vì chuỗi `"Thuan"` lưu ở vùng nhớ hằng(.rodata) RAM(chỉ đọc). Không thể lấy mảng `s2[] = "123"` ghi đè lên được.
    
-> Còn nếu `char ten[]` là mảng kí tự, thì thoải mái ghi đè, đảm bảo kích thước đủ lớn để không bị chuỗi nguồn ghi đè làm tràn dữ liệu.
```

- Hàm `strcat` dùng để **nối** chuỗi nguồn vào phần tử cuối(đuôi) của chuỗi đích.

```c
    char *strcat(char *dest, const char *scr);
```

```c
    #include <stdio.h>
    #include <string.h>

    int main()
    {
        char s1[] = "Thuan"; //char[]: kích thước tự động tính theo chuỗi khởi tạo
        char s2[] = "123";

        strcat(s1,s2);
        
        printf("%s\n",s1); //Thuan123


        return 0;
    }
```

- Hàm `strstr` là hàm tìm chuỗi s2 trong s1, và trả về địa chỉ của s2 trong s1.

```c
    char *strstr(const char *s1, const char *s2); 
```


```c
    #include <stdio.h>
    #include <string.h>

    int main()
    {
        char s1[] = "Huynh Minh Thuan hoc lop DH20TD ne!";
        char s2[] = "20TD"; //s1[], s2[] Kích thước của mảng tự động đc tính theo chuỗi được khai báo

        // Tìm vị trí của chuỗi"20TD" của s2 trong s1
        char *str = strstr(s1,s2); // trả về địa chỉ của chuỗi s2 trong s1

        printf("%c\n",s1[27]);

        if(str) // hoặc if(str != NULL)
        {
            printf("Đã tìm thấy chuỗi %s, địa chỉ %p\n",s2,str);
            // s2 là địa chỉ gốc (%s)
            // str là địa chị của s2 trong s1(%p)

            printf("Tại vị trí: %d\n",str-s1); 
            // str địa chỉ sau
            // s1 địa chỉ đầu tiên
        }
        else 
        {
            printf("Không tìm thấy!.");
        }

        return 0;
    }
```

- Hàm `strtok` là hàm **tách** chuỗi dài thành các chuỗi nhỏ, dựa vào các ký tự đặc biệt để phân rẽ chuỗi.

</details>

<details>
  <summary><h3>Lesson 8: Array</h3></summary>

## I. Mảng 1 chiều

> Là tập hợp các biến nằm liền nhau và có cùng kiểu dữ liệu, lưu vào các ô nhớ liên tiếp trên RAM.

```c
    unsigned char mang[5] = {0x01, 0x02, 0x03, 0x04, 0x05};

    /**
     *  mang[0] = 0x01
     *  
     *  - kiểu dữ liệu: unsigned char(1 byte)
     *  - &mang[0]: địa chỉ phần tử trên RAM
     *  - 0x01: giá trị phần tử
     *  - 0: index(vị trí) phần tử trong mảng 
     */
```

- Địa chỉ của mảng chính là tên mảng đó, hoặc là địa chỉ phần tử đầu tiên của mảng.

(_Nếu truy cập **phần tử** của mảng phải có `&`_)

## II. Mảng 2 chiều 

> Mảng 2 chiều là tập hợp các mảng 1 chiều được sắp xếp liền kề.

Đặc trưng của mảng 2 chiều:

- Kiểu dữ liệu phần tử, giá trị

- Tên mảng `a` là địa chỉ của mảng, địa chỉ mảng là phần tử đầu tiên `&a[0][0]`

**Note:** Khi truyền mảng 2 chiều vào hàm bắt buộc phải truyền số cột (có thể không truyền số hàng)

-> Vì nếu không truyền cột thì Compiler sẽ không biết nhảy bao nhiêu ô để đến hàng tiếp theo.

```c
    // Khai báo đúng số hàng và cột
    int mang[3][4] = {
        1,2,3,4,
        5,6,7,8,
        10,12,1314,
    };
```

```c
    // Khai báo số cột nhiều hơn -> dùng `{}` để in mảng đúng
    int mang[5][50] = {
        {1,2,3,4,5},
        {6,64,3,2,1},
        {0,1,2,2,1},
    };
```

- Truy xuất dữ liệu mảng
```c
    #include <stdio.h>
    int mang[3][4] = {
                1,2,3,4,
                11,12,13,14,
                21,22,23,24
                };

    char chuthich[3][6] = {
        "dong1",
        "dong2",
        "dong3",
    };

    int main(int argc, char const *argv[])
    {
        printf("-------------------\n");
        printf("%d\n", mang[2][3]);               //24
        printf("%d\n", mang[1][0]);               //11
        printf("%d\n", mang[1]);             // &mang[1][0] : địa chỉ 11 trêm RAM
        printf("%d\n", &mang[1][0]);         // địa chỉ 11 trêm RAM
        printf("-------------------\n");

        printf("%s\n",chuthich[0]);
    }
```

### Ứng của mảng 2 chiều

#### 1. Tạo LOG (nhật ký)

Là các dòng ghi trạng thái, thông tin và những vấn đề xảy ra trong code.

`INFO`	Thông tin chung

`DEBUG`	Thông tin chi tiết để debug

`WARN`	Cảnh báo nhưng chương trình vẫn chạy

`ERROR`	Lỗi không nghiêm trọng

`FATAL`	Lỗi nghiêm trọng làm chương trình dừng

```c
    #include <stdio.h>

    char error_logs[5][50] = {
        "ERROR 0: Sai cu phap",
        "ERROR 1: Tran bo nho",
        "ERROR 2: Gia tri truyen vao sai",
        "ERROR 3: Khong tra ve",
        "ERROR 4: Timout"
    };

    int main(int argc, char const *argv[])
    {
        printf("%s\n",error_logs[0]);
        printf("%s\n",error_logs[1]);
        printf("%s\n",error_logs[2]);
        printf("%s\n",error_logs[3]);
        printf("%s\n",error_logs[4]);
        return 0;
    }
```
#### 2. Lưu dữ liệu 

> Lưu dữ liệu nhiều cảm biến, quét LED,...

```c
    #include <stdio.h>

    #define SENSOR_NUMBER 10
    #define DAYS          31

    int nhietdocambien [SENSOR_NUMBER][DAYS];

    void nhapdulieu(int sensor_index, int day, int value)
    {
        nhietdocambien[sensor_index - 1] [day - 1] = value;  
    }

    int docdulieu(int sensor_index, int day)
    {   
        

        return nhietdocambien[sensor_index - 1] [day - 1]; // -1 vì đếm từ 0
    }

    int main(int argc, char const *argv[])
    {
        nhapdulieu(1,1,28);
        int temp = docdulieu(1,1);
        printf("nhiet do cua sensor %d, ngay %d la %d",1,1,temp);

        return 0;
    }
```

</details>


<details>
  <summary><h3>Lesson 9: Pointer</h3></summary>

_(phần 2 ở C-Advanced)_


#### INTERVIEW3: int (*p)[5] và int *p[5] có gì khác nhau?

```c
int (*p)[5]: Là con trỏ đến mảng 5 phần tử kiểu int
int *p[5]: Là mảng 5 phần tử con trỏ kiểu int
```
<img width="662" height="358" alt="Image" src="https://github.com/user-attachments/assets/6308032c-e00c-47c5-b849-f9e33b51a3c2" />

# A. Thao tác với con trỏ

> Con trỏ là 1 biến, không dùng lưu giá trị mà nó dùng để lưu địa chỉ của 1 đối tượng (biến, hàm, mảng,...)

> Cũng giống với biến, thì con trỏ cũng được cấp phát 1 vùng địa chỉ trên RAM

> Kích thước con trỏ phụ thuộc vào kiến trúc của máy tinh và trình biên dịch (Lap64bit = 8 byte, STM32 = 4 byte).

## 1. Kiểu dữ liệu của con trỏ

> Kiểu dữ liệu quyết định con trỏ đọc bao nhiêu byte trong vùng nhớ.

- Cấp phát vùng nhớ trên RAM (MSB-LSB)

```c
#include <stdio.h>

/**
 *  0x07 0x06 0x05 0x05 0x04 0x03 0x02 0x1
 *  Bit7 Bit6 Bit5 Bit4 Bit3 Bit2 Bit1 Bit0
 *   |                                   |
 *  MSB                                 LSB
 *  0x03                                0xE8
 *  
 * - Vì cấp phát địa chỉ theo MSB-LSB nên trọng số cao được cấp trước, trọng số thấp cấp sau
 * - (int) 0x00 0x00 0x03 0xE8
 */

int main(int argc, char const *argv[])
{   
    unsigned int x = 1000;  // x = 0x03E8 
    unsigned char *ptr = (unsigned char*) &x; // ép kiểu vs con trỏ (data_type*) // casting type    

    printf("%02x ", *ptr);
    printf("%02x ", *(ptr+1));
    printf("%02x ", *(ptr+2));
    printf("%02x ", *(ptr+3));

    return 0;
}
```

```c
  #include <stdio.h>

  int main(int argc, char const *argv[])
  {
      unsigned char mang[10] = {0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A};

      unsigned short *ptr = (unsigned short*) &mang; // &mang hoặc địa chỉ đầu tiên

      // Cấp phát địa chỉ theo MSB-LSB // Trọng số cao cấp phát trước(short = 2 byte)
      mang[0] = 0x0201;
      mang[1] = 0x0403;
      mang[2] = 0x0605;
      mang[3] = 0x0807;
      mang[4] = 0x0A09;

      return 0;
  }
```

## 2. Biến với con trỏ

> Kiểu dữ liệu khai báo biến và kiểu dữ liệu con trỏ phải **đồng bộ** với nhau.

```c
#include <stdio.h>

int main()
{
  int x = 111;
  int *p = &x;
  
  /** C2:
   *  int *p;
   *  p = &x;
   * 
   *   p: vùng địa chỉ mà con trỏ trỏ đến.
   *  *p: giá trị tại vùng địa chỉ mà con trỏ trỏ đến.
   *  &p: vùng địa chỉ của con trỏ. 
   */


  printf("Giá trị của x = %d\n", *p); // Giải tham chiếu con trỏ
  printf("Địa chỉ của x là %x hoặc %x\n",&x , p);
  printf("Địa chỉ của *ptr là %x\n",&p);

  return 0;
}
```

## 3. Toán tử tăng-giảm với con trỏ

> Địa chỉ của con trỏ sẽ tăng hoặc giảm theo đúng kích thước của kiểu dữ liệu con trỏ nó trỏ tới.

```c
#include <stdio.h>

int main(int argc, char const *argv[])
{
    unsigned char s1[10] = {1,2,3,4,5,6,7,8,9,10};
    unsigned char *ptr = s1;

    // hoặc tách ra: ptr = s1; // ptr = &s1[0]

    for (int i = 0; i < 10; i++)
    {
        printf("%d", *ptr); // mang[0]
        ptr++;      // ptr + 1 // Không phải + 1 giá trị, mà nhảy sang phần tử liền kề (1byte)
        // 1 - 0x01 (unsigned char)
        // 2 - 0x02
        // 3 - 0x03
        // ...
    }

    //12345678910
    return 0;
}
```

```c
#include <stdio.h>

int main(int argc, char const *argv[])
{
    unsigned int s1[10] = {1,2,3,4,5,6,7,8,9,10};
    unsigned int *ptr;

    ptr = &s1[9];

    for (int i = 10; i > 0; i--)
    {
        printf("%d", *ptr); // mang[10] = 10
        ptr--;      // ptr - 1 // Không phải - 1 giá trị, mà lùi về phần tử liền kề (4byte)

        // 10 - 0xE8 (unsigned int)
        // 9  - 0xE4 
        // 8  - 0xE0
        // ...
    }
    
    // 10987654321
    return 0;
}
```

<details>
  <summary><h4>Một vài ví dụ về toán tử tăng-giảm với con trỏ</h4></summary>

**VD1: (CHUẨN NHẤT)**
```c
  #include <stdio.h>

  int main(int argc, char const *argv[])
  {
      int s1[4] = {5,3,7,9};
      int *p = s1; // &s1[0]

      // Hậu tố: thực hiện lệnh lấy &s1[0] =5, tăng vị trí sau
      // Kết thúc lệnh *p tăng lên 1 vị trí &s1[0] -> &s1[1]
      int a = *p++; 
      
      int b = *p;   // Sử dụng lại *p (lấy giá trị hậu tố ở trên) -> s1[1] =3

      printf("%d\n", a); // 5

      printf("%d\n", b);   // 3
      printf("%d\n", a+b); // 8
      return 0;
  }
```

**VD2:**
```c
  #include <stdio.h>

  int main(int argc, char const *argv[])
  {
      int s1[4] = {1,2,3,4};
      int *p = s1; // &s1[0]

      printf("%d\n", *p++ + *p); 
      // Hậu tố:  &s1[0] = 1
      // lúc này *p đã thực hiện lệnh rồi -> tăng lên 1 vị trí liền kề &s1[1] = 2
      // ERROR: undefined behavior -> 1 biến không thể vừa thay đổi vừa sử dụng
      return 0;
  }
```

</details>


#### Quy tắc vàng khi dùng con trỏ với toán tử tăng giảm

_VD: Trong hàm nhập-xuất mảng_

```c
    void nhapMang(int *n, unsigned char *s1)
    {
        printf("Nhập số phần tử mảng: ");
        scanf("%d", n);
        for (int i = 0; i < *n; i++)
        {
            printf("mang[%d] = ",i);
            scanf("%hhu", s1);
            s1++;
        }
        
        printf("---------------\n");
    }

    void inMang(int n, unsigned char *s1)
    {
        for (int i = 0; i < n; i++)
        {
            printf("mang[%d] = %d\n",i, *s1);
            s1++;
        }
    }
```

- Không được dùng địa chỉ con trỏ gốc tăng-giảm trực tiếp

```c
    // Nếu s1[5]
    s1++;
    ...
    s1--;   // ❌ dễ quên, dễ sai
```    

- Sau câu lệnh tăng-giảm thì địa chỉ con trỏ gốc bị thay đổi `&s1[5]` không còn là `&s1[0]` hay `s1`.
Nên khi sử dụng lại con trỏ cho hàm mới sẽ sinh ra **BUG NGẦM** rất khó tìm.

- Code trên thì không có lỗi, do hàm cục bộ. Nhưng nếu dùng chung 1 hàm hoặc toàn cục -> **BUG**.

=> Giải pháp clean code là dùng con trỏ phụ, để không ảnh hưởng đến con trỏ gốc.

```c
#include <stdio.h>

void nhapMang(int n, char *s1)
{
    char *tmp = s1;   // ✅ con trỏ phụ

    for (int i = 0; i < n; i++)
    {
        scanf("%hhu", tmp);
        tmp++;
    }
}

void inMang(int n, char *s1)
{
    char *tmp = s1;   // ✅ con trỏ phụ

    for (int i = 0; i < n; i++)
    {
        printf("%d ", *tmp);
        tmp++;
    }
}

int main()
{
    char arr[5];
    char *p = arr;

    nhapMang(5, p);
    inMang(5, p);   // OK

    return 0;
}
```


## 4. Mối quan hệ mảng với con trỏ

```c
    #include <stdio.h>

    int main(int argc, char const *argv[])
    {
        unsigned char s[] = {1,2,3,4};
        unsigned char *p = s; // hoặc int *p = &s[0];

        printf("Địa của p: %p hoặc %p\n", p,&s[0]);
        printf("Địa của p+1: %p hoặc %p\n", p+1,&s[1]);
        printf("Địa của p+2: %p hoặc %p\n", p+2,&s[2]);

        printf("------------\n");
        printf("Giá trị của p: %d, %d hoặc %d\n",*p,p[0], s[0]);
        printf("Giá trị của p+1: %d, %d hoặc %d\n",*(p+1),p[1], s[1]);
        printf("Giá trị của p+2: %d, %d hoặc %d\n",*(p+2),p[2], s[2]);

        return 0;
    }
```

```c
/**
 *  Thay đổi phần tử của mảng bằng pointer
 */

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int mang[10] = {1,2,3,4,5,6,7,8,9,10};
    int *p = mang;

    for (int i = 0; i < 10; i++)
    {   
        *p = *p + 10; // thay đổi giá trị mảng, *p giải tham chiếu
        printf("mang[%d] = 0x%x\n", i, *p);
        p++;    // truy cập địa chỉ của mảng để tăng lên các vị trí liền kề
                // nếu *p là lấy giá trị rồi, không tăng vị trí được.
    }
    

    return 0;
}
```




</details>

</details>

<details>
  <summary><h3>Additional Notes</h3></summary>

## 1. Tham số dòng lệnh argc, argv

```c
#include <stdio.h>

/**
 * @brief   Mô tả ngắn gọn về hàm, biến, lớp… (1-2 dòng)
 * 
 * @param   Tên_tham_số  Giải thích tham số của hàm
 *           (nếu hàm có nhiều tham số, lặp lại @param cho từng tham số)
 * 
 * @return  Giá trị trả về
 * 
 * @details Mô tả chi tiết hơn về chức năng, cơ chế, thuật toán hoặc cách hoạt động
 *          của hàm/biến/lớp. Có thể dài hơn, nhiều dòng.
 * 
 * @note    Thông tin quan trọng, cảnh báo, lưu ý khi sử dụng hàm/biến/lớp.
 */


/**
 * @brief Tham số dòng lệnh của hàm main.
 *
 * @param argc Số lượng tham số dòng lệnh truyền vào chương trình.
 *             Luôn >= 1, vì argv[0] chứa tên chương trình.
 * @param argv Mảng các chuỗi chứa từng tham số dòng lệnh.
 *             argv[0] là tên chương trình, argv[1] là tham số đầu tiên, ...
 * 
 * @return 0
 *
 * @details
 * Cơ chế này cho phép điều khiển chương trình từ bên ngoài thông Command Terminal, tương tự
 * trên cả Windows và Linux. Thường dùng nhiều trên Linux nhờ môi trường terminal mạnh.
 *
 * @note
 * - Luôn kiểm tra argc trước khi truy cập argv[i] để tránh truy xuất ngoài phạm vi.
 * - Ứng dụng phổ biến: truyền dữ liệu, chọn chế độ chạy, mở file, xử lý batch/script.
 */

int main(int argc, char *argv[])
{
    printf("argc = %d\n", argc);
    printf("argv[0] = %s\n", argv[0]);
    
    if (argc > 1)
        printf("argv[1] = %s\n", argv[1]);

    return 0;
}
```

## 2. Tại sao sử dụng thư viện `<stdint.h>`?

- Khi dùng các kiểu dữ liệu có sẵn như `short, int, long`, thì đối với mỗi PC có kiển trúc khác nhau (32bit/64bit) thì kích thước sẽ khác nhau. Ngay cả kích thước trên MCU cũng khác nhau (STM8/STM32).

- `<stdint.h>` là thư viện dùng để sử dụng kiểu dữ liệu nguyên với số bit **cố định** (không thay đổi).

```c
    // Có dấu

    int8_t      -> 8bit  (1byte)
    int16_t     -> 16bit   2
    int32_t     -> 32bit   4
    int64_t     -> 64bit   8
```
```c
    // Không dấu
    uint8_t     -> 8bit
    uint16_t    -> 16bit
    uint32_t    -> 32bit
    uint64_t    -> 64bit
```
## 3. `return;`, `return 0;`, `return <biến>;`

- `return;`         -> Hàm void (): Thoát hàm ngay lập tức.

- `return 0;`       -> Hàm <data type> (): Chương trình chạy thành công, đồng thời thoát hàm.

- `return <biến>;`  -> Hàm <data type> (): Trả về giá trị

## 4. Tràn số -> Ép kiểu (type casting)

- Tránh tràn số.
- Đảm bảo an toàn dữ liệu khi xử lý dữ liệu khác data types.




</details>


# ÔN LẠI STRING-ARRAY-POINTER
