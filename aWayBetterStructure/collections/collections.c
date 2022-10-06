#include "collections.h"
#include "../utils/uselfullcallbacks.h"
#include <stdlib.h>
#include <stdio.h>

node_coordinates *init_node_coordinates_list(float x, float y)
{
    node_coordinates *head = (node_coordinates *)malloc(sizeof(node_coordinates));
    head->x = x;
    head->y = y;
    head->next = NULL;

    return head;
}

void add_node_to_list_end(node_coordinates **head, float x, float y)
{
    // if its not initialized then init
    node_coordinates *current = *head;
    node_coordinates *newNode = (node_coordinates *)malloc(sizeof(node_coordinates));

    if (*head == NULL)
    {
        printf("!@# entrou aqui\n");
        *head = init_node_coordinates_list(x, y);
        // print_node_values(*head);
        return;
    }

    while (current->next != NULL)
    {
        current = (node_coordinates *)current->next;
    }

    newNode->x = x;
    newNode->y = y;
    newNode->next = NULL;

    current->next = (struct node_coordinates *)newNode;
}

void remove_node_of_list_begin(node_coordinates **head)
{
    int listSize = 1;
    node_coordinates *current = *head;
    node_coordinates *nextNode = NULL;

    if (*head == NULL)
        return;
    while (current->next != NULL)
    {
        listSize++;
        current = (node_coordinates *)current->next;
    }
    if (listSize == 1)
        return;

    nextNode = (node_coordinates *)(*head)->next;
    free(*head);
    *head = nextNode;
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