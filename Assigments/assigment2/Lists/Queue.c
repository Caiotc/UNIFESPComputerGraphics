#include "./Queue.h"
#include "../utils/MyPrimitives/Ball.h"

void push(struct Queue *queue, void *data, int size);
void *peek(struct Queue *queue);
void pop(struct Queue *queue);

struct Queue queue_constructor()
{
    struct Queue new_queue;
    new_queue.list = linked_list_constructor();
    new_queue.push = push;
    new_queue.peek = peek;
    new_queue.pop = pop;
    return new_queue;
}

void queue_destructor(struct Queue *queue)
{
    linked_list_destructor(&queue->list);
    free(queue);
};

// inserts at the end of the list
void push(struct Queue *queue, void *data, int size)
{
    // inserts at the end
    printf("\n!@# olha essa caralha tamanho da lista ta inserindo no-> %d ",queue->list.length);
    queue->list.insert(queue->list.length, data, size, &queue->list);


}
void *peek(struct Queue *queue)
{
    // peek at the listinit
    return queue->list.retrieve(0, &queue->list);
}
void pop(struct Queue *queue)
{
    // remove at the list init
    queue->list.remove(0, &queue->list);
}
