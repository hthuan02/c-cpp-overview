#ifndef __LIST_H
#define __LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}Node;

Node* create_node(int new_data);
void push_front(Node **head, int data);
void push_back(Node **head, int data);
void display(Node *head);

#endif // __LIST_H