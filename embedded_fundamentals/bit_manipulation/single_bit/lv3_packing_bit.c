/* VD: Hệ thống embedded(Robot) mỗi chuyển động cần rất nhiều tín hiệu từ nhiều cảm biến hoặc động cơ
 * Nhưng mỗi tín hiệu truyền/nhận chỉ 1 bit, mà nó truyền/nhận 1 lần là 8 bit/1 byte
 * ---> Như vậy sẽ tốn bộ nhớ, nên packing dữ liệu giúp mình tôi ưu bộ nhớ, tăng hiệu suất
 * 
 * Còn unpacking dữ liệu là để lấy dữ liệu con ra dễ debug, dễ đọc, dễ maintain
 **/

#include <stdio.h>
#include <stdint.h>

uint8_t packing_bit(uint8_t enable, uint8_t direction, uint8_t fault)
{
    uint8_t status_bit = 0;

    status_bit = (enable << 0)
               | (direction << 1)
               | (fault << 2);

    return status_bit;
}

int main ()
{
    uint8_t enable = 1;
    uint8_t direction = 0;
    uint8_t fault = 1;

    uint8_t val_packing_bit = packing_bit(enable, direction, fault);

    printf("0x%02x\n", val_packing_bit);
    // 0x05 // 0b00000101

    return 0;
}