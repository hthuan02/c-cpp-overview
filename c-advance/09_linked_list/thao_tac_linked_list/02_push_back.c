// Hàm thêm 1 node ở cuối List
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
 * Thêm node vào cuối list:
 * - Duyệt danh sách (!= NULL), while((*head)->next != NULL)
 *       Tìm con trỏ *next của node cuối (==NULL), *head = (*head)->next
 * - Thay đổi *next của node cuối danh sách để = node mới
 *  
 *  Node4
 *   0xa1 
 *    111
 *   NULL
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

// Hàm thêm phần tử đầu list
void push_front(Node **head, int value)
{
    Node *new_node = createNode(value);

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

// Hàm thêm 1 Node ở cuối  List
void push_back(Node **head, int value)
{
    Node *new_node = createNode(value);

    if (*head == NULL)
    {
        *head = new_node;
    }
    else
    {   
        // Duyệt danh sách, phải dùng con trỏ cấp 1 để duyệt
        // Hoặc tạo con trỏ phụ: 
        // Node *temp = *head
        // while(temp->next != NULL)...
        Node *temp = *head;
        while (temp->next != NULL)
        {
            // Duyệt danh sách để node trỏ đến node tiếp theo
            // node1 trỏ node2, node2 trỏ node 3... đến *next của Node == NULL, là đến node cuối
            temp = temp->next;
        }
        
        // Thay đổi *next của cuối danh sách để trỏ đến node mới
        temp->next = new_node;
    }
}

void print_list(Node *head)
{
    int index = 0;

    if(head == NULL)
    {
        printf("Không có node!\n");
    }
    else    
    {
        while (head != NULL)
        {
            printf("Node %d: %d\n", index, head->data);

            // Trỏ đến node tiếp theo
            head = head->next;
            index++;
        }
        

    }
    
}

int main(int argc, char const *argv[])
{
    Node *n1 = createNode(5);
    Node *n2 = createNode(6);
    Node *n3 = createNode(7);

    n1->next = n2;
    n2->next = n3;

    // Truyền vào node đầu tiên, vì nó chứa *head
    // Trỏ đến *head đại diện cả danh sách
    print_list(n1); 
    push_front(&n1,2222);
    push_back(&n1,111);

    printf("\n");
    print_list(n1);

    return 0;
}
