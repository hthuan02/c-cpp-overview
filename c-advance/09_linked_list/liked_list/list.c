#include "list.h"

Node_t *create_node(int32_t data)
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

void push_front(Node_t **head, int32_t data)
{
    if (head == NULL)
    {
        return;
    }

    Node_t *new_node = create_node(data);
    if (new_node == NULL)
    {
        return;
    }
    
    new_node->next = *head;
    *head = new_node;
}

void push_back(Node_t **head, int32_t data)
{
    if (head == NULL)
    {
        return;
    }
    

    Node_t *new_node = create_node( data);
    if (new_node == NULL)
    {
        return;
    }

    if (*head == NULL)
    {
        new_node->next = *head;
        *head = new_node;
        return;
    }

    Node_t *temp = *head;
    while (temp->next != NULL)
    {   
        temp = temp->next;
    }

    temp->next = new_node;
}

void insert_node(Node_t **head, int32_t data, uint32_t pos)
{
    // Kiểm tra địa chỉ head trong main
    if (head == NULL)
    {
        return;
    }

    Node_t *new_node = create_node(data);
    if (new_node == NULL)
    {
        return;
    }

    Node_t *temp = *head;
    uint32_t size = 0;
    while(temp != NULL)
    {
        temp = temp->next;
        size++;
    }

    if (pos > size)
    {   
        // free new_node, ko free(head)
        free(new_node);
        new_node = NULL;
        return;
    }

    if (pos == 0)
    {
        new_node->next = *head;
        *head = new_node;

        return;
    }

    Node_t *next_of_list = *head;
    uint32_t index = 0;
    while (next_of_list != NULL && index < pos -1)
    {
        next_of_list = next_of_list->next;
        index++;
    }
    
    new_node->next = next_of_list->next;
    next_of_list->next = new_node;
}

void delete_front(Node_t **head)
{
    if (head == NULL ||*head == NULL)
    {
        return;
    }
    
    Node_t *temp = *head;
    (*head) = (*head)->next;
    free(temp);
    temp = NULL;
}

void delete_back(Node_t **head)
{
    if (head == NULL || *head == NULL)
    {
        return;
    }

    // list có 1 node
    if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;

        return;
    }

    // list có >= 2 node
    Node_t *temp = *head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
}
    
void delete_node(Node_t **head, uint32_t pos)
{
    if (head == NULL || *head == NULL)
    {
        return;
    }

    // Case1: pos > size
    Node_t *next_of_head = *head;
    uint32_t size = 0;
    while (next_of_head != NULL)
    {
        next_of_head = next_of_head->next;
        size++;
    }
    
    if (pos >= size)
    {
        return;
    }

    // Case2: pos == 0
    if (pos == 0)
    {
        Node_t *temp = *head;
        (*head) = (*head)->next;
        free(temp);
        temp = NULL;

        return;
    }

    // Case3: pos == index
    Node_t *next_of_list = *head;
    uint32_t index = 0;
    while (next_of_list != NULL && index < pos -1)
    {
        next_of_list = next_of_list->next;
        index++;
    }

    // free dynamic memory
    Node_t *to_delete = next_of_list->next;
    next_of_list->next = to_delete->next;

    free(to_delete);
    to_delete = NULL;
}

int32_t get_front(Node_t *head)
{   
    if (head == NULL)
    {
        return INT32_MAX;
    }

    return head->data;
}

int32_t get_back(Node_t *head)
{
    if (head == NULL)
    {
        return INT32_MAX;
    }

    Node_t *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    return temp->data;
}

int32_t get_node(Node_t *head, uint32_t pos)
{
    if (head == NULL)
    {
        return INT32_MAX;
    }

    Node_t *temp = head;
    uint32_t index = 0;

    // Duyệt temp != NULL -> ra khỏi mảng  == NULL
    // Duyệt temp-> next != NULL -> cuối mảng (nhưng duyệt kiểu này sai)
    // Bắt buộc kiểm tra NULL -> return; để kết thúc
    while (temp != NULL && index < pos)
    {
        temp = temp->next;
        index++;
    }
    if (temp == NULL)
    {
        return INT32_MAX;
    }
    return temp->data;
}

void print_list(Node_t *head)
{
    if (head == NULL)
    {
        return;
    }

    Node_t *temp = head;
    uint32_t index = 0;

    while (temp != NULL)
    {   
        printf("Node %d - Data %d\n",index, temp->data);
        temp = temp->next;
        index++;
    }
    printf("----------\n");
}

void free_list(Node_t **head)
{
    if (head == NULL || *head == NULL)
    {
        return;
    }
    Node_t *temp;
    while (*head != NULL)
    {
        temp = *head;
        (*head) = (*head)->next;
        free(temp);
        temp = NULL;
    }

}