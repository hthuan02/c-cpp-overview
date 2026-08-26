#include <stdio.h>

int main ()
{
    int arr1[] = {1,2};
    int arr2[] = {4,5,6};
    int s1[10], num = 0;

    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    for (int i = 0; i < n1; i++)
    {
        s1[num++] = arr1[i];
    }

    for (int i = 0; i < n2; i++)
    {
        s1[num++] = arr2[i];
    }
    
    for (int i = 0; i < num; i++)
    {
        printf("mang[%d] = %d\n",i, s1[i]);
    }
    
    

    return 0;
}