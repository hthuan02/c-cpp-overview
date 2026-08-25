#include "circular.h"

int main ()
{
    Queue_t q1;
    int32_t val_dequeue,
            val_front,
            val_rear;

    create_queue(&q1, 5);

    enqueue(&q1, 1);
    enqueue(&q1, 2);
    enqueue(&q1, 3);
    enqueue(&q1, 4);
    enqueue(&q1, 5);
    enqueue(&q1, 6);

    print_queue(q1);
    if (dequeue(&q1,&val_dequeue) == CIRCULAR_OK)
    {
        printf("Dequeue: %d\n", val_dequeue);
    }

    print_queue(q1);
    if (front(q1, &val_front) == CIRCULAR_OK)
    {
        printf("Front: %d\n", val_front);
    }
    
    if (rear(q1, &val_rear) == CIRCULAR_OK)
    {
        printf("Rear: %d\n", val_rear);
    }
    free_queue(&q1);

    return 0;
}