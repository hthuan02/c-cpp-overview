#include "list.h"

int main ()
{
    Node_t *n1 = create_node(1);
    Node_t *n2 = create_node(2);
    Node_t *n3 = create_node(3);

    n1->next = n2;
    n2->next = n3;

    push_front(&n1, 111);
    push_back(&n1, 999);
    insert_positon(&n1, 12345, 2);

    print_list(n1);
    free_list(&n1);

    return 0;
}