#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *createNode(int data)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;

    return temp;
}

// Hàm xóa 1 node ở cuối List
void pop_back(Node **array)
{
    if (*array == NULL)
    {
        return;
    }

    else
    {
        // list có 1 node
        if ((*array)->next == NULL)
        {
            free(*array);
            *array = NULL;
        }
        
        // list có nhiều hơn 1 node
        else
        {
            Node *p = *array;
            Node *temp = *array; // tim duyet vi ke cuoi
            unsigned int count = 0;
            
            // Tìm kích thước list
            while (p->next != NULL)
            {
                p = p->next;
                count++;
            }

            // Xóa node cuối list
            for (int i = 0; i < count - 1; i++)
            {
                temp = temp->next;
            }
            temp->next = NULL;
            free(p);
        }
    }
}

void printlist(Node *array)
{
    Node *p = array;
    int i = 0;

    while (p != NULL)
    {
        printf("Node = %d - Data = %d\n", i, p->data);
        p = p->next;
        i++;
    }
}

int main(int argc, char const *argv[])
{
    Node *n1 = createNode(5);
    Node *n2 = createNode(6);
    Node *n3 = createNode(7);

    n1->next = n2;
    n2->next = n3;

    printlist(n1);
    printf("\n");

    pop_back(&n1);
    printlist(n1);
    return 0;
}
