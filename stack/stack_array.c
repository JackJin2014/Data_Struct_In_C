/**
 * @file stack.h
 * @brief 使用一维数组实现堆栈
 *      模块的接口设计：实现的时候不要打印，而要返回结果
 * @author Jack Jin - gjinjian@gmail.com
 * @version v0.1
 * @date 2014-01-22
 */
#include "stack.h"
#include <stdlib.h>

static Ele      stack[MAX_SIZE];
static size_t   counter;


void init(size_t max)
{
    counter = 0;
}

/**
 * @brief 
 *  压栈
 * @param Ele
 *
 * @return 
 */
int push(Ele ele)
{
    if(is_full())   return 0;
    stack[counter++] = ele;
    return 1;
}

Ele pop(void)
{
    if(is_empty())  exit(1);//C 语言出错处理
    return stack[--counter];
}

Ele  top(void)
{
    if(is_empty())  exit(1);
    return stack[counter-1];
}

bool is_full(void)
{
    if(counter == MAX_SIZE)
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


