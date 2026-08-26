#include <stdio.h>

void nhapten(void)
{
    char ten[30];
    printf("Nhập tên: ");
    scanf("%s",ten);
    printf("Tên: %s\n",ten);
}

int nhaptuoi(void)
{
    int tuoi;
    printf("Nhập tuổi: ");
    scanf("%d",&tuoi);
    return tuoi; // return về cái biến mình khởi tạo, giá trị trả về 1 số

}

int main ()
{   
    int tuoithucte; // tạo biến tuoithucte, để gán giá trị return
    nhapten();
    tuoithucte = nhaptuoi(); 
    printf("Tuổi: %d\n",tuoithucte);

    return 0;
}