#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    Ele e = 30;
    int i = 0;

    PTree pt = create_tree(&e);
    for(; i < 100; i++){
        e = (Ele)(drand48()*1000);
        add_element(pt, &e);
    }

    mid_traverse(pt);
    printf("\n-----------------------\n");
    printf("tree size = %d.\n", size_tree(pt));


    for( i = 0; i < 51; i++){
        e = (Ele)(drand48()*1000);
        remove_element(pt, &e);
    }   

    mid_traverse(pt);
    printf("\n-----------------------\n");
    printf("tree size = %d.\n", size_tree(pt));

    destroy_tree(pt);
    pt = NULL;
    return 0;
}
