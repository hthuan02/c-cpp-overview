#include "list.h"

int main ()
{
    node_t *n1 = create_node(5);
    node_t *n2 = create_node(6);
    node_t *n3 = create_node(7);

    // Liên kết *next
    n1->next = n2;
    n2->next = n3;

    // push_front(&n1, 100);
    // push_back(&n1, 200);
    // insert(&n1, 300, 0);
    // insert(&n1, 400, 6);
    // insert(&n1, 500, 7);
    // insert(&n1, 600, 8);
    display(n1);

    // printf("Size of list: %d\n", size(n1));
    // printf("Node 1: %d\n", front_list(n1));
    // printf("Finally Node: %d\n", back_list(n1));
    // printf("Any Node: %d\n", get_list(n1,3));

    // pop_front(&n1);
    pop_back(&n1);
    display(n1);

    return 0;
}