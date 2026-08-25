#include "list.h"

int main ()
{
    Node_t *n1 = create_node(1);
    Node_t *n2 = create_node(2);
    Node_t *n3 = create_node(3);

    n1->next = n2;
    n2->next = n3;

    print_list(n1);

    push_front(&n1, 111);
    push_back(&n1, 999);
    insert_node(&n1,1234,2);

    pop_front(&n1);
    pop_back(&n1);
    delete_node(&n1, 1);
    // delete_node(&n1, 2);

    print_list(n1);
    printf("Get front node: %d\n", get_front(n1));
    printf("Get back node: %d\n", get_back(n1));
    printf("Get any node: %d\n", get_node(n1,0));
    printf("Get any node: %d\n", get_node(n1,1));
    printf("Get any node: %d\n", get_node(n1,2));

    return 0;
}