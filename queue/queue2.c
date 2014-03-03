/**
 * @file queue.h
 * @brief 使用一维数组实现队列——接口文件
 *          使用方法2：循环队列,在嵌入式串口编程中常用
 * @author Jack Jin - gjinjian@gmail.com
 * @version v0.1
 * @date 2014-01-22
 */

#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static  Ele     queue[MAX_SIZE];
static  size_t  head=0;   //取元素的索引,范围0-[MAX_SIZE-1]
static  size_t  tail=0;   //存元素的索引,范围0-[MAX_SIZE-1]

/**
 * @brief 
 *  将元素ele入队
 * @param Ele   
 * @return 成功返回1，失败返回0
 */
int  enqueue(Ele ele)
{
    if(is_full())   return 0;
    queue[tail++] = ele;
    tail %= MAX_SIZE;

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
    Ele ele = queue[head++];
    head %= MAX_SIZE;
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
    return queue[head];
}


/**
 * @brief 
 *  判断队列是否为空
 * @return 空为真
 */
bool is_empty(void)
{
    if(head == tail)   
        return true;
    else
        return false;
}


/**
 * @brief 
 *  判断队列是否满
 * @return 满为真
 */
bool is_full(void)
{
    if(abs(tail - head) == MAX_SIZE - 1)    // abs() 求绝对值
        return true;
    else
        return false;
}


/**
 * @brief 
 *  查询队列大小
 * @return 返回队列大小
 */
size_t   size(void)
{
    return (abs(tail - head));
}


