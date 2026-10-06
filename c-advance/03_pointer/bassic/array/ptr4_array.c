#include <stdio.h>

int main ()
{
    char *names[] = {
        "Alice",
        "Bob",
        "Charlie"
    };

    char **pp = names;

    // *pp = names[0] = Alice
    // *(pp + 1) = name[1] = Bob
    // *(pp + 2) = name[2] = Charlie

    return 0;
}