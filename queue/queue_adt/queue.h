/**
 * @file queue.h
 * @brief 一级队列接口
 *  基本ADT操作的对象是元素—————— 单例ADT
 *  一级ADT操作的对象是基本ADT————多例ADT
 * @author Jack Jin - gjinjian@gmail.com
 * @version V0.1
 * @date 2014-03-05
 */

#ifndef __QUEUE_H__
#define __QUEUE_H__

#include "element.h"
#include <stdbool.h>

#define MAX_SIZE    100

typedef struct queue    Queue;
typedef struct queue*   PQueue;
typedef struct node     Node;
typedef struct node*    PNode;

struct node {
    Ele     ele;
    PNode   next;
};

struct queue{
    PNode   head;
    PNode   tail;
    size_t  counter;
};




extern PQueue  init(int);

/**
 * @brief 
 *  将元素ele插入PQueue
 * @param PQueue
 * @param Ele
 * @return 成功返回1，失败返回0
 */
extern int  enqueue(PQueue, Ele);

extern Ele  dequeue(PQueue);

extern Ele  cpqueue(PQueue);


extern bool is_empty(PQueue);

extern bool is_full(PQueue);

extern size_t   size(PQueue);

#endif
