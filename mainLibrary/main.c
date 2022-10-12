#include <stdio.h>
#include "./LinkedList/LinkedList.h"

int main(int argc, char const *argv[])
{
    struct LinkedList list = linked_list_constructor();

    for (int i = 0; i < 10; i++)
    {
        list.insert(i, &i, 1, Int, &list);
    }

    for (int i = 0; i < 10; i++)
    {
        printf("\n%d", ((int *)list.retrieve(i, &list))[0]);
        /* code */
    }

    /* code */
    return 0;
}
