#include <stdio.h>
#include "./Lists/LinkedList.h"
#include "./Lists/Queue.h"



struct banana{
    int c;
};

struct banana banana_constructor(){
    struct banana new;
    new.c = 62;
    return new;
}
struct merda{
    float a;
    float b;
    struct Queue queue;
};
struct merda construct_merda(){
    struct merda new;
    new.a = 0.2f;
    new.b = 24.0f;
    new.queue = queue_constructor();
    return new;
}
int main(int argc, char const *argv[])
{
    struct merda teste = construct_merda();
    struct banana teste2 = banana_constructor();


    
    teste.queue.push(& teste.queue, &teste2, sizeof(teste2));

    printf("peek %i \n", ((struct banana *)teste.queue.peek(&teste.queue))->c);    

    /* code */
    return 0;
}
