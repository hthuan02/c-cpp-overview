#include "list.h"

Node* create_node(int new_data)
{
    Node *head = (Node*)malloc(sizeof(Node));
    head->data = new_data;
    head->next = NULL;

    return head;
}

void push_front(Node **head, int data)
{
    Node *new_node = create_node(data);

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

void push_back(Node **head, int data);
void display(Node *head)
{
    if (head == NULL)
    {
        printf("Không có node!\n");
    }

    else
    {   
        int index = 0;
        while (head != NULL)
        {
            printf("Node %d: %d\n", index, head->data);
            head = head->next;
            index++;
        }
        printf("\n");
    }
    
}