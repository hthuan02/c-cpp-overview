#include "list.h"

int main ()
{   
    // Khởi tạo node 
    Node *node1 = create_note(5); // 0x01 --> (data=5, ptr=NULL)
    Node *node2 = create_note(6); // 0xa1     (data=6, ptr=NULL)
    Node *node3 = create_note(7); // 0xe1     (data=7, ptr=NULL)

    // Liên kết node
    node1->next = node2;
    node2->next = node3;


    return 0;
}