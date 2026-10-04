#include <stdio.h>

int main ()
{
    int x = 10;
    int *p = &x;
    int **pp = &p;

    // (*pp)++; // *pp = p = &x: lấy địa chỉ trước, sau lệnh tăng đến vùng nhớ tiếp theo

    *(*pp)++; // *pp = p = &x -> *(*pp) = **pp

    (**pp)++;// **pp = *p = x: lấy data trước, sau lệnh tăng data lên 1 **pp = 11



    return 0;
}