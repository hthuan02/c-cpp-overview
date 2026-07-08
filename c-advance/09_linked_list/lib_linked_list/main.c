#include "list.h"

int main ()
{
    Node *n1 = create_node(5);
    Node *n2 = create_node(6);
    Node *n3 = create_node(7);

    n1->next =n2;
    n2->next =n3;

    push_front(&n1,100);
    display(n1);




    return 0;
}