/**
 * @file stack_mem.c
 * @brief 堆栈实现文件
 *      使用动态内存分配实现堆栈, 保证元素的唯一性
 *      前提：假定元素值的范围是0-max_size-1
 * @author Jack Jin - gjinjian@gmail.com
 * @version v0.1
 * @date 2014-03-04
 */
#include "stack.h"
#include <stdlib.h>

static PEle     stack, index;
static size_t   counter;
static size_t   max_size;


/**
 * @brief 
 *  初始化stack 
 * @param max  分配堆栈内存大小
 */
void init(size_t max)
{
    max_size = max;
    stack = (PEle)malloc(max*sizeof(Ele));
    index = (PEle)malloc(max*sizeof(Ele));
    int i;
    for(i=0; i<max; i++)
        index[i]=0;

    counter = 0;
}

static bool is_exist(Ele ele)
{
    if(index[ele] == 1)
        return true;
    else
        return false;
}

/**
 * @brief 
 *  压栈,counter+1
 * @param Ele
 *  压入的元素,  注意元素的范围是“0-max_size-1”
 * @return 成功1，失败0
 */
int  push(Ele ele)
{
    if(is_exist(ele) || is_full() )   return 0;
    stack[counter++] = ele;
    index[ele] = 1;             //标记元素存在
    printf("sizeof[index]=%d\n", sizeof(&index[0]));

    return 1;
}

/**
 * @brief 
 *  弹栈counter-1
 * @return 栈顶元素
 */
Ele  pop(void)
{
    if(is_empty())  exit(1);
    counter--;
    index[stack[counter]] = 0;  // 清除元素存在标志
    return stack[counter];
}

/**
 * @brief 
 *  获取首元素，counter不变
 * @return 首元素
 */
Ele  top(void)
{
    if(is_empty()) exit(1);
    return stack[counter-1];
}

/**
 * @brief 
 *  判断是否满
 * @return 满为真
 */
bool is_full(void)
{
    if(counter == max_size) 
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


