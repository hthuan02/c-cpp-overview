#include <stdio.h>
#include <stdint.h>

typedef union
{
    uint64_t value; // 8 byte
    uint8_t byte;   // 1 byte
} data_t;

int main()
{
    data_t data;

    data.value = 0x12345678;

    /* 0x78: LSB(Least Significant Bit): Trọng số thấp nhất
     * 0x12: MSB(Most Significant Bit): Trọng số cao nhất
     * 0x00 0x00 0x00 x00 0x12 0x34 0x56 0x78
     * --> Ta có: 4 cặp bit tương ứng với kiểu dữ liệu lớn nhất là int 4 byte
     * data.byte = 0x78
     * data.value = 0x12345678
     * 
     */

    printf("value = 0x%X\n", data.value);   
    printf("byte  = 0x%X\n", data.byte);


    return 0;
}