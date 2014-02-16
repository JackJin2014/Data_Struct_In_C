/**
 * @file s_list.h
 * @brief 单链表实现文件
 * @author Jack Jin - gjinjian@gmail.com
 * @version v0.1
 * @date 2014-01-22
 */

#include "s_list.h"
#include <malloc.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

PList   create(void)
{
    PList pl = (PList)malloc(sizeof(List));
    if(pl == NULL)  return NULL;
    pl->head.next = NULL;
    return pl;
}


static void destory_node(PNode pn)
{
    if(pn == NULL)  return;
    destory_node(pn->next);
    free(pn);
}

void    destory(PList pl)
{
    assert(pl != NULL);
    destory_node(pl->head.next);
    free(pl);
    pl = NULL;
}


int     push_front(PList pl, PEle pe)
{
    return insert(pl, 0, pe);
}

int     push_back(PList pl, PEle pe)
{
    return insert(pl, size(pl), pe);
}

static  PNode get_prev(PNode pn, size_t index)
{
    if(pn == NULL)  return NULL;
    if(index == 0)  return pn;
    get_prev(pn->next, index-1);
}

int     insert(PList pl, size_t index, PEle pe)
{
    if(pl == NULL || pe == NULL || index > size(pl))  return 0;
    PNode pn = get_prev(&pl->head, index);
    if(pn == NULL)  return 0;

    // 新节点使用 动态分配的方法，不要使用 Node 
    PNode node = (PNode)malloc(sizeof(Node));
    node->ele = *pe;

    if(pn->next != NULL)
        node->next = pn->next;
    else
        node->next = NULL;
    pn->next = node;
    return 1;

}


int     remove_front(PList pl)
{
    return  mremove(pl, 0);
}

int     remove_back(PList pl)
{
    return mremove(pl, size(pl)-1);     //注意-1
}

int     mremove(PList pl, size_t index)
{
    if(pl == NULL || index > size(pl))  return 0;
    PNode pn = get_prev(&pl->head, index);
    if(pn == NULL)  return 0;

    PNode p = pn->next->next;
    free(pn->next);
    pn->next = p;
    return 1;
}

int     set_front(PList pl, PEle pe)
{
    set(pl, 0, pe);
}

int     set_back(PList pl, PEle pe)
{
    set(pl, size(pl)-1, pe);
}

int     set(PList pl, size_t index, PEle pe)
{
    if(pe == NULL)  return 0;
    PNode pn = get(pl, index);
    if(pn == NULL)  return 0;
    pn->ele = *pe;
    return 1;
}


//以下接口也可以设计成通过指针回传结果
PNode   get_front(PList pl)
{
    return get(pl, 0);
}

PNode   get_back(PList pl)
{
    return get(pl, size(pl) - 1);   //注意-1
}

PNode   get(PList pl, size_t index)
{
    return get_prev(&pl->head, index+1);
}


size_t  size(PList pl)
{
    if(pl == NULL)  exit(1);
    size_t cnt =0;
    PNode pn = pl->head.next;

    while(pn != NULL){
        pn = pn->next;
        cnt++;
    }
    return cnt;
}

int     show(PList pl)
{
    if(pl == NULL) return 0;
    printf("Index\tEle Size:%d \n", size(pl));

    int i = 0;
    PNode pn = pl->head.next;

    while(i != size(pl)){
        printf("%-4d\t\t%d\n", i++, pn->ele);
        pn = pn->next;
    }
    return 1;
}


// PNode get_prev(PNode pn, size_t index);

