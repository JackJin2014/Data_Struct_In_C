/**
 * @file sc_list.h
 * @brief 单循环链表实现文件
 * @author Jack Jin - gjinjian@gmail.com
 * @version v0.1
 * @date 2014-02-14
 */
#include "sc_list.h"
#include <malloc.h>
#include <assert.h>
#include <stdio.h>

/**
 * @brief 
 *
 * @return 
 */
PList   create(void)
{
    PList pl = (PList)malloc(sizeof(List));
    if(pl == NULL)  return NULL;

    pl->head.next = &pl->head;
    return pl;
}


/**
 * @brief 销毁单向循环链表
 *  注意边界的判断
 * @param PList
 */
void    destory(PList pl)
{
    assert(pl != NULL);
    PNode pn, head = pl->head.next;
    while(head != &pl->head){
        pn = head->next;
        free(head);
        head = pn;
    }
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

int     insert(PList pl, size_t index, PEle pe)
{
    if(pl == NULL || pe == NULL || index > size(pl))  return 0;
    PNode pn;
    if(index == 0)
        pn = &pl->head;
    else{
        pn = get(pl, index-1);
        if(pn == NULL)  return 0;
    }

    PNode n = (PNode)malloc(sizeof(Node));
    n->ele = *pe;
    n->next = pn->next;
    pn->next = n;
    return 1;
}


int     remove_front(PList pl)
{
    return mremove(pl, 0);
}

int     remove_back(PList pl)
{
    return mremove(pl, size(pl)-1);
}

int     mremove(PList pl, size_t index)
{
    if(pl == NULL || index > size(pl)) return 0;
    PNode pn;

    if(index == 0)
        pn = &pl->head;
    else{
        pn = get(pl, index-1);
        if(pn == NULL) return 0;
    }

    pn->next = pn->next->next;
    return 1;
}


int     set_front(PList pl, PEle pe)
{
    return set(pl, 0, pe);
}

int     set_back(PList pl, PEle pe)
{
    set(pl, size(pl)-1, pe);
}

int     set(PList pl, size_t index, PEle pe)
 {
    if(pl == NULL || pe == NULL) return 0;
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
    return get(pl, size(pl)-1);
}

PNode   get(PList pl, size_t index)
{
    if(pl == NULL || index > size(pl)) return NULL;
    PNode pn = pl->head.next;
    int cnt=0;
    while(cnt != index){
        pn = pn->next;
        cnt++;
    }
    return pn;
}

size_t  size(PList pl)
{
    assert(pl != NULL);
    int cnt = 0;
    PNode pn = pl->head.next;

    while(pn != &pl->head){
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

    while(pn != &pl->head){
        printf("%-4d %-4d\n", i++, pn->ele);
        pn = pn->next;
    }
    return 1;
}




