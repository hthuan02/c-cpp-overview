## SUMMARIZE
1. _OK Bit manipulation (set/reset/check/toggle & packing/unpaking/bitmask)
2. Macro (val/fucn/variadic)
3. _OK Storage classes (extern/static/volatile/register)
4. _OK Struct/Union/Enum/bitfiled (sizeof)
5. _OK Kết hợp với bit field (union(struct())/field struct/field union)
6. _OK Pointer (void/func/ptr-ptr/ptr-const/const-to-ptr/null/array/operator/sizeof)
7. _OK Memory layout (Read only/Read-Write segment)
8. _OK DSA (string/array/list/stack/queue & sort/search)

---

## CAUTION
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
# IDEAS FOR FUTURE PROJECT VIHICLES ECU
# Version 1.0
## Cruise Control: kiểm soát giới hạn tốc độ lái
## giới hạn tốc độ tùy theo tuyến đường
## Tạo log cho mỗi data

## VD: tuyến đường gồ gề 40km/h - ghi lại thời gian real-time
#      tuyến đường bình thường 60km/h - realt-ime

# Version 2.0
# GGMAP-Cruise Control