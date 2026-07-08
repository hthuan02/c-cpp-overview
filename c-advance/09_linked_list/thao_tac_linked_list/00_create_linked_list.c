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

    // Trả về địa chỉ node
    return node;
}

int main ()
{   
    // Khởi tạo node
    Node *node1 = create_node(5); // giả sử địa chỉ 0x01 (5, NULL)
    Node *node2 = create_node(6); // 0xa1 (6, NULL)
    Node *node3 = create_node(7); // 0xe1 (7, NULL)

    // Liên kết node
    node1->next = node2;
    node2->next = node3;

    return 0;
}