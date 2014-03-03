/**
 * @file queue.h
 * @brief 使用一维数组实现队列——实现文件
 *      使用方法1：移动元素,效率低下
 * @author Jack Jin - gjinjian@gmail.com
 * @version v0.1
 * @date 2014-01-22
 */

#include "queue.h"
#include <stdlib.h>

static Ele  queue[MAX_SIZE];
static int  counter;


/**
 * @brief 
 *  把元素e放入队列queue中
 * @param e
 *
 * @return 成功1，失败0
 */
int  enqueue(Ele e)
{
    if(is_full())
        return 0;
    else
        queue[counter++] = e;
    return 1;
}

// 方法1
static void move(void)
{
    int i = 0;
    for(; i < counter - 1; i++)
        queue[i] = queue[i+1];
}

/**
 * @brief 
 *  从队列头部取出一个元素: 两种处理方法：移动、循环队列
 * @return 成功返回该元素，失败退出
 */
Ele  dequeue(void)
{
    if(is_empty())
        exit(1);
    else{
        Ele e = queue[0];
        move();
        counter--;

        return e;
    }
    exit(1);
}


/**
 * @brief 
 *  复制队列头元素
 * @return 头元素
 */
Ele  cpqueue(void)
{
    if(is_empty())
        exit(1);
    else
        return queue[0];
}


/**
 * @brief 
 *  队列是否为空
 * @return 空为真
 */
bool is_empty(void)
{
    if(counter == 0)
        return true;
    else
        return false;
}


/**
 * @brief 
 *  队列是否为满
 * @return 满为真
 */
bool is_full(void)
{
    if(counter == MAX_SIZE)
        return true;
    else
        return false;
}


/**
 * @brief 
 *  查询队列大小
 * @return 队列大小
 */
size_t   size(void)
{
    return counter;
}


