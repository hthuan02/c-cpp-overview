#include <stdio.h>

typedef enum 
{
    STACK_OVER_FLOW,
    MEMORY_LEAK,
    PARAM_INVALID,
    OK
}status_t;

status_t tinhsodiemthi(int diemthi)
{
    if(diemthi < 0 || diemthi > 10)
    {
        return PARAM_INVALID;
    }

    if (diemthi < 5)
    {
        printf("Fail\n");
    }

    else if(diemthi > 5)
    {
        printf("Pass\n");
    }

    return OK;
}

int main ()
{
    status_t err;
    int diemthi;

    while (1)
    {
        printf("Enter score:");
        scanf("%d", &diemthi);

        err = tinhsodiemthi(diemthi);
        
        if (err == PARAM_INVALID)
        {
            printf("Data input invalid!\n");
        }

    }
        


    return 0;
}