// Tách chuỗi "Huynh Minh Thuan"

#include <stdio.h>
#include <string.h>

void tachChuoi(char *s1, char *ho, char *chulot, char *ten)
{
    char *token = strtok(s1," ");
    int dem = 0;

    while(token != NULL) // Duyệt đến khi nào chuỗi = NULL thì thoát while
    {   
        if(dem == 0)
            strcpy(ho,token);

        else if (dem == 1)
            strcpy(chulot,token);

        else if (dem == 2)
            strcpy(ten,token);

        dem ++;
        token = strtok(NULL," ");
        
    }
}

int main ()
{
    char s1[] = "Huynh Minh Thuan"; // mảng tự động được tính theo chuỗi khởi tạo
    char ho[6];
    char chulot[5];
    char ten[6];
    

    printf("Huynh Minh Thuan\n");
    
    tachChuoi(s1,ho,chulot,ten);

    printf("Họ: %s\n",ho);
    printf("Chữ lót: %s\n",chulot);
    printf("Tên: %s\n",ten);

    return 0;
}