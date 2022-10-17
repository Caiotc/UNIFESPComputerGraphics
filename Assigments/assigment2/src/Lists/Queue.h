#ifndef QUEUE_H
#define QUEUE_H

#include "./LinkedList.h"
struct Queue
{
    struct LinkedList list;

    void (*push)(struct Queue *queue, void *data, int size);
    void *(*peek)(struct Queue *queue);
    void (*pop)(struct Queue *queue);
};

// constructors

struct Queue queue_constructor(void);
void queue_destructor(struct Queue *queue);
#endif