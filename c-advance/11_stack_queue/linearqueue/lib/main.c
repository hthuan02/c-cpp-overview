#include "linear.h"

int main ()
{
    Queue q1;
    queue_init(&q1);

    enqueue(&q1,1);
    enqueue(&q1,2);
    enqueue(&q1,3);
    enqueue(&q1,4);
    enqueue(&q1,5);
    enqueue(&q1,6);

    printf("Front: %d\n", front(q1));
    printf("Rear: %d\n", rear(q1));
    display(q1);

    printf("--------------------\n");

    dequeue (&q1);
    dequeue (&q1);
    dequeue (&q1);
    dequeue (&q1);
    dequeue (&q1);

    enqueue(&q1, 100);
    enqueue(&q1, 200);
    enqueue(&q1, 300);
    printf("Front: %d\n", front(q1));
    printf("Rear: %d\n", rear(q1));
    display(q1);


    queue_free(&q1);
    return 0;
}