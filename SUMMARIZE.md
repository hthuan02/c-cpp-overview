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
