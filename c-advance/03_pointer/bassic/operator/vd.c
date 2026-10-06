/**
 *  p++: thực hiện lệnh trước, tăng sau câu lệnh
 *  ++p: tăng lên trước, thực hiện lệnh sau
 *  p--: thực hiện lệnh trước, giảm sau câu lệnh
 *  --p: giảm trước, thực hiện lệnh sau
 */

/** GIÁ TRỊ
 *  (*p)++: lấy giá trị cũ thực hiện lệnh, sau lệnh tăng giá trị thêm 1
 *  ++(*p): tăng giá trị thêm 1 lên trước, thực hiện lệnh sau
 *  (*p)--: lấy giá trị cũ trước thực hiện lệnh, giảm 1 giá trị sau lệnh
 *  --(*p): giảm 1 trước, thực hiện lệnh sau
 */

/** ĐỊA CHỈ
 *  *p++, ++*p, *p--, --*p
 *   => Thực hiện tương tự, nhưng 4 câu lệnh này làm việc với địa chỉ
 */


#include <stdio.h>

void process(int *p)
{
    if (p == NULL)
    {
        return;
    }
                // p = &arr[0] ... (int *)
    (*p)++;     // arr[0]=10, sau lệnh arr[0]=11
    p++;        // arr[0]=11 -> sau lệnh: p = &arr[1]
    (*p)++;     // arr[1]=20, sau lệnh arr[1]=21
}

int main()
{
    int arr[] = {10, 20, 30};

    process(arr);

    printf("%d %d %d\n",
           arr[0],      //11
           arr[1],      //21
           arr[2]);     //30

}