#include "./Node.h"
#include "../utils/MyPrimitives/Ball.h"

#include <string.h>

struct Node *create_node(void *data, int size)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    *new_node = node_constructor(data, size);
    return new_node;
}

void destroy_node(struct Node *node)
{
    node_destructor(node);
}
struct Node node_constructor(void *data, int size)
{
    int i;
    if (size < 1)
    {
        printf("\ninvalid data size for Node");
        exit(1);
    }

    struct Node node;

    node.counter = 222;
    // size of the array in bytes
    node.data = malloc(size);   
    memcpy(node.data, data, size);
    //memcpy(((struct Ball *)node.data)->center_coordinates,((struct Ball*)data)->center_coordinates,2*sizeof(float));

    node.next = NULL;
    node.previous = NULL;

    return node;
}

void node_destructor(struct Node *node)
{
    free(node->data);
    free(node);
}