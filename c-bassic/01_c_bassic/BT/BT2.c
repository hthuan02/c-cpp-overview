 /*******************************************************************
 * BT2: Viết chương trình đọc từ bàn phím 3 số nguyên biểu diễn ngày,
 * tháng, năm và xuất ra màn hình dưới dạng "dd/mm/yyy".
 *******************************************************************/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned char ngay, thang;
    int nam;

    printf("Địa chỉ của ngày tren RAM: %d\n",&ngay);
    printf("Địa chỉ của tháng tren RAM: %d\n",&thang);
    printf("Địa chỉ của năm tren RAM: %d\n",&nam);

    printf("Nhập ngày, tháng, năm;\n");
    scanf(" %c", &ngay);

    // Phải xài lệnh xóa bộ đệm ngay đây, vì dính 2 %c nên nó lưu lại 
    // nhận nút Enter làm giá trị, nên nó bị bỏ qua câu lệnh tiếp theo
    scanf(" %c", &thang); // có cách 1 cái, báo scanf loại bỏ khoảng trắng trc đó, k nhận ENTER làm giá trị
    scanf("%d", &nam);

    printf("%c/%c/%d",ngay,thang,nam);

    return 0;
}