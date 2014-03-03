/**
 * @file queue.h
 * @brief 使用一维数组实现队列——接口文件
 * @author Jack Jin - gjinjian@gmail.com
 * @version v0.1
 * @date 2014-01-22
 */

#ifndef __QUEUE_H__
#define __QUEUE_H__

#include "element.h"
#include <stdbool.h>

#define MAX_SIZE    100


/**
 * @brief 
 *  将元素ele入队
 * @param Ele   
 * @return 成功返回1，失败返回0
 */
extern int  enqueue(Ele);

/**
 * @brief 
 *  从队列头部取出元素
 * @return 成功返回头元素，失败退出
 */
extern Ele  dequeue(void);

/**
 * @brief 
 *  从队列头部复制头元素
 * @return 成功返回头元素，失败退出
 */
extern Ele  cpqueue(void);


/**
 * @brief 
 *  判断队列是否为空
 * @return 空为真
 */
extern bool is_empty(void);

/**
 * @brief 
 *  判断队列是否满
 * @return 满为真
 */
extern bool is_full(void);

/**
 * @brief 
 *  查询队列大小
 * @return 返回队列大小
 */
extern size_t   size(void);

#endif
