/**
 * @file s_list.h
 * @brief 单链表接口文件
 * @author Jack Jin - gjinjian@gmail.com
 * @version v0.1
 * @date 2014-01-22
 */

#ifndef _S_LIST_H_
#define _S_LIST_H_

#include "element.h"

typedef unsigned int size_t;

/*
typedef struct node{
    PNode  prev;
    Ele     ele;
    PNode  next;
}Node, *PNode;
*/
struct node{
    Ele     ele;
    struct node*  next;
};

typedef struct node     Node;
typedef struct node *   PNode;

//哑节点
typedef struct list{
    Node    head;
}List, *PList;

extern  PList create(void);
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

//extern PNode get_prev(PNode pn, size_t index);

#endif
