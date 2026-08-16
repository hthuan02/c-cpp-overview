#ifndef __LIST_H
#define __LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct Node_t
{
    uint32_t data;
    struct Node_t *next;
}Node_t;

Node_t* create_node(uint32_t data);
// push
void push_front(Node_t **head, uint32_t data);
void push_back(Node_t **head, uint32_t data);
void insert_node(Node_t **head, uint32_t data, uint8_t pos);

// pop
void pop_front(Node_t **head);
void pop_back(Node_t **head);
void delete_node(Node_t **head, uint8_t pos);

// get
uint32_t get_front(Node_t *head);
uint32_t get_back(Node_t *head);
uint32_t get_node(Node_t *head, uint8_t pos);

// display
void print_list(Node_t *head);

#endif // __LIST_H