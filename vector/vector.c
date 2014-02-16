/**
 * @file vector.c
 * @brief 使用动态数组实现顺序表
 * @author Jack Jin - gjinjian@gmail.com
 * @version v0.1
 * @date 2014-01-19
 */

#include "vector.h"
#include <stdio.h>
#include <malloc.h>
#include <memory.h>
#include <assert.h>


/**
 * @brief 动态数组初始大小及动态扩展的因数
 *
 * @return 
 */
#define INIT_SIZE 10


/**
 * @brief 
 *      创建vector及动态数组
 * @return PVector类型
 */
PVector create(void)
{
    PVector pv = (PVector)malloc(sizeof(Vector));
    assert(pv != NULL);

    pv->array = calloc(INIT_SIZE, sizeof(Ele));
    assert(pv != NULL);

    pv->counter = 0;
    pv->max = INIT_SIZE;
    return pv;
}


/**
 * @brief 
 *      销毁vector及动态数组
 * @param PVector
 */
void    destory(PVector pv)
{
    assert(pv != NULL);
    free(pv->array);
    free(pv);

    pv = NULL;
}


/**
 * @brief   扩容处理 
 *      动态数组空间不足时，动态扩展处理函数，默认扩容大小为INIT_SIZE
 * @param PVector
 */
static  void enlarge(PVector pv)
{
    assert(pv != NULL);

    if(pv->counter >= pv->max){
        PEle new_array = (PEle)calloc(pv->max + INIT_SIZE, sizeof(Ele));
        assert(new_array != NULL);
        memcpy(new_array, pv->array, pv->max*sizeof(Ele));
        free(pv->array);
        pv->array = new_array;
        pv->max  += INIT_SIZE;
    }
}


/**
 * @brief 
 *      在动态数组头插入元素
 * @param PVector
 * @param PEle
 *
 * @return 成功返回1,失败返回0
 */
int     push_front(PVector pv, PEle pe)
{
    return insert(pv, 0, pe);

#if 0
    if(pv == NULL || pe == NULL)
        return 0;
    enlarge(pv);

    for(size_t i = pv->counter; i > 0; i--)
        pv->array[i] = pv->array[i-1];
    //memcpy(pv->array+1, pv->array, pv->counter);
    
    pv->array[0] = *pe;
    pv->counter++;
    return 1;
#endif
}


/**
 * @brief 
 *      在动态数组尾插入元素
 * @param PVector
 * @param PEle
 *
 * @return 成功返回1，失败返回0
 */
int     push_back(PVector pv, PEle pe)
{
    return insert(pv, pv->counter, pe);

#if 0
     if(pv == NULL || pe == NULL)
         return 0;
     enlarge(pv);
     pv->array[pv->counter++] = *pe;
     //*(pv->array+pv->counter) = *pe;
     //pv->counter++;
     return 1;
#endif
}


/**
 * @brief 
 *      在动态数组【头——尾】间插入元素
 * @param PVector
 * @param index
 * @param PEle
 * @return 成功返回1，失败返回0
 */
int     insert(PVector pv, size_t index, PEle pe)
{
    if(pv == NULL || pe == NULL || index > pv->counter)
        return 0;
    enlarge(pv);

#if 0
    for(size_t i = pv->counter; i > index; i--)
        pv->array[i] = pv->array[i-1];
    pv->array[i] = *pe;
    pv->counter++;
#endif
    memcpy(pv->array+index+1 ,pv->array+index, (pv->counter-index)*sizeof(Ele));
    pv->array[index] = *pe;
    pv->counter++;
    return 1;
}


/**
 * @brief 
 *  移除第0个元素
 * @param PVector
 *
 * @return 成功返回1，失败返回0
 */
int     remove_front(PVector pv)
{
    return mremove(pv, 0);
}


/**
 * @brief 
 *  移除最后一个元素
 * @param PVector
 *
 * @return 成功返回1，失败返回0
 */
int     remove_back(PVector pv)
{
    return mremove(pv, pv->counter-1);
}


/**
 * @brief 
 *      移除动态数组index位置的元素
 * @param PVector
 * @param index [0, counter -1]
 *      
 * @return 成功返回1，失败返回0
 */
int     mremove(PVector pv, size_t index)
{
    if(pv == NULL || index > pv->counter-1)
        return 0;
    //memcpy(pv->array+index, pv->array+index+1, pv->counter-index);    //error
    int i = index;
    for(; i < pv->counter-1; i++)
        pv->array[i] = pv->array[i+1];
    //*(pv->array+pv->counter) = 0;
    //pv->counter--;
    //*(pv->array+pv->counter--) = 0;   //error
    memset(pv->array+pv->counter--, 0, sizeof(Ele));   //error
    return 1;
}


/**
 * @brief 
 *      将PVector的最后一个元素值设置为*pe
 * @param PVector
 * @param PEle
 * @return 成功返回1，失败返回0
 */
int     set_front(PVector pv, PEle pe)
{
    return set(pv, 0, pe);
}


/**
 * @brief 
 *      将PVector的最后一个元素值设置为*pe
 * @param PVector
 * @param PEle
 *
 * @return 成功返回1，失败返回0
 */
int     set_back(PVector pv, PEle pe)
{
    return set(pv, pv->counter-1, pe);
}


/**
 * @brief 
 *      将PVector的第index元素值设置为*pe
 * @param PVector
 * @param index
 * @param PEle
 *
 * @return 成功返回1，失败返回0
 */
int     set(PVector pv, size_t index, PEle pe)
{
    if(pv == NULL || pe == NULL || index > pv->counter)
        return 0;
    pv->array[index] = *pe;
    //memcpy(pv->array+index, pe, sizeof(*pe));
    return 1;
}


    

/**
 * @brief 
 *  获取第一个元素的值
 * @param PVector
 *
 * @return 成功返回PEle, 失败返回NULL
 */
PEle    get_front(PVector pv)
{
    return get(pv, 0);
}



/**
 * @brief 
 *  获取最后一个元素的值
 * @param PVector
 *
 * @return 成功返回PEle, 失败返回NULL
 */
PEle    get_back(PVector pv)
{
    return get(pv, pv->counter-1);
}


/**
 * @brief 
 *  获取PVector第index元素值
 * @param PVector
 * @param index
 *
 * @return 成功返回PEle, 失败返回NULL
 */
PEle    get(PVector pv, size_t index)
{   
    if(pv == NULL || index > pv->counter)
        return NULL;
    return pv->array+index;
}


/**
 * @brief 
 *  获取PVector counter值
 * @param PVector
 *
 * @return 失败返回-1
 */
size_t  size(PVector pv)
{
    if(pv == NULL)
        return -1;

    return pv->counter;
}

//  需要根据Ele 具体类型重新实现
int     show(PVector pv)
{
    if(pv == NULL)
        return 0;
    printf("---------------------\n");
    printf("Index   Ele  Counter:%d Max:%d \n", pv->counter, pv->max);
    int i = 0;
    for(i = 0; i < pv->counter; i++)
        printf("%-7d %-4d \n", i, *(pv->array+i));
}

