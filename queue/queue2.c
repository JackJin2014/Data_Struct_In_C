/**
 * @file queue.h
 * @brief 使用一维数组实现队列——接口文件
 *          使用方法2：循环队列
 * @author Jack Jin - gjinjian@gmail.com
 * @version v0.1
 * @date 2014-01-22
 */

#include "queue.h"

static  Ele     queue[MAX_SIZE];
static  size_t  head;   //取元素的索引
static  size_t  tail;   //存元素的索引

int  enqueue(Ele)
{
    if(is_full())   return 0;
    

}

Ele  dequeue(void);
Ele  cpqueue(void);
bool is_empty(void);
bool is_full(void);
size_t   size(void);

