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

extern int  enqueue(Ele);
extern Ele  dequeue(void);
extern Ele  cpqueue(void);
extern bool is_empty(void);
extern bool is_full(void);
extern size_t   size(void);

#endif
