#include "list.h"

Node_t *create_node(int32_t new_data)
{
    Node_t *Node = (Node_t *)malloc(sizeof(Node_t));
    if (Node == NULL)
    {
        Node->data = 0;
        Node->next = NULL;
        return NULL;
    }

    Node->data = new_data;
    Node->next = NULL;

    return Node;
}

LinkedListStatus_t push_front(Node_t **head, int32_t data)
{   
    // Kiêm tra địa chỉ head trong main
    if (head == NULL)
    {
        return LIST_NULL_PTR;
    }
    
    Node_t *new_node = create_node(data);
    if (new_node == NULL) 
    {   
        return LIST_MALLOC_FAIL;
    }

    new_node->next = *head;
    *head = new_node;
    
    return LIST_OK;
}

LinkedListStatus_t push_back(Node_t **head, int32_t data)
{   
    if (head == NULL)
    {
        return LIST_NULL_PTR;
    }
    

    Node_t *new_node = create_node(data);
    if (new_node == NULL)
    {
        return LIST_MALLOC_FAIL;
    }

    // List rỗng
    if (*head == NULL)
    {
        new_node->next = *head;
        *head = new_node;

        return LIST_OK;
    }
    
    // List không rỗng
    Node_t *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }   
    temp->next = new_node;
    
    return LIST_OK;
}

LinkedListStatus_t insert_positon(Node_t **head, int32_t data, uint32_t pos)
{   
    // Kiểm tra địa chỉ head trong main
    if (head == NULL)
    {
        return LIST_NULL_PTR;
    }
    
    Node_t *new_node = create_node(data);
    if (new_node == NULL)
    {
        return LIST_MALLOC_FAIL;
    }

    // Duyệt list tìm size để kiểm tra pos
    Node_t *temp = *head;
    uint32_t size = 0; 
    if (temp != NULL)
    {
        temp = temp->next;
        size++;
    }

    // Case1: pos > size
    if (pos > size)
    {
        return LIST_INVALID_PARAM;
    }
    
    // Case2: pos == 0
    if (pos == 0)
    {
        new_node->next = *head;
        *head = new_node;

        return LIST_OK;
    }

    // Case3: pos == index
    Node_t *temp_next = *head;
    uint32_t index = 0;
    while (temp_next != NULL && index < pos-1)
    {
        temp_next = temp_next->next;
        index++;
    }
    new_node->next = temp_next->next;
    temp_next->next = new_node;
    
    return LIST_OK;
}

LinkedListStatus_t delete_front(Node_t **head, int32_t *val);
LinkedListStatus_t delete_back(Node_t **head, int32_t *val);
LinkedListStatus_t delete_position(Node_t **head, int32_t *val, int32_t pos);



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
        printf("---------------\n");    
    }
    
    
}

void free_list(Node_t **head)
{
    if (head == NULL || *head == NULL)
    {
        return;
    }

    Node_t *temp;
    while ((*head) != NULL)
    {   
        temp = (*head);
        (*head) = (*head)->next;
        free(temp);
        temp = NULL;
    }
    
}
