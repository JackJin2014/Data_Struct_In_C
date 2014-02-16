/**
 * @file sc_list.h
 * @brief 单循环链表接口文件
 * @author Jack Jin - gjinjian@gmail.com
 * @version v0.1
 * @date 2014-02-14
 */

#ifndef _SC_LIST_H_
#define _SC_LIST_H_

#include "element.h"

typedef struct node     Node;
typedef struct node*    PNode;

struct node{
    Ele     ele;
    PNode   next;
};

typedef struct list{
    Node head;
}List, *PList;

extern  PList   create(void);
extern  void    destory(PList);

extern  int     push_front(PList, PEle);
extern  int     push_back(PList, PEle);
extern  int     insert(PList, size_t index, PEle);

extern  int     remove_front(PList);
extern  int     remove_back(PList);
extern  int     mremove(PList, size_t index);

extern  int     set_front(PList, PEle);
extern  int     set_back(PList, PEle);
extern  int     set(PList, size_t index, PEle);

//以下接口也可以设计成通过指针回传结果
extern  PNode   get_front(PList);
extern  PNode   get_back(PList);
extern  PNode   get(PList, size_t index);

extern  size_t  size(PList);
extern  int     show(PList);


#endif
