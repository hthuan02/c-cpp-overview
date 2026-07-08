#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    Node *next;
}Node;

Node* create_node(int newdata)
{
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = newdata;
    node->next = NULL;

    return node;
}

// Hàm thêm node ở vị trí đầu
void push_front(int **head, int data)
{
    Node *new_node = create_node(data);

    if(*head == NULL)
    {
        *head = new_node;
    }

    else
    {
        new_node->next = *head;
        *head = new_node;
    }
    
}


int main ()
{
    Node *node1 = create_node(5);
    Node *node2 = create_node(6);
    Node *node3 = create_node(7);

    node1->next = node2;
    node2->next = node3;

    return 0;
}