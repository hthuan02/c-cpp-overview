#include <stdio.h>
int main ()
{
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr) / sizeof(arr[0]);

    int val_new = 12345;
    //ghi trước
    arr[n] = val_new;
    n++;

    // print_array
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    

    return 0;
}