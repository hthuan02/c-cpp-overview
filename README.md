## SUMMARIZE
1. Bit manipulation (set/reset/check/toggle & packing/unpaking/bitmask)
2. Macro (val/fucn/variadic)
3. Storage classes (extern/static/volatile/register)
4. Struct/Union/Enum (sizeof)
5. Kết hợp với bit field (union(struct())/field struct/field union)
6. Pointer (void/func/)
7. Memory layout
8. DSA (string/array/list/stack/queue & sort/search)

---

## CAUSTION
### 1. 3.55 & 3.55f

```c
    float a = 3.55; // 3.55 (double)
    // data_type float, compiler chuyển double -> float
```

```c
    float a = 3.55f; // 3.55f -> (float)3.55 --> HẰNG SỐ THẬP PHÂN FLOAT
    // Không cần chuyển đổi từ double -> float
```

### 2. Overflow (Tràn số)

- Cố ghi 300(int) vào char
- char (1byte-256) có giá trị từ 0-255
```c
    // 300 - 256 = 44
    // giá trị của char là 44
``` 


