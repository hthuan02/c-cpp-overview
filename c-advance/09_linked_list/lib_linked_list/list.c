#include "list.h"

// Hàm khởi tạo node, lưu toàn bộ node trong phân vùng heap
node_t* create_node(int new_data)
{
    // Cấp phát động cho 1 Node
    node_t *head = (node_t*)malloc(sizeof(node_t));
    head->data = new_data;
    head->next = NULL;

    // Trả về địa chỉ node vừa tạo
    return head;
}

// Hàm thêm node ở đầu list
void push_front(node_t **head, int value)
{
    node_t *new_node = create_node(value);

    if(*head == NULL)
    {
        *head = new_node;
    }

    else
    {
        new_node->next = *head;
        *head = new_node;
    }
}

// Hàm thêm node ở cuối list
void push_back(node_t **head, int value)
{
    node_t *new_node = create_node(value);

    if (*head == NULL)
    {
        *head = new_node;
    }

    else
    {
        node_t *temp = *head;  

        // Duyệt list, tìm *next của node cuối `head-> next != NULL`
        while (temp->next != NULL)
        {
            // Trỏ đến node tiếp theo
            temp = temp->next;
        }
        // Khi thoát while, in ra *next của node cuối
        temp->next = new_node;

    }
    

}

// Hàm thêm node ở vị trí bất kỳ
void insert(node_t **head, int value, int pos)
{
    node_t *new_node = create_node(value);

    if (*head == NULL)
    {
        *head = new_node;
    }

    else
    {
        // Thêm node vị trí đầu tiên
        if (pos == 0)
        {
            new_node->next = *head;
            *head = new_node;
        }
        
        // Thêm node khác vị trí đầu
        else
        {
            int index = 0;
            node_t *temp = *head;

            // Duyệt list, kiểm tra node đến vị trí index < pos -1
            while (temp != NULL && index < pos - 1)
            {
                // *next trỏ đến node tiếp theo
                temp = temp->next;
                index++;
            }

            // Cập nhật list
            if (temp != NULL && index == pos - 1)
            {
                new_node->next = (temp->next);
                temp->next = new_node;
            }
            
            
        }
    }
    
}

// Kiểm tra kích thước của node
int size(node_t *head)
{
    unsigned int count = 0;
    
    if (head == NULL)
    {
        return 0;
    }

    else
    {
        // Duyệt list, kiểm tra node
        while(head != NULL)
        {
            // Trỏ đến node tiếp theo
            head = head->next;
            count++;
        }

        return count;
    }
    
}

// Đọc giá trị node đầu tiên
int front_list(node_t *head)
{
    unsigned int front_list;

    if (head == NULL)
    {
        return 0;
    }
    
    else
    {
        front_list = head->data;

        return front_list;
    }

}

// Hàm đọc giá trị node cuối
int back_list(node_t *head)
{   
    unsigned back_list;

    if (head == NULL)
    {
        return 0;
    }

    else
    {
        // Duyệt list, kiểm tra *next
        while (head->next != NULL)
        {
            // Trỏ node tiếp theo
            head = head->next;
        }
        back_list = head->data;

        return back_list;
    }
    
}

// Hàm hiển thị các node
void display(node_t *head)
{
    if (head == NULL)
    {
        printf("Không có node!\n");
    }

    else 
    {
        int index = 0;
        // Duyệt list, kiểm tra khi node không rỗng
        while (head != NULL)
        {
            printf("Node %d: %d\n", index, head->data);
            // Trỏ đến *next của node tiếp theo
            head = head->next;
            index++;
        }
        printf("\n");

    }
    
}