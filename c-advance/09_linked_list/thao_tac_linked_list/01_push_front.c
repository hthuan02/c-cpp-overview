// Hàm thêm 1 node ở đầu List
/**
 *  Node1       Node2       Node3
 *   0xaa        0xb3        0xe1
 *     2           5           7
 *   0xb3        0xe1        0xa1
 * 
 *   [Node mới]
 *      0xb5
 *       111
 *      NULL  <-- *next = NULL
 * 
 * Thêm node vào đầu list:
 * - Thay đổi con trỏ *next của node mới --> *next = 0xaa =*head
 * - Cập nhật lại *head của danh sách *head=0xaa --> Thay đổi thành *head = 0xb5 = new_node
 * 
 *  Node1
 *   0xb5  <-- *head
 *    111
 *   0xaa
 */

#include <stdio.h>
#include <stdlib.h>

// struct kiểu Node
typedef struct Node
{
    int data;
    Node *next;
}Node;

// Prototype
Node* create_node(int newdata);
void push_front(Node **array, int value); //Thêm 1 node có giá trị value đầu danh sách
/**
 *  - Tham số truyền vào con trỏ cấp 1: Thay đổi giá trị/địa chỉ trỏ tới của 1 biến (biến đó không phải là con trỏ)
 *  - Tham số truyền vào con trỏ cấp 2: Biến gốc `*head` là 1 con trỏ rồi, thay đổi địa chỉ trỏ đến con trỏ cấp 1 `*head` --> con trỏ cấp 2
 *  --> Nếu dùng lại con trỏ cấp 1: Chỉ là sao chép dữ liệu 
 */

int main ()
{
    Node *node1 = create_node(5);
    Node *node2 = create_node(6);
    Node *node3 = create_node(7);
    
    node1->next = node2;
    node2->next = node3;

    return 0;
}

// Hàm khởi tạo node, lưu toàn bộ node ở heap
Node* create_node(int newdata)
{
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = newdata;
    node->next = NULL;

    // return địa chỉ node
    return node;
}

// Hàm thêm phần tử đầu list
void push_front(Node **head, int value)
{
    Node *new_node = create_node(value);

    // Kiểm tra địa chỉ của con trỏ cấp 1, danh sách có rỗng hay không
    if (*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        new_node->next = *head;
        *head = new_node;
    }
    

}