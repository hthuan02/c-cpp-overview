# Level 2 - Parameter & Data

- Multi parameter callback (pointer, buffer + length, const pointer)


Level 3 — Architecture
typedef, struct chứa callback, đăng ký/hủy đăng ký, kiểm tra NULL, user_data cơ bản


Level 4 — Event-driven
Callback từ sự kiện UART, Timer, Button; phân biệt ISR và xử lý trong main()

Level 5 — Advanced Design
Hiểu callback kết hợp ring buffer, state machine, event queue và RTOS

Level 6 — Project
Xây dựng Driver có callback và tách biệt Driver với Applicatio