🌳 Sơ đồ cây Pointer — Embedded C

---

```text
POINTER IN C
│
├── LEVEL 1 — BEGINNER
│   │
│   ├── Địa chỉ & dữ liệu
│   │   ├── &
│   │   ├── *
│   │   ├── address
│   │   └── dereference
│   │
│   ├── Pointer cơ bản
│   │   ├── int *p
│   │   ├── p = &x
│   │   ├── *p
│   │   └── NULL
│   │
│   └── Pointer Arithmetic
│       ├── p++
│       ├── p--
│       ├── p + n
│       └── p - n
│
├── LEVEL 2 — ARRAY + POINTER
│   │
│   ├── Array ↔ Pointer
│   │   ├── arr
│   │   ├── &arr
│   │   ├── &arr[i]
│   │   └── *(arr + i)
│   │
│   ├── Pointer + Array
│   │   ├── p + i
│   │   ├── *(p + i)
│   │   ├── p++
│   │   └── ++p
│   │
│   ├── Prefix / Postfix
│   │   ├── ++p
│   │   ├── p++
│   │   ├── --p
│   │   ├── p--
│   │   ├── (*p)++
│   │   ├── ++(*p)
│   │   ├── *p++
│   │   └── *++p
│   │
│   └── Array / Pointer expression
│       ├── arr[i]
│       ├── *(arr+i)
│       ├── p[i]
│       └── *(p+i)
│
├── LEVEL 3 — INTERN POINTER
│   │
│   ├── Pointer làm parameter
│   │   ├── function(int *p)
│   │   ├── modify variable
│   │   ├── swap()
│   │   └── array parameter
│   │
│   ├── Pointer Arithmetic nâng cao
│   │   ├── pointer difference
│   │   ├── pointer comparison
│   │   └── pointer range
│   │
│   ├── NULL / Null Pointer
│   │   ├── NULL
│   │   ├── NULL check
│   │   ├── dereference NULL
│   │   └── defensive programming
│   │
│   ├── void *
│   │   ├── generic pointer
│   │   ├── cast
│   │   └── generic function
│   │
│   ├── const + pointer
│   │   ├── const int *
│   │   ├── int *const
│   │   └── const int *const
│   │
│   ├── Pointer-to-Pointer
│   │   ├── int **
│   │   ├── **pp
│   │   ├── change pointer
│   │   └── dynamic allocation
│   │
│   └── Array / Pointer types
│       ├── int *p[5]
│       └── int (*p)[5]
│
├── LEVEL 4 — INTERN → FRESHER ⭐
│   │
│   ├── FUNCTION POINTER ⭐
│   │   ├── int (*fp)(int, int)
│   │   ├── assign function
│   │   ├── call through pointer
│   │   └── function pointer parameter
│   │
│   ├── CALLBACK ⭐
│   │   ├── callback concept
│   │   ├── register callback
│   │   ├── invoke callback
│   │   ├── callback state
│   │   └── callback in driver
│   │
│   ├── Array of Function Pointers
│   │   ├── menu system
│   │   ├── command dispatcher
│   │   └── state machine
│   │
│   ├── typedef Function Pointer
│   │   ├── typedef
│   │   ├── callback type
│   │   └── readable APIs
│   │
│   └── Function Pointer + struct
│       ├── function table
│       ├── interface
│       └── driver abstraction
│
├── LEVEL 5 — EMBEDDED FRESHER ⭐⭐⭐
│   │
│   ├── Pointer + Struct
│   │   ├── struct *
│   │   ├── ->
│   │   ├── (*p).member
│   │   └── struct pointer parameter
│   │
│   ├── Function Pointer + Struct
│   │   ├── driver interface
│   │   ├── ops table
│   │   └── callback object
│   │
│   ├── Memory
│   │   ├── malloc
│   │   ├── calloc
│   │   ├── realloc
│   │   ├── free
│   │   └── memory ownership
│   │
│   ├── Buffer
│   │   ├── uint8_t *
│   │   ├── RX buffer
│   │   ├── TX buffer
│   │   └── buffer boundary
│   │
│   └── Ring Buffer
│       ├── head
│       ├── tail
│       ├── read pointer
│       └── write pointer
│
└── LEVEL 6 — EMBEDDED ADVANCED
    │
    ├── volatile + pointer
    │   ├── volatile uint32_t *
    │   └── memory-mapped register
    │
    ├── Register Access
    │   ├── peripheral base address
    │   ├── register pointer
    │   ├── struct mapping
    │   └── bit manipulation
    │
    ├── ISR / Interrupt
    │   ├── ISR callback
    │   ├── shared data
    │   └── volatile
    │
    ├── DMA
    │   ├── buffer pointer
    │   ├── DMA descriptor
    │   └── ownership
    │
    └── RTOS
        ├── callback
        ├── task argument void *
        ├── queue/buffer
        └── driver abstraction
```