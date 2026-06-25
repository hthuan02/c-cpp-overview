// Viết 1 hàm phải pt bậc I, truyền vào các đối số và trả về kq
// ax + b = 0
// Nếu a = 0
//       b == 0, vsn
//       b != 0, vn
// Nếu a != 0, có nghiệm x = -b/a

#include <stdio.h>
#include <stdlib.h>

void nhap2so(float *a, float *b)
{
    printf("Nhập 2 số a,b:\n");
    scanf("%f %f",a,b);
    printf("PT Bậc I: %gx + %g = 0\n",(*a),(*b));
}

float giaiPTbac1(float a,float b)
{   
    float x;
    if (a == 0)
    {
        if(b == 0) printf("PT Vô số nghiệm.\n");

        else printf("PT vô nghiệm!\n");
    }
    else x = -b / a;

    return x;
}

int main()
{   
    float a,b;
    float KQ;
 
    nhap2so(&a,&b);

    KQ = giaiPTbac1(a,b);

    if(a!=0) printf("PT có nghiệm: x = %g\n", KQ);
    
    return 0;
}