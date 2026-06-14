C
- Struct/ union/enum
- Stack/queue
- circular queue --> ring buffer (head/tail)
- linked list
- pointer, dereferences ptr, truy cập địa chỉ- giá trị, func ptr

MCU
- positive register system, SP
- peripherals (Timer, ISR, ADC, DMA), protocol (SPI, I2C, UART)
- makefile: vpath, thumb, compile/linker option(flags)
- linker script
- startup file

Others: Git, debug register


# (FAIL X-X) PLAN A - intern (khó xảy ra)
(Hoàn cảnh hiện tại 9.6.26)

- Ôn CV
- Apply intern hơn 5 cty rồi
- FPT Software

# PLAN B - FRESHERRRRRRRR
(Trường hợp hoàn thành được trước 7.8.26 đổ lại)

- Chuẩn bị cho 2 tháng tới
- Vững kiến thức trong CV cũ
- RTOS --> project 1 update lên RTOS
- GUI QT hoặc winform -> project 2 DC motor
- TOEIC 600-700

# PLAN C 
(Sau tháng 8.2026 vẫn chưa tìm được việc embedded)
- Chạy grab 8h/ ngày hoặc làm KNC bảo dưỡng, điện --> lương 6-8tr/tháng nuôi sống bản thân
- Tiếp tục nuôi dam mê...

# Mình không mong là plan C này xảy ra ^^. Mong mỏi mọi việc đến với mình thật thuận lợi. Mình phải sống, mình nhất định phải sống, mình phải trả ơn cuộc đời này ^^. Mình không để bản thân mình bị dồn vào đường cùng đâu ^^. 

# POINTER QUESTION
1. Sự khác nhau giữa `p++` và `(*p)++`?

- `p++`: là con trỏ p & toán tử tăng, tăng địa chỉ lên 1 đơn vị. Nghĩa là dịch chuyển địa chỉ của con trỏ p sang ô nhớ tiếp theo
VD: arr[] =  {0x00, 0x01, 0x02, 0x04};
--> int *p = arr hoặc = &arr[0]
--> (*p)++ = &arr[1]: ở lần tăng đầu tiên

- `(*p)++`: là giải tham chiếu con trỏ & toán tử tăng. Nghĩa là tăng giá trị của con trỏ lên 1 đơn vị

2. Tại sao kích thước mọi con trỏ trong cùng 1 môi trường bằng nhau?
--> Vì kích thước của nó phụ thuộc vào kiến trúc máy tính và trình biên dịch, không phụ thuộc vào kiểu dữ liệu. Như ở môi trường 32bit (STM32) có địa chỉ từ 0x00000000 - 0xFFFFFFFF. Mọi biến lưu địa chỉ đều cần dùng 4 byte (32 bit) này để biểu diễn, không phân biệt lớn hay nhỏ

3. Bản chất của `array` & `pointer` có giống nhau không?
--> Không giống nhau
Mảng: `int arr[5] = {0x00, 0x01, 0x02, 0x03, 0x04}` 
- Lưu các biến nằm liền kề nhau trên vùng nhớ RAM, chung kiểu dữ liệu.
- Mỗi biến đều có vùng nhớ riêng cho dữ liệu
- sizeof(arr): kích thước toàn bộ mảng
- Không thể arr++

Con trỏ: `int *ptr`
- Là biến dùng để lưu địa chỉ, có thể khai báo biến bằng kiểu dữ liệu hoặc void
- Có vùng nhớ riêng, chỉ dùng để lưu địa chỉ
- sizeof(ptr): kích thước con trỏ
- có thể (*ptr)++ tăng giá trị con trỏ đang trỏ tới hoặc (ptr)++ tăng địa chỉ con trỏ đang trỏ tới.

// 4. Ý nghĩa `int *(*ptr)(int*, int*)`? 
// --> Đây là con trỏ hàm kiểu int, với 2 tham số truyền vào là 2 con trỏ kiểu int. Trả về là 1 con trỏ *ptr kiểu int

5. `int *p[5]` & `int (*p)[5]` có gì khác nhau?

- `int *p[5]`: mảng 5 phần tử là con trỏ kiểu int
- `int (*p)[5]`: con trỏ p trỏ đến mảng 5 phần tử