#include "list.h"

Node* create_note(int newData)
{
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = newData;
    node->next = NULL;

    return node;
}