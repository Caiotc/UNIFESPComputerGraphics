#include "./Node.h"

#include <string.h>

// struct Node node_contructor(void *data, int size)
// {
//     if (size < 1)
//     {
//         printf("\ninvalid data size for Node");
//         exit(1);
//     }

//     struct Node node;
//     // alocate mem size for the data
//     node.data = malloc(size);

//     // sets data to the node.data
//     memccpy(node.data, data, size);
//     node.next = NULL;

//     return node;
// }

// void node_destructor(struct Node *node)
// {
//     free(node->data);
//     free(node);
// }