#ifndef LINKED_LIST_SINGLY_H
#define LINKED_LIST_SINGLY_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct Node_t
{
    int32_t data;
    struct Node_t *next;
}Node_t;

typedef enum
{
    LIST_OK,
    LIST_NULL_PTR,      
    LIST_MALLOC_FAIL,
    LIST_INVALID_PARAM,
    LIST_EMPTY
}ListSinglyStatus_t;

/* Hàm khởi tạo node */
Node_t *init_node(int32_t new_data);

/* Hàm thêm node */
ListSinglyStatus_t push_front(Node_t **head, int32_t data);
ListSinglyStatus_t push_back(Node_t **head, int32_t data);
ListSinglyStatus_t insert_node(Node_t **head, int32_t data, uint32_t pos);

/* Hàm xóa node */
ListSinglyStatus_t pop_front(Node_t **head, int32_t *data);
ListSinglyStatus_t pop_back(Node_t **head, int32_t *data);
ListSinglyStatus_t delete_node(Node_t **head, int32_t *data, uint32_t pos);

/* Hàm đọc node */
ListSinglyStatus_t get_front(Node_t *head, int32_t *data);
ListSinglyStatus_t get_back(Node_t *head, int32_t *data);
ListSinglyStatus_t get_node(Node_t *head, int32_t *data, uint32_t pos);

/* Hàm in list & Hàm thu hồi vùng nhớ malloc */
void print_list_singly(Node_t *head);
void free_list_singly(Node_t **head);

#endif // LINKED_LIST_SINGLY_H