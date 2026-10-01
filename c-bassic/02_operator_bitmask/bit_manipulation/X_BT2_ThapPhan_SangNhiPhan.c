#include<stdio.h>
#include<string.h>

int main()
{

    unsigned char x,b7,b6,b5,b4,b3,b2,b1,b0;
    printf("Nhập số thập phân 0-255: ");
    // Không nên dùng scanf với %d
    // Vì kiểu là unsigned char 1 byte mà định dạng %d ~ 4 byte rồi
    // Dùng kiểu 
    scanf("%hhu",&x);

    if ( x > 0 && x <= 255)
    {
        b7 = (x/128) %2;
        b6 = (x/64) % 2;
        b5 = (x/32) % 2;
        b4 = (x/16) % 2;

        b3 = (x/8) % 2;
        b2 = (x/4) % 2;
        b1 = (x/2) % 2;
        b0 = x % 2;

        printf("Số nhị phân: %d%d%d%d %d%d%d%d\n",b7,b6,b5,b4,b3,b2,b1,b0);
    }
    else
        printf("Ngoài vùng giá trị, vui lòng nhập lại\n");

    
    return 1;
}

// Hạn chế, chưa xử lý được việc nhập số vượt ngưỡng cho phép (0-255)
// Để khắc phục phải dùng if-else, while,...đệ quy