#include "list.h"

Node_t* create_node(uint32_t data)
{
    Node_t *Node = (Node_t*)malloc(sizeof(Node_t));
    
    if (Node == NULL)
    {
        return NULL;
    }
    
 
    Node->data = data;
    Node->next = NULL;

    return Node;
}

// push
void push_front(Node_t **head, uint32_t data)
{
    Node_t *new_node = create_node(data);

    if (new_node == NULL)
    {
        return;
    }

    if (*head == NULL)
    {
        *head = new_node;

        return;
    }

    new_node->next = *head;
    *head = new_node;
}

void push_back(Node_t **head, uint32_t data)
{
    Node_t *new_node = create_node(data);
    if (new_node == NULL)
    {
        return;
    }
    
    if (*head == NULL)
    {
        *head = new_node;
        return;
    }
    
    
    Node_t *temp = *head;
    uint8_t index = 0;
    while (temp->next != NULL)
    {
        temp = temp->next;
        index++;
    }

    temp->next = new_node;
    
}

void insert_node(Node_t **head, uint32_t data, uint8_t pos)
{
    Node_t *new_node = create_node(data);
    if (new_node == NULL)
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
        // Giả sử list có 3 node, pos = 5 -> return ngang ==> ERROR: memory leak
        free(new_node);
        return;
    }
    
    if (pos == 0)
    {
        new_node->next = *head;
        *head = new_node;

        return;
    }

    Node_t *next_list = *head;
    uint8_t index = 0;
    while (next_list != NULL && index < pos -1)
    {
        next_list = next_list->next;
        index++;
    }

    new_node->next = next_list->next;
    next_list->next = new_node;

}

// pop
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

    // TH1: Xóa node cuối, list có 1 node
    if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;

        return;
    }
    

    // TH2: Xóa node cuối, list >=2 node
    Node_t *temp = *head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
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

    if (pos >= size)
    {
    
        return;
    }

    if (pos == 0)
    {
        Node_t *delete_front = *head;
        (*head) = (*head)->next;
        free(delete_front);
        delete_front = NULL;

        return;
    }

    Node_t *next_of_list = *head;
    uint8_t index = 0;
    while (next_of_list != NULL && index < pos -1)
    {
        next_of_list = next_of_list->next;
        index++;
    }

    Node_t *to_delete = next_of_list->next;
    next_of_list->next = to_delete->next;
    
    free(to_delete);
}

// get
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

    if (temp == NULL)
    {
        return UINT32_MAX;
    }
    
    return temp->data;

}

// display
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
        printf("----------------\n");
    }
    
}
