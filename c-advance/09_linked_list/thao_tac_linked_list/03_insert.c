// Hàm thêm 1 node ở đầu List
/**
 *    0           1                   2           3
 *  Node1       Node2               Node3       Node4
 *   0xaa        0xb3     XXXXXX     0xe1        0xa1
 *     2           5                  7          12
 *   0xb3        0xe1                0xa1        NULL
 * 
 *   [Node mới] 
 *      0xb5
 *       111
 *      NULL  <-- *next = NULL
 * 
 * Thêm node vào (index = 2):
 *  - pos == 0 --> giống push front list
 *  - index < pos-1  --> Duyệt list, kiểm tra node để tìm đến vị trí index 
 *              - gán *next của new_node = 0xe1
 *              - *head = new_node
 * 
 *  Node1
 *   0xb5  <-- *head
 *    111
 *   0xaa
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *createNode(int data)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;

    return temp;
}

// Hàm thêm 1 node ở vị trí bất kỳ trong List
void insert(Node **array, int value, int pos)
{
    Node *new_Node = createNode(value);
    Node *p = *array;
    int index = 0;

    // Nếu thêm vị trí đầu
    if (pos == 0)
    {
        new_Node->next = *array;
        *array = new_Node;
        return;
    }

    // Duyệt qua list đến vị trí pos-1 (trước new_Node)
    while (p != NULL && index < pos - 1)
    {
        p = p->next;
        index++;
    }

    // Node 0 - Node 1 -0xC9- Node 2 - Node3
    // Nếu đã tìm được vị trí hợp lệ

    // Thêm điều kiện p!=NULL để đánh tình trạng pos > list --> CRASH CHƯƠNG TRÌNH
    // Cập nhật *next
    if (p != NULL && index == pos - 1)
    {
        new_Node->next = (p->next); // *next Node mới muốn thêm vào (gán) = *next của node cuối list đã duyệt bên trên
        p->next = new_Node;         // trỏ *next của node mới đến node tiếp theo trong list
    }
}

void printlist(Node *array)
{
    Node *p = array;
    int i = 0;

    while (p != NULL)
    {
        printf("Node = %d - Data = %d\n", i, p->data);
        p = p->next;
        i++;
    }
}

int main(int argc, char const *argv[])
{
    Node *n1 = createNode(5);
    Node *n2 = createNode(6);
    Node *n3 = createNode(7);

    n1->next = n2;
    n2->next = n3;

    insert(&n1, 1000, 3);
    printlist(n1);
    return 0;
}
