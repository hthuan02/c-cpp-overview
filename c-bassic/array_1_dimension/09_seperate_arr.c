#include <stdio.h>

int main ()
{
    int arr[] = {1,2,3,4,5,6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int  index = 2;

    int s1[10],
        s2[10],
        n1 = 0,
        n2 = 0;
    
    for (int i = 0; i < index; i++)
    {
        s1[n1++] = arr[i];
    }
    // printf("%d", n1);

    for (int j = index; j < n; j++)
    {
        s2[n2++] = arr[j];
    }
    
    for (int k = 0; k < n1; k++)
    {
        printf("mang[%d] = %d\n",k, s1[k]);
    }
    
    printf("\n");
    for (int i =0; i < n2; i++)
    {
        printf("mang[%d] = %d\n",i, s2[i]);
    }
    
    
    
    return 0;
}