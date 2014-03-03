/**
 * @file stack.h
 * @brief 堆栈接口
 *  一维数组实现stack_array.c 
 *  使用动态内存分配实现stack_mem.c
 *  链表实现stack_list.c
 * @author Jack Jin - gjinjian@gmail.com
 * @version v0.1
 * @date 2014-01-22
 */

#ifndef __STACK_H__
#define __STACK_H__

#include "element.h"
#include <stdbool.h>

#define MAX_SIZE    100

extern void init(size_t);
extern int  push(Ele);
extern Ele  pop(void);
extern Ele  top(void);
extern bool is_full(void);
extern bool is_empty(void);
extern size_t size(void);

#endif
