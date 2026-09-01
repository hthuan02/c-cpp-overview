#include "list_singly.h"

int main ()
{
    int32_t val_pop_front,
            val_pop_back,
            val_delete_node,
            val_front,
            val_back,
            val_node_pos;

    Node_t *n1 = init_node(1);
    Node_t *n2 = init_node(2);
    Node_t *n3 = init_node(3);

    n1->next = n2;
    n2->next = n3;

    print_list_singly(n1);

    push_front(&n1, 111);
    push_back(&n1, 999);
    insert_node(&n1, 1234, 2);

    print_list_singly(n1);
    if (pop_front(&n1, &val_pop_front) == LIST_OK)
    {
        printf("Pop front node: %d\n", val_pop_front);
    }

    if (pop_back(&n1, &val_pop_back) == LIST_OK)
    {
        printf("Pop back node: %d\n", val_pop_back);
    }

    if (delete_node(&n1, &val_delete_node, 1) == LIST_OK)
    {
        printf("Delete position node: %d\n", val_delete_node);
    }



    print_list_singly(n1);
    if (get_front(n1, &val_front) == LIST_OK)
    {
        printf("Front node: %d\n", val_front);
    }

    if (get_back(n1, &val_back) == LIST_OK)
    {
        printf("Back node: %d\n", val_back);
    }

    if (get_node(n1, &val_node_pos,2) == LIST_OK)
    {
        printf("Any node position: %d\n", val_node_pos);
    }
    
    free_list_singly(&n1);
    return 0;
}