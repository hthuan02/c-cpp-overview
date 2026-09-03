#include <stdio.h>

int main ()
{
    int arr1[] = {1,2,3,4,5};
    int arr2[] = {6,7,8,9};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    int arr[50] ={0};
    int num = 0;

    for (int i = 0; i < n1; i++)
    {
        arr[num++] = arr1[i];
    }

    for (int i = 0; i < n2; i++)
    {
        arr[num++] = arr2[i];
    }

    for (int i = 0; i < num; i++)
    {
        printf("%d ", arr[i]);
    }    

    return 0;
}