/** 
 * Nhập 1 số nguyên bất kỳ và in ra các chữ số chẵn, chữ số lẻ
 * VD: Nhập 12345677654 // Mỗi số là duy nhất không lặp lại
 * => Số chẳn: 2 4 6
 * => Số lẻ: 1 3 5 7
 */

/*--------------------------- THUẬT TOÁN TÁCH SỐ (ĐƠN VỊ, CHỤC, TRĂM,...) -------------------------*/
/** 
 *  duyệt số > 0 (==0 thì thoát)
 *  VD: n =  3451
 *  var = n % 10 = 1 (tách được số 1 - hàng đơn vị)
 *
 *  num[0,1,2,3...9] => num[1] = 1 (số 1 đã xuất hiện rồi) 
 *  3451 / 10 = 345
 * 
 *  Lặp lần 2: n = 345 
 *  var = n = 345 % 10 = 5 (tách số 5- hàng chục)
 *  num[5] = 1 (số 5 đã xuất hiện)
 *  345 / 10 = 34
 * 
 *  Lặp lần 3: n =34
 *  var = n = 34 % 10 = 4
 *  num[4] = 1 (sô 4 đã xuất hiện)
 *  34 / 10 = 3
 * 
 *  Lặp lần 4: n = 3
 *  var = n = 3 % 10 = 3
 *  num[3] = 1 (số 3 đã xuất hiện)
 *  n = 3 / 10 = 0  -> THOÁT while
 * 
 *  => 1 3 4 5
 */

#include <stdio.h>

void nhapSoTN(int *n)
{
    printf("Nhập số vào số nguyên n: "); scanf("%d",n);

}

void tachSo(int n, int num[])
{
    for(int i = 0;i < 10;i++)
        num[i] = 0;       // (0->9) = 0, chưa xuất hiện
    
    while(n > 0)
    {   
        // n: là giá trị nhập vào
        // num: là giá trị đã xử lý -> truyền tham trị num là để cho hàm sau xử lý
        int var;
        var = n % 10;    // tách số hàng đơn vị
        num[var] = 1;    // (0->9) = 1, đã xuất hiện => Ngăn việc in ra số bị trùng lặp
        n = n / 10;      // Sau khi tách được r, thì loại bỏ số hàng đơn vị, chục, trăm,... cho đến khi = 0 -> thoát while
    }
}

void inSoChan(int num[])
{   
    printf("Số chẳn: ");
    for(int i = 0;i < 10;i++)
    {
        if(num[i] && i % 2 == 0)
            printf(" %d",i);
    }
    printf("\n");
}

void inSoLe(int num[])
{   
    printf("Số lẻ: ");
    for(int i = 0;i < 10;i++)
    {
        /**
         *  Kiểm tra num[i] xuất hiện hay chưa "và" i là số lẻ khác 0
         *  Nếu đổi thứ tự if(i & num[i] != 0) // kiểm tra i xuất hiện hay chưa và num[i] %2 !=0 -> SAI
         * 
         * => Không có chuyện kẹp điều kiện "Và" // num[i] và i%2 !=0 -> SAI
         */
        if(num[i] && i % 2 != 0)
            printf(" %d",i);
    }

}

int main ()
{
    int n;
    int num[10]; // 0 1 2 3...8 9 // num[]
    nhapSoTN(&n);

    tachSo(n,num);
    inSoChan(num);
    inSoLe(num);
    
    return 0;
}