#include "./Node.h"

#include <string.h>

struct Node node_constructor(void *data, int data_type, int size)
{
    int i;
    if (size < 1)
    {
        printf("\ninvalid data size for Node");
        exit(1);
    }

    struct Node node;
    switch (data_type)
    {
    case Int:
    {
        node.data = malloc(sizeof(int) * size);
        // if it is a array every slot of it will be setted
        for (i = 0; i < size; i++)
        {
            ((int *)node.data)[i] = ((int *)data)[i];
        }
        break;
    }
    case Long:
    {
        node.data = malloc(sizeof(long) * size);
        // if it is a array every slot of it will be setted
        for (i = 0; i < size; i++)
        {
            ((long *)node.data)[i] = ((long *)data)[i];
        }
        break;
    }
    case Float:
    {
        node.data = malloc(sizeof(float) * size);
        // if it is a array every slot of it will be setted
        for (i = 0; i < size; i++)
        {
            ((float *)node.data)[i] = ((float *)data)[i];
        }
        break;
    }
    case Double:
    {
        node.data = malloc(sizeof(double) * size);
        // if it is a array every slot of it will be setted
        for (i = 0; i < size; i++)
        {
            ((double *)node.data)[i] = ((double *)data)[i];
        }
        break;
    }
    case Char:
    {
        node.data = malloc(sizeof(char) * size);
        // if it is a array every slot of it will be setted
        for (i = 0; i < size; i++)
        {
            ((char *)node.data)[i] = ((char *)data)[i];
        }
        break;
    }
    case Bool:
    {
        node.data = malloc(sizeof(bool) * size);
        // if it is a array every slot of it will be setted
        for (i = 0; i < size; i++)
        {
            ((bool *)node.data)[i] = ((bool *)data)[i];
        }
        break;
    }
    default:
    {
        node.data = data;
        break;
    }
    }
    return node;
}

void node_destructor(struct Node *node)
{
    free(node->data);
    free(node);
}