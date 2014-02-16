#include "vector.h"
#include <stdio.h>

int main(void)
{
    PVector pv = create();
    Ele e1=111;
    Ele e2=222;
    Ele e3=333;
    Ele e4=444;
    Ele e5=555;
    
    push_front(pv, &e1);
    push_front(pv, &e2);
    push_back(pv, &e3);
    insert(pv, 1, &e4);
    push_back(pv, &e5);
    show(pv);

#if 0
    remove_front(pv);
    show(pv);
    remove_back(pv);
    show(pv);
    mremove(pv, 3);
    show(pv);

#endif  
//#if 0
    set_front(pv, &e4);
    show(pv);
    set_back(pv, &e1);
    show(pv);
    set(pv, 2, &e2);
    show(pv);
//#endif

    destory(pv);

    return 0;
}
