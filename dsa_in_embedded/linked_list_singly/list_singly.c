#include "list_singly.h"

Node_t *init_node(int32_t new_data)
{
    Node_t *Node = (Node_t*)malloc(sizeof(Node_t));
    if (Node == NULL)
    {
        return NULL;
    }
    
    Node->data = new_data;
    Node->next = NULL;

    return Node;
}

ListSinglyStatus_t push_front(Node_t **head, int32_t data)
{ 
    // Kiểm tra địa chỉ head trong main
    if (head == NULL)
    {
        return LIST_NULL_PTR;
    }

    // Tạo new_node, kiểm tra malloc thành công hay không
    Node_t *new_node = init_node(data);
    if (new_node == NULL)
    {
        return LIST_MALLOC_FAIL;
    }
    
    // Địa chỉ node đầu list 
    if (*head == NULL)
    {
        *head = new_node;
        return LIST_OK;
    }
    new_node->next = *head;
    *head = new_node;
        
    return LIST_OK;
}

ListSinglyStatus_t push_back(Node_t **head, int32_t data)
{
    // Kiểm tra địa chỉ biến head trong main
    if (head == NULL)
    {
        return LIST_NULL_PTR;
    }
    
    // Tạo new_node, kiểm tra malloc
    Node_t *new_node = init_node(data);
    if (new_node == NULL)
    {
        return LIST_MALLOC_FAIL;
    }

    // Case1: List rỗng
    if (*head == NULL)
    {
        *head = new_node;
        return LIST_OK;
    }

    // Case2: List có node
    Node_t *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = new_node;
    return LIST_OK;
}

ListSinglyStatus_t insert_node(Node_t **head, int32_t data, uint32_t pos)
{
    // Kiểm tra địa chỉ head trong main
    if (head == NULL)
    {
        return LIST_NULL_PTR;
    }

    // Tạo new_node, kiểm tra malloc thành công chưa
    Node_t *new_node = init_node(data);
    if (new_node == NULL)
    {
        return LIST_MALLOC_FAIL;
    }

    // Case1: pos > size
    int32_t val_size = 0;
    Node_t *ptr_read_size = *head;
    while (ptr_read_size != NULL)
    {
        ptr_read_size = ptr_read_size->next;
        val_size++;
    }
    if (pos > val_size)
    {
        free(new_node);
        return LIST_INVALID_PARAM;
    }

    // Case2: pos = 0
    if (pos == 0)
    {
        new_node->next = *head;
        *head = new_node;
        return LIST_OK;
    }

    // Case3: any position
    int32_t index = 0;
    Node_t *next_of_list = *head;
    while (next_of_list != NULL && index < pos -1)
    {
        next_of_list = next_of_list->next;
        index++;
    }

    new_node->next = next_of_list->next;
    next_of_list->next = new_node;
    return LIST_OK;   
}

ListSinglyStatus_t pop_front(Node_t **head, int32_t *data)
{   
    // Kiểm tra biến head trong main
    if (head == NULL)
    {
        return LIST_NULL_PTR;
    }

    // Kiểm tra list rỗng
    if (*head == NULL)
    {
        return LIST_EMPTY;
    }
    
    Node_t *temp = *head;
    (*head) = (*head)->next;
    
    *data = temp->data;
  
    free(temp);
    temp = NULL;

    return LIST_OK;
}

ListSinglyStatus_t pop_back(Node_t **head, int32_t *data)
{
    // Kiểm tra biến head trong main
    if (head == NULL)
    {
        return LIST_NULL_PTR;
    }

    // Kiểm tra khi list rỗng
    if (*head == NULL)
    {
        return LIST_EMPTY;
    }

    // Case1: List có 1 node
    if ((*head)->next == NULL)
    {   
        *data = (*head)->data;
        free(*head);
        *head = NULL;
        return LIST_OK;
    }

    // Case2: List >= 2 node
    // Xóa node cuối - node gần cuối lần *next cuối list
    Node_t *temp = *head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    // Ghi giá trị xóa vào data
    Node_t *ptr_write_temp = temp->next;
    *data =ptr_write_temp->data;

    // Thu hồi
    free(temp->next);
    temp->next = NULL;
    return LIST_OK;
}

ListSinglyStatus_t delete_node(Node_t **head, int32_t *data, uint32_t pos)
{
    // Kiểm tra giá trị head trong main
    if (head == NULL)
    {
        return LIST_NULL_PTR;
    }

    // Case1: pos > size
    Node_t *ptr_size = *head;
    uint32_t size = 0;
    while (ptr_size != NULL)
    {
        ptr_size = ptr_size->next;
        size++;
    }
    
    // list từ 0-1-2-3 nên phải có dấu `=`
    if (pos >= size)
    {
        return LIST_INVALID_PARAM;
    }

    // Case2: pos = 0
    if (pos == 0)
    {
        Node_t *temp = *head;
        // Ghi giá trị ra
        *data = temp->data;

        (*head) = (*head)->next;
        free(temp);
        temp = NULL;

        return LIST_OK;
    }

    // Case3: any position
    uint32_t index = 0;
    Node_t *temp = *head;
    while (temp != NULL && index < pos -1)
    {
        temp = temp->next;
        index++;
    }

    Node_t *to_delete = temp->next;
    temp->next = to_delete->next;

    *data = to_delete->data;

    free(to_delete);
    to_delete = NULL;
    return LIST_OK;
}

ListSinglyStatus_t get_front(Node_t *head, int32_t *data)
{
    if (head == NULL)
    {
        return LIST_EMPTY;
    }
    *data = (*head).data;

    return LIST_OK;
}

ListSinglyStatus_t get_back(Node_t *head, int32_t *data)
{
    if (head == NULL)
    {
        return LIST_EMPTY;
    }
    
    // Case1: List 1 node
    if ((*head).next == NULL)
    {
        *data = (*head).data;
        return LIST_OK;
    }

    // Case2: List >=2 node
    Node_t *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    *data = temp->data;
    
    return LIST_OK;
}

ListSinglyStatus_t get_node(Node_t *head, int32_t *data, uint32_t pos)
{
    if (head == NULL)
    {
        return LIST_EMPTY;
    }

    uint32_t index = 0;
    Node_t *temp = head;
    while (temp != NULL && index < pos)
    {
        temp = temp->next;
        index++;
    }

    if (temp == NULL)
    {
        return LIST_INVALID_PARAM;
    }

    *data = temp->data;
    return LIST_OK;
}

void print_list_singly(Node_t *head)
{
    if (head == NULL)
    {
        return;
    }

    Node_t *temp = head;
    uint32_t index = 0;
    while (temp != NULL)
    {
        printf("Node %d - Data %d\n", index, temp->data);
        temp = temp->next;
        index++;
    }
    printf("---------\n");
    
}

void free_list_singly(Node_t **head)
{
    if (head == NULL || *head == NULL)
    {
        return;
    }

    Node_t *temp;
    while ((*head) != NULL)
    {
        temp = *head;
        (*head) = (*head)->next;
        free(temp);
        temp = NULL;
    }
}
