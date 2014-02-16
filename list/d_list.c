/**
 * @file d_list.c
 * @brief 双链表实现文件
 *      引用节点前驱、后驱注意：哑节点、尾节点特殊情况
 *      index 范围：0——size-1
 *      递归、迭代的使用
 * @author Jack Jin - gjinjian@gmail.com
 * @version v0.1
 * @date 2014-01-22
 */

#include "d_list.h"
#include <malloc.h>
#include <assert.h>
#include <stdio.h>


/**
 * @brief 
 *  创建链表
 * @return 链表指针,失败返回NULL
 */
PList create(void)
{
    PList pl = (PList)malloc(sizeof(List));
    if(pl == NULL)
        return NULL;
    pl->head.prev = pl->head.next = NULL;

    return pl;
}


/**
 * @brief 
 *  释放pn节点—最后节点 之间的空间
 * @param PNode
 */
static void destory_node(PNode pn)
{
    if(pn == NULL)
        return;
    destory_node(pn->next);
    free(pn);
}


/**
 * @brief 
 *  释放链表pl、哑节点
 * @param PList
 */
void    destory(PList pl)
{
    assert(pl != NULL);
    destory_node(pl->head.next);
    free(pl);
    pl = NULL;
}



/**
 * @brief 
 *  在链表pl的头部插入元素pe
 * @param PList
 * @param PEle
 *
 * @return 成功1，失败0
 */
int     push_front(PList pl, PEle pe)
{
    if(pl == NULL || pe == NULL)
        return 0;

    PNode pn = (PNode)malloc(sizeof(Node));
    if(pn == NULL)
        return 0;
    pn->prev = pn->next = NULL;
    // head ——>[] ——> 1st 
    // []
    pn->prev = &pl->head;
    pn->ele = *pe;
    pn->next = pl->head.next;
    // 1st
    if(pn->next != NULL)
        pn->next->prev = pn;
    // head
    pl->head.next = pn;
    return 1;
}


/**
 * @brief 
 *  获取链表的尾节点
 * @param PNode
 * @return 
 *  返回尾节点指针
 */
static PNode tail(PNode pn)
{
    //伪递归
    if(pn->next == NULL) return pn;
    return tail(pn->next);
#if 0
    while(pn->next != NULL)
        pn = pn->next;
    return pb;
#endif
}


/**
 * @brief 
 *  在链表pl尾部插入元素pe
 * @param PList
 * @param PEle
 * @return 成功1，失败0
 */
int     push_back(PList pl, PEle pe)
{
    if(pl == NULL || pe == NULL)
        return 0;

    //PNode end = tail(pl->head.next);
    PNode end = tail(&pl->head);     //!null 

    PNode pn = (PNode)malloc(sizeof(Node));
    if(pn == NULL)  return 0;
    pn->prev = end;
    pn->ele  = *pe;
    pn->next = NULL;

    end->next = pn;

    return 1;
}



/**
 * @brief 
 *   head   index-1   index     
 *   可以获取返回尾节点
 * @param PNode 必须指定为head
 * @param index
 *
 * @return  
 */
//extern PNode get_prev(PNode pn, size_t index)
static PNode get_prev(PNode pn, size_t index)
{
    if(pn == NULL) return NULL;
    if(index == 0) return pn;
    //return get_prev(pn->next, index--);
    return get_prev(pn->next, index-1);
#if 0
    while(pn != NULL && index != 0){
        pn = pn->next;
        index--;
    }
    return pn;
#endif
}

/**
 * @brief 
 *   在链表pl的index位置插入pe元素
 *两种办法:1:找index节点的前驱: 单链表、双链表同样适用
           2、找index节点: 仅适于双链表
 *
 *   head  index[0——(size-1)] 
 * @param PList
 * @param index
 * @param PEle
 * @return 成功1，失败0
 */
int     insert(PList pl, size_t index, PEle pe)
{
    if(pl == NULL || pe == NULL || index > size(pl))
        return 0;
#if 0
    PNode pre = get_prev(pl->head, index);
    if(pre == NULL) return 0;

    PNode pn = (PNode)malloc(sizeof(Node));
    if(pn == NULL)  return 0;
    pn->ele = *pe;
    pn->prev = pre;
    pn->next = pre->next;

    if(pre->next != NULL){
        pre->next = pn;
        pre->next->prev = pn;
    }

    return 1;

#endif
    //方法2 找自己
    PNode pn = get(pl, index);
    if(pn == NULL)
        return 0;
    
    PNode node = (PNode)malloc(sizeof(Node));
    if(node == NULL)
        return 0;

    node->prev = pn->prev;
    node->ele  = *pe;
    node->next = pn;

    if(pn->prev != NULL)
        pn->prev->next = node;

    pn->prev = node;
    return 1;
}



