#include <stdio.h>
#include <stdint.h>
#include <string.h>

// Union có struct lồng vào, dùng để cập nhật dữ liệu liên tục
typedef union 
{
    struct 
    {   
        // Thiết kế uint8_t, thông tin dạng array
        // Tối ưu bộ nhớ nhất có thể không bị padding 
        uint8_t id[2];          //2
        uint8_t data[4];        //4
        uint8_t check_sum[2];   //2
    } Data_t;
    
    uint8_t frame[8];
} DataFrame_t;

// 0xa0 0xa1 0xa2 0xa3 0xa4 0xa5 0xa6 0xa7
// trong union có 2 biến: struct và frame
// --> Do union sử dụng chung vùng nhớ
// --> Khi id/data/check_sum thay đổi thì framơe[] thay đổi

int main ()
{
    DataFrame_t transmit_data = {0};
    memcpy(transmit_data.Data_t.id, "12",2);
    memcpy(transmit_data.Data_t.data, "1234",4);
    memcpy(transmit_data.Data_t.check_sum, "77",2);

    DataFrame_t receive_data = {0};
    memcpy (receive_data.frame,
            transmit_data.frame,
            sizeof(transmit_data.frame));


    return 0;
}