#include "circular.h"

int main ()
{
    Circular_t q2;
    int32_t val_dequeue,
            val_front,
            val_rear;
    if (init_queue(&q2, 5) == CIRCULAR_MALLOC_FAIL)
    {
        return -1;
    }

    enqueue(&q2, 1);
    enqueue(&q2, 2);
    enqueue(&q2, 3);
    enqueue(&q2, 4);
    enqueue(&q2, 5);
    enqueue(&q2, 6);
    enqueue(&q2, 7);

    if (dequeue(&q2, &val_dequeue) == CIRCULAR_OK)
    {
        printf("Dequeue: %d\n", val_dequeue);
    }
    
    enqueue(&q2, 111);

    print_queue(q2);
    if (front(q2, &val_front) == CIRCULAR_OK)
    {
        printf("Front: %d\n", val_front);
    }

    if (rear(q2, &val_rear) == CIRCULAR_OK)
    {
        printf("Rear: %d\n", val_rear);
    }

    return 0;
}