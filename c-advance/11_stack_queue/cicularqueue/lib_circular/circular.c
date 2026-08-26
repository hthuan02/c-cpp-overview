#include "circular.h"

/** 
 *  DEBUG
 *  - Không đặt tên hàm trùng member struct
 *  - Không print được -> Khởi tạo malloc fail or print có vấn đề or isEmpty/isFull fault
 *  - Kiểm tra dấu `=` có bị thiếu?
 *  - Kiểm tra thiếu `return`?
 *  - Kiểm tra data_type đồng nhất
 */

/* Hàm khởi tạo queue, thêm, xóa queue */
QueueCircularStatus_t create_queue(Queue_t *q, uint32_t data)
{
    q->items = (uint32_t*)malloc(data * sizeof(uint32_t));
    if (q->items == NULL)
    {
        q->front = q->rear = -1;
        q->size = 0;

        return CIRCULAR_MALLOC_FAIL;
    }
    
    q->front = q->rear = -1;
    q->size = data;
    return CIRCULAR_OK;
}

QueueCircularStatus_t enqueue(Queue_t *q, int32_t data)
{
    if (isFull(*q))
    {
        return CIRCULAR_FULL;
    }

    // Kiểm tra queue toàn rỗng trước
    if (q->front == -1)
    {
        q->front = 0;
    }

    // Tăng trước, ghi sau
    q->rear = (q->rear + 1) % q->size;
    q->items[q->rear] = data;

    return CIRCULAR_OK;
}

QueueCircularStatus_t dequeue(Queue_t *q, int32_t *data)
{
    if (isEmpty(*q))
    {
        return CIRCULAR_EMPTY;
    }

    // đọc giá trị trước, tăng front sau
    *data = q->items[q->front];

    // kiểm tra trường hợp khi rỗng
    if (q->front == q->rear)
    {
        q->front = q->rear = -1;
    }
    
    else
    {
        q->front = (q->front + 1) % q->size;
    }
    
    return CIRCULAR_OK;
}

QueueCircularStatus_t front(Queue_t q, int32_t *data)
{
    if (isEmpty(q))
    {
        return CIRCULAR_EMPTY;
    }

    *data = q.items[q.front];

    return CIRCULAR_OK;
}

QueueCircularStatus_t rear(Queue_t q, int32_t *data)
{
    if (isEmpty(q))
    {
        return CIRCULAR_EMPTY;
    }

    *data = q.items[q.rear];

    return CIRCULAR_OK;
}

/* Hàm kiểm tra queue */
bool isEmpty(Queue_t q)
{
    return q.front == -1;
}

bool isFull(Queue_t q)
{
    return q.front == (q.rear + 1) % q.size;
}

/* Hàm display queue */
void print_queue(Queue_t q)
{
    if (isEmpty(q))
    {
        return;
    }

    else
    {
        printf("Queue: ");
        
        int32_t i = q.front;
        while (1)
        {
            printf("%d ", q.items[i]);
            
            if (i == q.rear) break;
            i = (i + 1) % q.size;
        }
        printf("------------\n");
    }
    
}

/* Hàm thu hồi queue */
void free_queue(Queue_t *q)
{
    if (q->items)
    {
        free(q->items);
        q->items = NULL;
        q->front = q->rear = -1;
        q->size = 0;
    }
    
}
