#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct Node_t
{
    int32_t data;
    struct Node_t *next;
}Node_t;

Node_t *create_node(int32_t data);

void push_front(Node_t **head, int32_t data);
void push_back(Node_t **head, int32_t data);
void insert_node(Node_t **head, int32_t data, uint32_t pos);

void delete_front(Node_t **head);
void delete_back(Node_t **head);
void delete_node(Node_t **head, uint32_t pos);

int32_t get_front(Node_t *head);
int32_t get_back(Node_t *head);
int32_t get_node(Node_t *head, uint32_t pos);

void print_list(Node_t *head);
void free_list(Node_t **head);

#endif // LINKED_LIST_H