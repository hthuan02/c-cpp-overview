#include <stdio.h>
#include <stdint.h>

typedef struct
{
    uint8_t  a : 3;     // 1byte (3bit)
    uint16_t b : 5;     // 2byte (8bit)
    uint16_t e : 3;
    // uint32_t c : 10;    // 4 byte (10bit)
}Test_t;

// tổng kích thước struct 8 byte (1 pad)
// 21 bit - còn lại chưa sử dụng

int main ()
{
    Test_t s1;

    printf("%d\n", sizeof(Test_t));

    return 0;
}