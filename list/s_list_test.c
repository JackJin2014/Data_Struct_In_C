#include "s_list.h"
#include <stdio.h>

int main(void)
{
    Ele e1 = 11;
    Ele e2 = 22;
    Ele e3 = 33;


    PList pl = create();

    push_front(pl, &e1);
    push_front(pl, &e2);
    push_front(pl, &e3);
    push_back(pl, &e2);
    insert(pl, 1, &e3);
    show(pl);
    printf("_____________________\n");
#if 0
    remove_front(pl);
    remove_back(pl);
    show(pl);
    printf("_____________________\n");

    Ele e8 = 88;
    Ele e9 = 99;
    Ele e7 = 77;
    set_front(pl, &e8);
    set_back(pl, &e9);
    set(pl, 3, &e7);
    show(pl);

#endif
    
    PNode head = get_front(pl);
    PNode mid = get(pl, 3);
    PNode tail = get_back(pl);
    printf("head = %d \n", *mid);

//printf("head = %d \t mid = %d \t tail = %d .\n", *head, *mid , *tail);

    destory(pl);
    return 0;
}
