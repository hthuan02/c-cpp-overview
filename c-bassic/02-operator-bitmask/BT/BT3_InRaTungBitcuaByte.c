#include<stdio.h>
#include<string.h>

int main()
{

    unsigned char x = 0b11101110;
    unsigned char y;
    // Kiểm ra bit thứ 7 -> Tạo 1 bitmask (bit 0)
    //          0b00000001
    // (1<<7)   0b10000000  AND (&)
    //   x      0b11101110
    //-------------------------
    //   KQ     0b10000000 -> in ra giá trị thập phân 128
    //   Để in ra dạng logic 0|1 thì `!=0`

    for(int i = 7;i >= 0;i--)
    {   
        y = ((1 << i) & x) != 0;
        printf("Bit %d: %d\n",i,y);
    }


        return 0;
}

