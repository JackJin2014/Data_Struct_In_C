/**
 * @file sc_list_test.c
 * @brief 单向循环链表测试文件
 * @author Jack Jin - gjinjian@gmail.com
 * @version v0.1
 * @date 2014-02-16
 * 2014-02-16 19:33 接口测试成功
 */

#include "sc_list.h"

#include <stdio.h>
#include <assert.h>

int main(void)
{ 
    PList pl = create();
    assert(pl != NULL);

    int e1 = 11;
    int e2 = 22;
    int e3 = 33;

    int e4 = 44;

    push_front(pl, &e1);
    push_front(pl, &e2);
    push_front(pl, &e3);
    push_back(pl, &e4);
    remove_back(pl);

    //insert(pl, 2, &e2);

    show(pl);
#if 0    
    remove_front(pl);
    remove_back(pl);
    mremove(pl, 2);

    set_front(pl, &e4);
    set_back(pl, &e4);
    set(pl, 3, &e3);

    show(pl);
#endif

    printf(" front=%d mid=%d back=%d \n", get_front(pl)->ele, get(pl, 1)->ele, get_back(pl)->ele);

    destory(pl);
    return 0;
}
