#include <stdio.h>

int main ()
{   
    int arr[5] = {55,32,11,5,111};
    int n = sizeof(arr)/sizeof(arr[0]);
    int new_arr=12345;
    // dịch phải, for--
    // ghi new_front_arr
    // tăng arr

    for (int i = n; i > 0; i--)
    {
        arr[i] = arr[i -1]; 
    }
    
    arr[0] = new_arr;
    n++;

    // print_array
    for (int i = 0; i < n; i++)
    {
        printf("mang[%d] = %d\n",i, arr[i]);
    }
    

    return 0;
}