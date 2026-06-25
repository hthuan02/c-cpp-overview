/**
 *  Tách chuỗi "20/03/2021" 
 * -> Lưu vào và in ra 3 biến: Ngày, Tháng, Năm. 
 * 
 */

#include <stdio.h>
#include <string.h>

int main()
{
    char s1[] = "20/03/2021";
    char ngay[3];
    char thang[3];
    char nam[5];

    int dem = 0;

    char *token = strtok(s1,"/");

    while(token != NULL)
    {
        if(dem == 0)
            strcpy(ngay,token);
        
        else if(dem == 1)
            strcpy(thang,token);

        else if(dem == 2)
            strcpy(nam,token);
        
        dem++;
        token = strtok(NULL, "/");
    }

    printf("Ngày: %s\n",ngay);
    printf("Tháng: %s\n",thang);
    printf("Năm: %s\n",nam);

    return 0;
}


