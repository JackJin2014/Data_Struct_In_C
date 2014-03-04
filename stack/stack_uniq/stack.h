/**
 * @file stack.h
 * @brief 堆栈接口
 *  使用动态内存分配实现stack_mem.c
 *  压栈时保证元素的唯一性，可以避免重复`
 *      前提：假定元素值的范围是0-max_size-1
 * @author Jack Jin - gjinjian@gmail.com
 * @version v0.1
 * @date 2014-03-04
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
