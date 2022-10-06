#include "collections.h"
#include <stdlib.h>

node_coordinates *init_node_coordinates_list(float x, float y)
{
    node_coordinates *head = (node_coordinates *)malloc(sizeof(node_coordinates));
    head->x = x;
    head->y = y;
    head->next = NULL;

    return head;
}

void add_node_to_list(node_coordinates *head, float x, float y)
{
    node_coordinates *current = head;
    node_coordinates *newNode = (node_coordinates *)malloc(sizeof(node_coordinates));

    while (current->next != NULL)
    {
        current = (node_coordinates *)current->next;
    }

    newNode->x = x;
    newNode->y = y;
    newNode->next = NULL;

    current->next = (struct node_coordinates *)newNode;
}

void interate_over_list(void (*callback)(), node_coordinates *head)
{
    node_coordinates *current = head;

    while (current != NULL)
    {
        callback(current);
        current = (node_coordinates *)current->next;
        /* code */
    }
}