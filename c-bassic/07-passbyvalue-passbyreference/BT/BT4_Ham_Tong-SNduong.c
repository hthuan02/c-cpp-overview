/**
 *  Viết hàm nhận vào số nguyên dương n, tính:
 * 
 *  S = 1 + 2 + ... + n
 *  S = 1^2 + 2^2 + ... + n^2
 */

#include <stdio.h>

void nhapSoNguyen(int *n)
{
    printf("Nhập số nguyên: n = "); scanf("%d",n);
}

/**
 * Dùng hàm void(<tham số>) hoặc int(<tham số>) đều được
 */

int tongN(int n, int S)
{
    for(int i = 1;i <= n;i++)
    {
        printf(" %d",i);
        S = S + i;
    }
    return S;
}

void tongN_binhPhuong(int n, int S)
{
    for(int i = 1;i <= n;i++)
        S = S + i*i;

    printf("\nS = %d\n",S);
}


int main()
{   
    int n, S = 0;
    int tongKq;

    nhapSoNguyen(&n);

    tongKq = tongN(n,S);
    printf("\nS = %d",tongKq);

    tongN_binhPhuong(n,S);

    return 0;
}