/**
 * @brief 
 *  删除pl的头节点
 * @param PList
 *
 * @return 成功1，失败0
 */
int     remove_front(PList pl)
{
    return mremove(pl, 0);
}



/**
 * @brief 
 *  删除尾节点
 * @param PList
 *
 * @return 成功1，失败0
 */
int     remove_back(PList pl)
{
    return mremove(pl, size(pl) -1);
}


/**
 * @brief 
 *  删除index位置的节点
 * @param PList
 * @param index
 *
 * @return 成功1，失败0
 */
int     mremove(PList pl, size_t index)
{
    if(pl == NULL || index > size(pl))
        return 0;
#if 0
    PNode pn = get_prev(pl->head);
    if(pn == NULL || pn->next == NULL)   return 0;

    PNode tmp = pn->next;

    pn->next = tmp->next;
    if(tmp->next == NULL)  return 0;
    tmp->next->prev = pn;

    free(tmp);
    tmp = NULL;
#endif

    // find
    PNode pn = get(pl, index);
    if(pn == NULL)  return 0;
    // swap
    if(pn->next != NULL){
        pn->prev->next = pn->next;
        pn->next->prev = pn->prev;
    }else{
        pn->prev->next = NULL;
    }
    // free
    free(pn);
    pn = NULL;
    return 1;
}


/**
 * @brief 
 *  设置链表头节点元素
 * @param PList
 * @param PEle
 *
 * @return 成功1，失败0
 */
int     set_front(PList pl, PEle pe)
{
    return set(pl, 0, pe);
}


/**
 * @brief 
 *  设置链表尾节点元素
 * @param PList
 * @param PEle
 *
 * @return 成功1，失败0
 */
int     set_back(PList pl, PEle pe)
{
    return set(pl, size(pl) -1, pe);
}


/**
 * @brief 
 *  设置链表index位置元素
 * @param PList
 * @param index
 * @param PEle
 *
 * @return 成功1，失败0
 */
int     set(PList pl, size_t index, PEle pe)
{
    if(pl == NULL || pe == NULL || index > size(pl))
        return 0;
    PNode pn = get(pl, index);
    if(pn == NULL)  return 0;
    pn->ele = *pe;
    return 1;
}



//以下接口也可以设计成通过指针回传结果

/**
 * @brief 
 *  获取链表头节点元素
 * @param PList
 *
 * @return 成功1，失败0
 */
PNode   get_front(PList pl)
{
    return get(pl, 0);
}


/**
 * @brief 
 *  获取链表尾节点元素  
 * @param PList
 *
 * @return 成功1，失败0
 */
PNode   get_back(PList pl)
{
    return get(pl, size(pl)-1);
}


/**
 * @brief 
 *  获取链表index位置元素
 * @param PList
 * @param index
 *
 * @return 成功1，失败0
 */
PNode   get(PList pl, size_t index)
{
    if(pl == NULL || index > size(pl))
        return NULL;
    PNode pn = pl->head.next;
    while(index-- > 0)
        pn = pn->next;

    return pn;
}


/**
 * @brief 
 *  获取链表节点的数量
 * @param PList
 *
 * @return 成功1，失败0
 */
size_t  size(PList pl)
{
    if(pl == NULL)
        return 0;

    int cnt = 0;
    PNode pn = pl->head.next;
    while(pn != NULL){
        pn = pn->next;
        cnt++;
    }
    return cnt;
}
    

/**
 * @brief 
 *  打印链表
 * @param PList
 *
 * @return 成功1，失败0
 */
int     show(PList pl)
{
    if(pl == NULL) return 0;
    printf("Index\tEle Size:%d \n", size(pl));
    int i = 0;
    PNode pn = pl->head.next;

    while(i != size(pl)){
        printf("%-4d %-4d\n", i++, pn->ele);
        pn = pn->next;
    }
    return 1;
}


