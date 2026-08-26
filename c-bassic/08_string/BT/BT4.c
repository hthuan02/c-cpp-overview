/**
 *  Xóa bỏ khoảng trắng trong chuỗi "Deviot hoc that, lam that, dao tao that"
 *  Và in ra chuỗi liền  
 *  
 *  Muốn xóa khoảng trắng ' ' -> Ghi đè ' ' bằng tất cả phần tử ở sau lên phần tử đó 
 *  strspy() 
 *  
 */

#include <stdio.h>
#include <string.h>

void xoaKhoangTrang(char s1[], int index)
{   
    // muốn xóa từ chỗ nào thì bắt đầu từ chỗ đó, xóa từ vị trí khoảng trắng 5
    for(int i = index;i < strlen(s1);i++)
    {   
        // ghi đè tất cả phần tử phía sau dồn lên trc 1 phần tử 
        // "Minh Thuan" -> ghi đè lên " " vị trí s1[5]
        s1[i] = s1[i+1]; 

    }

    // có đc giá trị index
}


int main()
{
    char s1[] = "Huynh Minh Thuan";

    // Tìm vị trí khoảng trắng trong chuỗi để xóa
    char *token = strstr(s1," ");

    while(token != NULL)
    {
        int index = token - s1; // tìm index vị trí của khoảng trắng // 5 -> truyền vào hàm
        xoaKhoangTrang(s1,index);   // thực hiện ghi đè ra trc 1 đơn vị
        printf("%s\n",s1);          
        token = strstr(s1, " ");    // lặp lại, tìm khoảng trắng tiếp theo để xóa 
    }
    
    

    return 0;
}