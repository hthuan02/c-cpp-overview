#ifndef __LIST_H
#define __LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
   int data; 
   Node *next;
    
} Node;

// void create_node(Node *node, int newData); // kiểu trả về là void, 2 tham số
Node* create_note(int newData); // kiểu trả về là con trỏ của kiểu Node khai báo ở struct, 1 tham số
// Sự khác nhau thứ 3, lưu toàn bộ node trong HEAP. Còn kiểu void ở trên chỉ lưu mảng khởi tạo kích thước ở heap, giá trị top hay front/rear vẫn lưu ở stack
// Khi sử dụng thì gọi con trỏ *node1, *node2,...





#endif // LIST_H