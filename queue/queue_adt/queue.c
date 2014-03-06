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


/**
 * @brief 
 *  创建一个新节点
 * @param Ele
 * @param next
 *
 * @return 返回该新节点
 */
static PNode new(Ele ele, PNode next)
{
    PNode pn = (PNode)malloc(sizeof(Node));
    assert(pn != NULL);
    pn->ele = ele;
    pn->next = next;
    return pn;
}


/**
 * @brief 
 *  创建一个队列，分配空间
 * @param max
 *
 * @return 返回该队列的指针
 */
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


/**
 * @brief 
 *  从oq队列中出队一个元素
 * @param PQueue
 *
 * @return 返回头元素
 */
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


/**
 * @brief 
 *  复制pq队列的首元素
 * @param PQueue
 *
 * @return 首元素的拷贝
 */
Ele  cpqueue(PQueue pq)
{    
    if(is_empty(pq)) exit(1);
    return pq->head->ele;
}



/**
 * @brief 
 *  pq是否是空队列
 * @param PQueue
 *
 * @return 是否？
 */
bool is_empty(PQueue pq)
{
    if(pq->head == NULL)
        return true;
    else
        return false;
}


/**
 * @brief 
 *  链表实现，假定不可能满
 * @param PQueue
 *
 * @return false，不可能满
 */
bool is_full(PQueue pq)
{
    return false;
}


/**
 * @brief 
 *  pq队列的大小
 * @param PQueue
 *
 * @return 队列大小
 */
size_t   size(PQueue pq)
{
    return pq->counter;
}


