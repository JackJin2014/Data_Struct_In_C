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



/**
 * @brief 
 *  初始化stack 
 * @param max 没有用，为了与其他实现保持接口的一致
 */
void init(size_t max)
{
    counter = 0;
}

/**
 * @brief 
 *  压栈,counter+1
 * @param Ele
 *  压入的元素
 * @return 成功1，失败0
 */
int push(Ele ele)
{
    if(is_full())   return 0;
    stack[counter++] = ele;
    return 1;
}


/**
 * @brief 
 *  弹栈counter-1
 * @return 栈顶元素
 */
Ele pop(void)
{
    if(is_empty())  exit(1);//C 语言出错处理
    return stack[--counter];
}


/**
 * @brief 
 *  获取首元素，counter不变
 * @return 首元素
 */
Ele  top(void)
{
    if(is_empty())  exit(1);
    return stack[counter-1];
}


/**
 * @brief 
 *  判断是否满
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
 *  判断是否空
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
 *  堆栈的大小
 * @return 堆栈的大小
 */
size_t size(void)
{
    return counter;
}


