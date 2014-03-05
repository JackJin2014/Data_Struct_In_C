/**
 * @file queue.c
 * @brief 一级队列实现
 *  基本ADT操作的对象是元素—————— 单例ADT
 *  一级ADT操作的对象是基本ADT————多例ADT
 * @author Jack Jin - gjinjian@gmail.com
 * @version V0.1
 * @date 2014-03-05
 */

#include "queue.h"
#include <stdlib.h>
#include <assert.h>

static PNode new(Ele ele, PNode next)
{
    PNode pn = (PNode)malloc(sizeof(Node));
    assert(pn != NULL);
    pn->ele = ele;
    pn->next = next;
    return pn;
}


PQueue  init(int max)
{
    PQueue pq = (PQueue)malloc(sizeof(Queue));
    assert(pq != NULL);
    pq->head = NULL;
    pq->counter = 0;

    return pq;
}



/**
 * @brief 
 *  将元素ele插入PQueue
 * @param PQueue
 * @param Ele
 * @return 成功返回1，失败返回0
 */
int  enqueue(PQueue pq, Ele ele)
{
    if(pq->head == NULL){
        pq->tail = new(ele, pq->head);
        pq->head = pq->tail;
        return 1;       //  忘了,导致每个队列前两个元素一样
    } 

    pq->tail->next = new(ele, pq->tail->next);
    pq->tail = pq->tail->next;

    pq->counter++;
    return 1;

}


Ele  dequeue(PQueue pq)
{
    if(is_empty(pq)) exit(1);

    Ele ele = pq->head->ele;
    PNode pn = pq->head->next;
    free(pq->head);
    pq->head = pn;

    pq->counter--;

    return ele;
}


Ele  cpqueue(PQueue pq)
{    
    if(is_empty(pq)) exit(1);
    return pq->head->ele;
}



bool is_empty(PQueue pq)
{
    if(pq->head == NULL)
        return true;
    else
        return false;
}


bool is_full(PQueue pq)
{
    return false;
}


size_t   size(PQueue pq)
{
    return pq->counter;
}


