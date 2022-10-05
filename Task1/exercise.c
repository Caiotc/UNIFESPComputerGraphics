#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

typedef struct node
{
    int val;
    struct node *next;
    /* data */
} node_t;

void print_list(node_t *head)
{
    node_t *current = head;

    while (current != NULL)
    {
        printf("%d\n", current->val);
        current = current->next;
    }
}

void add_node(node_t *head, int value)
{
    node_t *current = head;
    node_t *newNode = (node_t *)malloc(sizeof(node_t));

    while (current->next != NULL)
    {
        current = current->next;
    }
    newNode->val = value;
    newNode->next = NULL;
    current->next = newNode;
}

void display(void (*p)())
{
    for (int i = 0; i < 5; i++)
    {
        p(i);
        /* code */
    }
}
void print_numbers(int num)
{
    printf("valor aleatorio %i \n", num);
}

int main(int argc, char *argv[])
{

    /* code */
    return 0;
}
