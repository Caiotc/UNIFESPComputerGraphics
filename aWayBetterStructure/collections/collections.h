#ifndef __COLLECTIONS_H
#define __COLLECTIONS_H
#include "../structs/types_and_consts.h"

node_coordinates *init_node_coordinates_list(float x, float y, int modeToDraw, int strokeSize, int colorSelector);
int calculate_list_size(node_coordinates *head);
void add_node_to_list_end(node_coordinates **head, float x, float y, int modeToDraw, int strokeSize, int colorSelector);
void remove_node_of_list_begin(node_coordinates **head);
void remove_node_of_list_end(node_coordinates **head);
void interate_over_list(void (*callback)(), node_coordinates *head);
void iterate_over_list_repass_every_two_points(void (*callback)(), node_coordinates *head);

#endif