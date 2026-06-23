# 1. Quá trình compiler?
Gồm 4 quá trình:
- Tiền xử lý
- Biên dịch
- Dịch hợp ngữ
- Liên kết

# 2. Datatype, format, variable, constant?

# 3. Macro? So sánh macro & const?

# 4. Local/global variables?

# 5. Pass by value, pass by referencee?

# 6. Function? So sánh macro & func?

# 7. String?
- strlen
- strcmp(s1,s2) // ASCII
- strcspn
- strcpy
- strstr
- strchr
- strtok

# 8. Array?
- độ dài mảng: n = arr/arr[0]
- tách mảng
- gộp mảng
- thêm/xóa/sửa mảng
- sắp xếp mảng tăng dần/giảm dần
- tìm MAX/MIX mảng

# 9. Struct, union? Tính kích thước? So sánh struct & union?
struct:  mỗi biến là vùng nhớ khác nhau
-> kích thước: all member + padding

union: chung vùng nhớ
-> kích thước: member MAX + padding

# 10. Stack? linear/circular queue?
STACK: Ngăn xếp (LIFO)
-  push: thêm phần tử vào đỉnh stack (top++)
-  pop: lấy phần tử từ đính stack (top--)
-  top: đọc giá trị đỉnh stack (top = size - 1)
- kiểm tra stack đầy: top = maxsize - 1
- kiểm tra stack rỗng: top = -1

Trước khi tạo stack cần khởi tạo 3 biến:
- items[]: tạo 1 mảng để lưu phần tử của stack
Nếu là *items: phải cấp phát động malloc
- size: kích thước tối đa của stack
- top: giá trị tại đỉnh stack (== -1, giá trị ban đầu)

# 11. So sánh linear queue & circular queue

Giống: Đều là cấu trúc dữ liệu hàng đợi. Hoạt động theo cách phần tử được thêm vào trước thì lấy ra trước (first in-first out).
Đều có enqueue, dequeue và 2 giá trị quan trọng front, rear.

Khác:
- Linear: Rear(giá trị cuối phần tử) chỉ tăng không quay vòng. Nên không thể tái sử dụng lại ô trống để enqueue(thêm phần tử).
VD: Cho mảng 5 phần tử, enqueue cả 5 phần tử, sau đó dequeue 2 phần tử đầu --> linear xuất hiện hiện tượng đầy giả. KHông thể enqueue vào 2 ô trống đó được. Bắt buộc phải dequeue toàn bộ mới enqueue được phần tử mới. (front > rear hoặc front == -1 thì dừng)

- Circular: Giá trị front, rear có thể xoay vòng dựa vào dấu `%` (front = (front + 1) % size, rear = (rear + 1) % size). Vì vậy khắc phục đc tình trạng lãng phí ô nhớ của linear. Có thể enqueue phần tử vào 2 ô trống ở đầu được. (Đến khi front == rear thì front = -1 rỗng dừng)

# Pointer?
ptr?
truy cập giá trị? địa chỉ?
--> dereference

// biến 

int x = 10;
int *ptr = &x;

--> truy cập giá trị %d
*ptr hoặc x

--> truy cập địa chỉ %p
ptr hoặc &x

// mảng

int arr[] = {0x01, 0x02, 0x03, 0x04};
int *ptr = arr; // arr hoặc &arr[0]

--> truy cập giá trị %d
- phần tử thứ nhất: *ptr  hoặc arr[0]
- phần tử thứ 2: *(ptr+1) hoặc arr[1]
- phần tử thứ 3: *(ptr+2) hoặc ar2[2]

--> Truy cập địa chỉ %p
- phần tử thứ nhất: ptr hoặc &arr[0]
- phần tử thứ 2: ptr+1 hoặc &arr[1]
- phần tử thú 3: ptr+2 hoặc &arr[2]

// trường hợp khác về mảng
--> truy cập giá trị các phần tử của mảng
arr[2] hoặc 2[arr] là *(arr + 2)

--> truy cập giá trị
- arr: tên mảng
- &arr[0]: phần tử đầu tiên của mảng
====> 2 cái này như nhau

arr vs &arr khác nhau:
- arr là truy cập mảng hay còn gọi là phần tử đầu tiên của mảng, nên  khi + 1 địa chỉ tăng lên theo byte <data_type>
- &arr là truy cập toàn bộ mảng, khi + 1 thì địa chỉ tăng lên theo tổng số byte <data_type>

// kích thước
#include <stdio.h>

int main ()
{
    int arr[] = {0x01, 0x02, 0x03, 0x04};
    int *ptr = arr;

    printf("%d\n", sizeof(ptr));  // 8 - kích thước con trỏ phụ thuộc vào kiến trúc máy tính
    printf("%d\n", sizeof(*ptr)); // 4 - kích thước của kiểu dữ liệu mà con trỏ nó trỏ đến
    printf("%d\n", sizeof(arr));  // 16 - kích thước của mảng

    return 0;
}

Phân loại con trỏ
X- void ptr
X- ptr const
X- const to ptr
- null ptr (cấp phát bộ nhớ động)
- ptr to ptr (linked list)

--> Học lại linked list để luyện 2 con trỏ này

- function ptr (call back)
Ứng dụng 1: Làm Callback Function (Xử lý sự kiện / Lập trình nhúng)
Hãy tưởng tượng bạn viết một hệ thống nút nhấn trên phần cứng (STM32). Bạn không muốn mỗi lần nút nhấn được bấm, nó lại chạy cố định một hành động. Bạn muốn:

Hôm nay bấm nút thì Bật Đèn.

Mai bấm nút thì Kêu Còi.

Bạn chỉ cần viết một hàm xử lý nút nhấn nhận vào một Con trỏ hàm (Callback). Khi nút được bấm, nó sẽ kích hoạt cái hàm nằm trong con trỏ đó.

Ứng dụng 2: Tối ưu cấu trúc lệnh rẽ nhánh (Thay thế cho chuỗi if-else hoặc switch-case quá dài)
Thay vì viết một rừng if (luachon == 1) tong(); else if (luachon == 2) hieu(); ..., bạn có thể tạo một Mảng con trỏ hàm (như ví dụ ở tài liệu ban đầu của bạn). Khi người dùng chọn menu i, bạn chỉ cần gọi cal[i](a, b);. Code sẽ chạy cực nhanh và gọn gàng



hiện tại đã học
- void ptr
- ptr const
- const to ptr

--> tiếp tục học null ptr & ptr to ptr, nhưng bị trở ngại chưa áp dụng được vào bài tập
==> nên tiếp theoo học linked list
- linked list mới chỉ nắm được khái niệm, chưa thao tác được

--> trước khi thao tác linked list. Thì xem lại thao tác với mảng gồm
- thêm/xóa/sửa mảng
- sắp xếp mảng tăng/giảm
- tách mảng, gộp mảng
- min/max mảng

===> 1. học lại thao tác vs mảng
     2. Thao tác với linked list
     3. con trỏ null (cấp phát động), ptr to ptr
     4. con trỏ hàm, mấy cái callback interrupt