#include <stdio.h>
#include "./LinkedList/LinkedList.h"

int main(int argc, char const *argv[])
{
    struct LinkedList_int list = linked_list_int_constructor();

    for (int i = 0; i < 10; i++)
    {
        list.insert(i, i, &list);
    }

    for (int i = 0; i < 10; i++)
    {
        printf("\n%d", list.retrieve(i, &list));
        /* code */
    }

    /* code */
    return 0;
}
