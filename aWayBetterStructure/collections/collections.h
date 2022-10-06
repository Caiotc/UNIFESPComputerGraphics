#ifndef __COLLECTIONS_H
#define __COLLECTIONS_H
#include "../structs/abstractTypes.h"

node_coordinates *init_node_coordinates_list(float x, float y);
void add_node_to_list_end(node_coordinates **head, float x, float y);
void remove_node_of_list_begin(node_coordinates **head);
void remove_node_of_list_end(node_coordinates *head);
void interate_over_list(void (*callback)(), node_coordinates *head);

#endif