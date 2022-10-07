#include "collections.h"
#include "../utils/uselfullcallbacks.h"
#include <stdlib.h>
#include <stdio.h>

int calculate_list_size(node_coordinates *head)
{
    node_coordinates *current = head;
    int listSize = 0;
    while (current != NULL)
    {
        current = (node_coordinates *)current->next;
        listSize++;
        /* code */
    }
    return listSize;
}
node_coordinates *init_node_coordinates_list(float x, float y, int modeToDraw, int strokeSize, int colorSelector)
{
    node_coordinates *head = (node_coordinates *)malloc(sizeof(node_coordinates));
    head->x = x;
    head->y = y;
    head->modeToDraw = modeToDraw;
    head->strokeSize = strokeSize;
    head->colorSelector = colorSelector;
    head->next = NULL;

    return head;
}

void add_node_to_list_end(node_coordinates **head, float x, float y, int modeToDraw, int strokeSize, int colorSelector)
{
    // if its not initialized then init
    node_coordinates *current = *head;
    node_coordinates *newNode = (node_coordinates *)malloc(sizeof(node_coordinates));

    if (*head == NULL)
    {
        *head = init_node_coordinates_list(x, y, modeToDraw, strokeSize, colorSelector);
        // print_node_values(*head);
        return;
    }

    while (current->next != NULL)
    {
        current = (node_coordinates *)current->next;
    }

    newNode->x = x;
    newNode->y = y;
    newNode->modeToDraw = modeToDraw;
    newNode->strokeSize = strokeSize;
    newNode->colorSelector = colorSelector;
    newNode->next = NULL;

    current->next = (struct node_coordinates *)newNode;
}

void remove_node_of_list_begin(node_coordinates **head)
{
    int listSize = 1;
    node_coordinates *current = *head;
    node_coordinates *nextNode = NULL;
    printf("\n!@# chegou aqui se liga no nodo");
    print_node_values(*head);
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

void remove_node_of_list_end(node_coordinates **head)
{
    node_coordinates *current = *head;
    node_coordinates *currentOneAhead;

    if (current == NULL)
        return;
    if (current->next == NULL)
    {
        printf("\n!@# mano eu ja to no fim da lista");
        free(*head);
        *head = NULL;
        return;
    }
    currentOneAhead = (node_coordinates *)current->next;

    while (currentOneAhead->next != NULL)
    {
        current = (node_coordinates *)current->next;
        currentOneAhead = (node_coordinates *)currentOneAhead->next;
    }

    print_node_values(current);
    print_node_values(currentOneAhead);

    free(currentOneAhead);
    current->next = NULL;
}

void iterate_over_list_repass_every_two_points(void (*callback)(), node_coordinates *head)
{
    int listSize = calculate_list_size(head);
    int lastEvenNum = listSize - (listSize % 2);
    int numOfRunThoughs = lastEvenNum / 2;
    int i = 1;
    node_coordinates *current = head;
    node_coordinates *currentOneAhead;

    if (head == NULL)
        return;
    if (head->next == NULL)
    {
        return;
    }
    currentOneAhead = (node_coordinates *)current->next;

    for (i; i <= numOfRunThoughs; i++)
    {
        callback(current, currentOneAhead);
        current = (node_coordinates *)currentOneAhead->next;
        if (current != NULL)
            currentOneAhead = (node_coordinates *)current->next;
    }
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