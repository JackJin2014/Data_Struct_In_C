#include "d_list.h"
#include <stdio.h>
#include <assert.h>

int main(void)
{
    PList pl = create(); 
    assert(pl != NULL);

    Ele e1 = 111;
    Ele e2 = 222;
    Ele e3 = 333;

    push_front(pl, &e1);
    if( push_back(pl, &e2) )   //segment fault
        printf("push_back sucess!\n");
    else 
        printf("fail\n");

    insert(pl, 0, &e3);     
    if(insert(pl, size(pl), &e3))
        printf("sucess\n");
    else 
        printf("fail\n");
    show(pl);
#if 0
    remove_front(pl);
    remove_back(pl);
    mremove(pl, 0);

    Ele e9 = 999;
    set_front(pl, &e9);
    set_back(pl, &e9);
    set(pl, 1, &e9);
    
    PNode pn = get_front(pl);
    printf("%d \n", pn->ele);

    pn = get_back(pl);
    printf("%d \n", pn->ele);

    pn = get(pl, 1);
    printf("%d \n", pn->ele);

#endif

    //test get_prev()
#if 0
    PNode pn = get_prev(&pl->head, 3);
    if(pn == NULL)
        printf("error\n");
    else
        printf("%d \n", pn->ele);
#endif
   // show(pl);
    destory(pl);
    return 1;
}
