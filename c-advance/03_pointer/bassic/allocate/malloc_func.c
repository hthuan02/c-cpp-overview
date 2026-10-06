
#include <stdio.h>
#include <stdlib.h>

void allocate(int **p){
    *p = (int*)malloc(sizeof(int));
}
int main ()
{
    int *p = NULL;

    allocate(&p);
    *p = 100;

    free(p);
    return 0;
}