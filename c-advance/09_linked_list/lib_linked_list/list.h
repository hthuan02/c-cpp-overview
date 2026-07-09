#ifndef __LIST_H
#define __LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node_t
{
    int data;
    struct node_t *next;
}node_t;

/* Prototype Function */
//  Các hàm thêm node
node_t* create_node(int data);
void push_front(node_t **head, int value);
void push_back(node_t **head, int value);
void insert(node_t **head, int value, int pos);

// Các hàm xóa node
void pop_front(node_t **head);
void pop_back(node_t **head);
void delete_list(node_t **head);

// Các hàm đọc data node
int size(node_t *head);
int front_list(node_t *head);
int back_list(node_t *head);
int get_list(node_t *head, int pos);

// Hàm in node
void display(node_t *head);

#endif // __LIST_H

