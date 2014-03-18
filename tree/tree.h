/**
 * @file tree.h
 * @brief 排序二叉树接口
 * @author Jack Jin - gjinjian@gmail.com
 * @version v0.1
 * @date 2014-03-10
 */

#ifndef __TREE_H__
#define __TREE_H__

#include "element.h"

typedef struct node     Node;
typedef struct node*    PNode;

struct node {
    Ele     ele;
    PNode   left;
    PNode   right;
}node;

typedef struct tree{
    PNode    root;
}Tree, *PTree;

extern PTree    create_tree(PEle pe);
extern void     destroy_tree(PTree pt);

extern int      add_element(PTree pt, PEle pe);
extern int      remove_element(PTree pt, PEle pe);

extern PEle     get_element(PTree pt, PEle pe);
extern PNode    find_min(PNode);
extern PNode    find_max(PNode);

extern void     pre_traverse(PTree);
extern void     mid_traverse(PTree);
extern void     post_taverse(PTree);

extern size_t   size_tree(PTree pt);

//extern int      set_element(PTree pt, PEle pe);

#endif
