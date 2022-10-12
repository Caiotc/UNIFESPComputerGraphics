#include <stdio.h>
#include "./Lists/LinkedList.h"
#include "./Lists/Queue.h"

int main(int argc, char const *argv[])
{

    struct Queue queue = queue_constructor();

    for (int i = 0; i < 10; i++)
        queue.push(&queue, &i, 1);

    printf("peek %d \n", *(int *)queue.peek(&queue));
    queue.pop(&queue);
    printf("peek %d \n", *(int *)queue.peek(&queue));

    /* code */
    return 0;
}
