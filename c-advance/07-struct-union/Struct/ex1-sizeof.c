#include <stdio.h>

#pragma pack(1) // cấp phát từng byte 1
typedef struct 
{
    char ID;        // 1
    int class;      // 4
    double student; // 8
}student_t;

#pragma pack()

int main ()
{
    student_t name;
    printf("Size of struct: %d\n", sizeof(name)); // 13

}