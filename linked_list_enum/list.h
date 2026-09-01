#ifndef LINKED_LIST_H
#define LNKED_LIST_H


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct  Node_t
{
    int32_t data;
    struct Node_t *next; 
}Node_t;

typedef enum
{
    LIST_OK = 0,            // List thành công
    LIST_NULL_PTR,          // Tham số con trỏ NULL
    LIST_INVALID_PARAM,     // Dữ liệu & tham số không hợp lệ
    LIST_MALLOC_FAIL,       // Malloc thất bại
    LIST_EMPTY,             // List rỗng
    LIST_OUT_OF_RANGE       // Tham số vượt ngoài phạm vi (insert,delete)
}LinkedListStatus_t;

Node_t *create_node(int32_t new_data);
LinkedListStatus_t push_front(Node_t **head, int32_t data);
LinkedListStatus_t push_back(Node_t **head, int32_t data);
LinkedListStatus_t insert_positon(Node_t **head, int32_t data, uint32_t pos);

LinkedListStatus_t delete_front(Node_t **head, int32_t *val);
LinkedListStatus_t delete_back(Node_t **head, int32_t *val);
LinkedListStatus_t delete_position(Node_t **head, int32_t *val, int32_t pos);



void print_list(Node_t *head);
void free_list(Node_t **head);

#endif // LINKED_LIST_H