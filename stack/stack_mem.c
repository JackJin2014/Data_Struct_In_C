/**
 * @file stack_mem.c
 * @brief 堆栈实现文件
 *      使用动态内存分配实现堆栈
 * @author Jack Jin - gjinjian@gmail.com
 * @version v0.1
 * @date 2014-03-03
 */
#include "stack.h"
#include <stdlib.h>

static PEle     stack;
static size_t   counter;
static size_t   max_size;


void init(size_t max)
{
    max_size = max;
    stack = (PEle)malloc(max*sizeof(Ele));
    counter = 0;
}

int  push(Ele ele)
{
    if(is_full())   return 0;
    stack[counter++] = ele;
    return 1;
}

Ele  pop(void)
{
    if(is_empty())  exit(1);
    return stack[--counter];
}

Ele  top(void)
{
    if(is_empty()) exit(1);
    return stack[counter-1];
}

bool is_full(void)
{
    if(counter == max_size) 
        return true;
    else   
        return false;
}

bool is_empty(void)
{    
    if(counter == 0)
        return true;
    else
        return false;
}


size_t size(void)
{
    return counter;
}


