#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct Node_t
{
    uint32_t data;
    struct Node_t *next;
}Node_t;

// Create node function
Node_t* create_node(uint32_t new_data)
{
    Node_t *Node = (Node_t*)malloc(sizeof(Node_t));
    Node->data = new_data;
    Node->next = NULL;

    return Node;
} 

void push_front(Node_t **head, uint32_t new_data)
{
    Node_t *new_node = create_node(new_data);
    if (new_node == NULL)
    {
        return;
    }
    
    if (*head == NULL)
    {
        *head = new_node;
    }
    new_node->next = *head;
    *head = new_node;
    
}

void push_back(Node_t **head, uint32_t new_data)
{
    Node_t *new_node = create_node(new_data);
    if (new_node == NULL)
    {
        return;
    }
    
    Node_t *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = new_node;
    
}

void insert_node(Node_t **head, uint32_t new_data, uint8_t pos)
{
    Node_t *new_node = create_node(new_data);
    if (new_node == NULL)
    {
        return;
    }

    Node_t *temp = *head;
    uint8_t index = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        index++;
    }

    if (pos > index)
    {
        return;
    }

    if (pos == 0)
    {
        new_node->next = *head;
        *head = new_node;
    }

    Node_t *next_list = *head;
    uint8_t size = 0;
    while (next_list != NULL && size < pos -1)
    {
        next_list = next_list->next;
        size++;
    }

    new_node->next = next_list->next;
    next_list->next = new_node;
    
}

void pop_front(Node_t **head)
{
    if (*head == NULL)
    {
        return;
    }
    
    Node_t *temp = *head;
    (*head) = (*head)->next;
    free(temp);
    temp = NULL;
}

void pop_back(Node_t **head)
{
    if (*head == NULL)
    {
        return;
    }
    
    Node_t *temp = *head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    Node_t *to_delete = temp->next;
    temp->next = to_delete->next;

    free(temp->next);
    temp->next = NULL;
}

void delete_node(Node_t **head, uint8_t pos)
{
    if (*head == NULL)
    {
        return;
    }

    Node_t *temp = *head;
    uint8_t size = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        size++;
    }

    if (pos > size)
    {
        return;
    }

    if (pos == 0)
    {
        Node_t *delete_front = *head;
        free (delete_front);
        delete_front = NULL;
    }
    
    Node_t *to_delete = *head;
    uint8_t index = 0;
    while (to_delete != NULL && index < pos -1)
    {
        to_delete = to_delete->next;
        index++;
    }

    if (to_delete == NULL && index == pos -1)
    {
        return;
    }

    Node_t *delete_node = to_delete->next;
    to_delete->next = delete_node->next;
    
    free(delete_node);
}

uint32_t get_front(Node_t *head)
{
    if (head == NULL)
    {
        return UINT32_MAX;
    }
    
    return head->data;
}

uint32_t get_back(Node_t *head)
{
    if (head == NULL)
    {
        return UINT32_MAX;
    }
    Node_t *temp = head;   
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    

    return temp->data;
}

uint32_t get_node(Node_t *head, uint8_t pos)
{
    if (head == NULL)
    {
        return UINT32_MAX;
    }

    Node_t *temp = head;   
    uint8_t index = 0;
    while (temp != NULL && index < pos)
    {
        temp = temp->next;
        index++;
    }

    return temp->data;
}



void print_list(Node_t *head)
{
    if (head == NULL)
    {
        return;
    }

    else
    {   
        Node_t *temp = head;
        uint8_t index = 0;
        while (temp != NULL)
        {
            printf("Node %d - Data %d\n", index, temp->data);
            temp = temp->next;
            index++;
        }
        printf("--------------\n");
        
    }
    
}

int main ()
{
    Node_t *n1 = create_node(5);
    Node_t *n2 = create_node(6);
    Node_t *n3 = create_node(7);

    n1->next = n2;
    n2->next = n3; 

    print_list(n1);

    push_front(&n1, 111);
    push_back(&n1, 222);
    insert_node(&n1, 1234, 2);

    pop_front(&n1);
    pop_back(&n1);
    delete_node(&n1, 1);
    print_list(n1);

    printf("Get front node: %d\n", get_front(n1));
    printf("Get back node: %d\n", get_back(n1));
    printf("Get any node: %d\n", get_node(n1,1));



 

    return 0;
}
