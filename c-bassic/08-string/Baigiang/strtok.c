#include<stdio.h>
#include<string.h>

int main ()
{
    char s1[] = "22/11/2025";
    char ngay[3];
    char thang[3];
    char nam[5];

    printf("22/11/2025\n");

    // token: tạm gọi là các chuỗi 
    char *token = strtok(s1,"/"); // tách chuỗi "22/11/2025" -> "25", kí tự đặc biệt phân rẽ tách "/"
    int dem = 0;

    while(token != NULL) // token duyệt tới vùng nhớ có giá trị -> không có giá trị THOÁT
    {   
        if (dem == 0)
            strcpy(ngay,token);

        else if (dem == 1)
            strcpy(thang,token);

        else if(dem == 2) // else là dành cho tất cả trường hợp còn lại // else if là TH thứ 3
            strcpy(nam,token);

        dem++;
        token = strtok(NULL, "/"); // NULL, có nghĩ là truyền chuỗi tiếp theo để tách "11/2025"
    }

    printf("Ngày: %s\n",ngay);
    printf("Tháng: %s\n",thang);
    printf("Năm: %s\n",nam);

    return 0;
}