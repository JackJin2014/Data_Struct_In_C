/**
 * @file stack_list.c
 * @brief 使用链表实现堆栈
 * @author Jack Jin - gjinjian@gmail.com
 * @version v0.1
 * @date 2014-03-02
 */
#include <stdlib.h>
#include "element.h"
#include "stack.h"


typedef struct node     Node;
typedef struct node*    PNode;

struct node{
    Ele     ele;
    PNode   next;
};

typedef struct list{
    Node head;
}List, *PList;

static PList pl;
static size_t counter;

PNode NEW(Ele ele, PNode next)
{
    PNode pn = (PNode)malloc(sizeof(Node));
    if(pn == NULL)  return NULL;

    pn->ele = ele;
    pn->next = next;

    return pn;
}


void init(size_t max)
{
    pl = (PList)malloc(sizeof(List));
    assert(pl != NULL);

    pl->head.next = NULL;          //使用单链表实现
    //pl->head.next = &pl->head;   //使用单循环链表实现
    counter = 0;
}

int  push(Ele ele)
{
     pl->head.next = NEW(ele, pl->head.next);
     ++counter;
}

Ele  pop(void)
{
    if(is_empty())  exit(1);

    Ele ele = pl->head.next->ele;
    PNode pn = pl->head.next->next;
    free(pl->head.next);
    pl->head.next = pn;

    counter--;
    return ele;
}


/**
 * @brief 
 *  使用链表实现的top和pop没区别，没有counter的差别
 * @return 
 */
Ele  top(void)
{
    return pop();
}

bool is_full(void)
{
    return false;
}

bool is_empty(void)
{
    if(pl->head.next == NULL)
        return true;
    else
        return false;
}


size_t size(void)
{
    return counter;
}


