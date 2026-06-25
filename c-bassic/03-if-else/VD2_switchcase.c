/*************************************************** 
 * Nhập phép toán + 
 * Nhập vào 2 a,b: 1 
 * 
 * 1 +  2 = 3
 **************************************************/

#include<stdio.h>

int main()
{
    int n,a,b;
    char bieuthuc;

    printf("Nhập 2 số a & b: \n");
    scanf("%d%d",&a,&b);

    // Cần khoảng trắng trc `%c`
    // Để chương trình k hiểu là nhận Enter làm input mà skip đoạn sau của chương trình
    printf("Chọn phép tính: ");
    scanf(" %c",&bieuthuc); 


    switch(bieuthuc){
        case '+':
            printf("a + b = ?\n");
            printf("%d + %d = %d\n",a,b,a+b);
            break;

        case '-':
            printf("a - b = ?\n");
            printf("%d - %d = %d\n",a,b,a-b);
            break;
        
        case '*':
            printf("a * b = ?\n");
            printf("%d * %d = %d\n",a,b,a*b);
            break;

        case '/':
            printf("a / b = ?\n");
            printf("%d / %d = %d\n",a,b,a/b);
            break;

        case '%':
            printf("a %% b = ?\n");
            printf("%d %% %d = %d\n",a,b,a%b);
            break;

        default:
            printf("Nhập sai!, vui lòng thử lại!\n");
    }


    
}