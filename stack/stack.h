/**
 * @file stack.h
 * @brief 使用一维数组实现堆栈
 * @author Jack Jin - gjinjian@gmail.com
 * @version v0.1
 * @date 2014-01-22
 */

#ifndef __STACK_H__
#define __STACK_H__

#include "element.h"
#include <stdbool.h>

#define MAX_SIZE    100

extern int  push(Ele);
extern Ele  pop(void);
extern Ele  top(void);
extern bool is_full(void);
extern bool is_empty(void);
extern size_t size(void);

#endif
