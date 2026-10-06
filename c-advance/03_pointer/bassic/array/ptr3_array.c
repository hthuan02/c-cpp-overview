#include <stdio.h>

int main ()
{
    int a = 10;
    int b = 20;

    int *arr[2] = {&a, &b}; 
    
    // int *arr[0] = &a
    // int *arr[1] = &b
    int **pp = arr; // &arr[0]

    // *pp = arr[0] = &a
    // **pp = a = 10
    // *(pp + 1) = arr[1] = &b
    // **(pp + 1) = b = 20

    return 0;
}
