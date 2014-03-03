/**
 * @file queue_list.c
 * @brief  使用链表实现队列
 * @author Jack Jin - gjinjian@gmail.com
 * @version V0.1
 * @date 2014-03-03
 */
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef struct node     Node;
typedef struct node*    PNode;

struct node{
    Ele     ele;
    PNode   next;
};

static PNode head, tail;
static size_t counter;


static PNode NEW(Ele ele, PNode next)
{
    PNode pn = (PNode)malloc(sizeof(Node));
    assert(pn != NULL);
    pn->ele = ele;
    pn->next = next;
    return pn;
}

void init(int max)
{
    head = NULL;
    tail = NULL;
    counter = 0;
}

/**
 * @brief 
 *  将元素ele入队
 * @param Ele   
 * @return 成功返回1，失败返回0
 */
int  enqueue(Ele ele)
{
    if(is_empty()){
        tail = NEW(ele, head); 
        head = tail;
        counter++;
        return 1;
     }

    tail->next = NEW(ele, tail->next);
    tail = tail->next;
    counter++;

    return 1;
}


/**
 * @brief 
 *  从队列头部取出元素
 * @return 成功返回头元素，失败退出
 */
Ele  dequeue(void)
{
    if(is_empty())  exit(1);
    Ele ele = head->ele;
    PNode tmp = head->next;
    free(head);
    head = tmp;
    counter--;

    return ele;
}


/**
 * @brief 
 *  从队列头部复制头元素
 * @return 成功返回头元素，失败退出
 */
Ele  cpqueue(void)
{
    if(is_empty())  exit(1);
    return head->ele;
}



/**
 * @brief 
 *  判断队列是否为空
 * @return 空为真
 */
bool is_empty(void)
{
    if (head == NULL)
        return true;
    else
        return false;
}


/**
 * @brief 
 *  判断队列是否满, 列表实现默认false
 * @return 满为真
 */
bool is_full(void)
{
    return false;
}


/**
 * @brief 
 *  查询队列大小
 * @return 返回队列大小
 */
size_t   size(void)
{
    return counter;
}


