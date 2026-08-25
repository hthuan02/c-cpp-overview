#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct Node_t
{
    uint32_t data;
    struct Node_t *next;
}Node_t;

/* Create node */
Node_t* create_node(uint32_t new_data);

/* Push node */
void push_front(Node_t **head, uint32_t data);
void push_back(Node_t **head, uint32_t data);
void insert_node(Node_t **head, uint32_t data, uint8_t pos);

/* Pop node */
void pop_front(Node_t **head);
void pop_back(Node_t **head);
void delete_node(Node_t **head, uint8_t pos);

/* Get node */
uint32_t get_front(Node_t *head);
uint32_t get_back(Node_t *head);
uint32_t get_node(Node_t *head, uint8_t pos);

/* Display list */
void print_list(Node_t *head);

/* Free address of heap segment */
void free_list(Node_t **head);

Node_t* create_node(uint32_t new_data)
{
    Node_t *Node = (Node_t*)malloc(sizeof(Node_t));
    if (Node == NULL)
    {
        return NULL;
    }

    Node->data = new_data;
    Node->next = NULL;

    // Trả về địa chỉ node
    return Node;
}

/*===================================== PUSH NODE ==========================================*/
/* Push node */
void push_front(Node_t **head, uint32_t data)
{   
    Node_t *new_node = create_node(data);
    if (new_node == NULL) return;

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
    if (new_node == NULL) return;

    if (*head == NULL)
    {
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

void insert_node(Node_t **head, uint32_t data, uint8_t pos)
{
    Node_t *new_node = create_node(data);
    if (new_node == NULL) return;
    
    Node_t *temp = *head;
    uint8_t size = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        size++;
    }
    
    if (pos > size)
    {   
        free(new_node);
        return;
    }

    if (pos == 0)
    {
        // push_front
        new_node->next = *head;
        *head = new_node;
        return;
    }

    Node_t *next_of_list = *head;
    uint8_t index = 0;
    while (next_of_list != NULL && index < pos -1)
    {
        next_of_list = next_of_list->next;
        index++;
    }

    new_node->next = next_of_list->next;
    next_of_list->next = new_node;
    
    
}

/* Pop node */
void pop_front(Node_t **head)
{
    if (*head == NULL)
    {
        return;
    }

    else
    {
        Node_t *temp = *head;
        (*head) = (*head)->next;
        free(temp);
        temp = NULL;
    }
    
}

void pop_back(Node_t **head)
{
    if (*head == NULL)
    {
        return;
    }

    // TH1: list có 1 node
    if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;

        return;
    }

    // TH2: list có >= 2 node
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
    if (*head == NULL) return;
     
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
        // pop_front
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

    Node_t *delete_node = next_of_list->next;
    next_of_list->next = delete_node->next;

    free(delete_node);
    delete_node = NULL;

}

/* Get node */
uint32_t get_front(Node_t *head)
{
    if (head == NULL) return UINT32_MAX;
    
    return head->data;
}

uint32_t get_back(Node_t *head)
{
    if (head == NULL) return UINT32_MAX;
    
    Node_t *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    return temp->data;
}

uint32_t get_node(Node_t *head, uint8_t pos)
{
    if (head == NULL) return UINT32_MAX;

    Node_t *temp = head;
    uint8_t index = 0;
    while (temp != NULL && index < pos)
    {
        temp = temp->next;
        index++;
    }
    
    // Kiểm tra lại
    if (temp == NULL)
    {
        return UINT32_MAX;
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
            printf("Node %d - Data %d\n",index, temp->data);
            temp = temp->next;
            index++;
        }
        printf("-------------------\n");
    }
}

void free_list(Node_t **head)
{   
    /* L1: temp = n1
     *     *head = n2 --> free n1
     * L2: temp = n2
     *     *head = n3 --> free n2
     * L3: temp = n3 
     *     *head = NULL --> free n3
     */

    Node_t *temp;
    while (*head != NULL)
    {
        temp = *head;
        (*head) = (*head)->next;
        free(temp);
    }
    
}

int main ()
{   
    // Khởi tạo node
    Node_t *n1 = create_node(1); // giả sử địa chỉ 0x01 (5, NULL)
    Node_t *n2 = create_node(2); // 0xa1 (6, NULL)
    Node_t *n3 = create_node(3); // 0xe1 (7, NULL)

    // Liên kết node
    n1->next = n2;
    n2->next = n3;

    print_list(n1);

    push_front(&n1, 111);
    push_back(&n1, 999);
    insert_node(&n1, 1234,2);

    pop_front(&n1);
    pop_back(&n1);
    // delete_node(&n1, 3);
    delete_node(&n1, 1);
    // delete_node(&n1, 0);

    print_list(n1);    
    printf("Get front node: %d\n", get_front(n1));
    printf("Get back node: %d\n", get_back(n1));
    printf("Get any node: %d\n", get_node(n1,2));

    free_list(&n1);

    return 0;
}

