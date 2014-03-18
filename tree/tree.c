/**
 * @file tree.c
 * @brief 排序二叉树接口实现文件
 * @author Jack Jin - gjinjian@gmail.com
 * @version v0.1
 * @date 2014-03-10
 */
#include "tree.h"
#include <malloc.h>
#include <assert.h>
#include <stdio.h>

PTree    create_tree(PEle pe)
{
    PNode root = (PNode)malloc(sizeof(Node));
    if(root == NULL)  return NULL;
    root->ele = *pe;
    root->left = NULL;
    root->right = NULL;

    PTree pt = (PTree)malloc(sizeof(Tree));
    if(pt == NULL) {
        free(root);
        return  NULL;
    }
    pt->root = root;
    return pt;
}



/**
 * @brief 
 *  递归销毁左树、右树
 * @param PNode
 */
static void destroy_node(PNode pn)
{
    if(pn == NULL)  return;
    destroy_node(pn->left);
    destroy_node(pn->right);
    free(pn);
}


/**
 * @brief 
 *
 * @param PTree
 */
void     destroy_tree(PTree pt)
{
    assert(pt != NULL);
    destroy_node(pt->root);
    free(pt);
}



/**
 * @brief 
 *  当pn为空，创建一个节点
 * @param PNode
 * @param PEle
 *
 * @return 
 */
static PNode add_node(PNode pn, PEle pe)
{
    //if(pe == NULL)   return NULL;
    PNode pnew = (PNode)malloc(sizeof(Node));
    if(pnew == NULL)  return NULL;
    pnew->ele = *pe;
    pnew->left = NULL;
    pnew->right = NULL;

    if(pn == NULL)
        return pnew;
    else if(*pe < pn->ele)
        //pn->left = pnew;
        pn->left = add_node(pn->left, pe);
    else if(*pe > pn->ele)
        //pn->right = pnew;
        pn->right = add_node(pn->right, pe);
    return pn;
}



/**
 * @brief 
 *
 * @param PTree
 * @param PEle
 *
 * @return 
 */
int      add_element(PTree pt, PEle pe)
{
    if(pt == NULL || pe == NULL)    return 0;
    pt->root = add_node(pt->root, pe);
    return 1;
}

/**
 * @brief 
 *
 * @param PNode
 * @param PEle
 *
 * @return 
 */
static PNode remove_node(PNode pn, PEle pe)
{
    if(pn == NULL)  return NULL;    //没找到时

    if(*pe < pn->ele)
        pn->left = remove_node(pn->left, pe);
    else if(*pe > pn->ele)
        pn->right = remove_node(pn->right, pe);
    else{
        if(pn->left && pn->right){
            PNode tmp = find_min(pn->right);
            pn->ele = tmp->ele;
            pn->right = remove_node(pn->right, &tmp->ele);
        }else{
            PNode tmp = NULL;
            if(pn->left){ 
                tmp = pn->left;
                free(pn);
            }else if(pn->right){
                tmp = pn->right;
                free(pn);
            }else{
                free(tmp);
                pn = NULL;
            }
            //return pn;
        }

    }
    return pn;
}


/**
 * @brief 
 *
 * @param PTree
 * @param PEle
 *
 * @return 
 */
int      remove_element(PTree pt, PEle pe)
{
    if(pt == NULL || pe == NULL) return 0;
    pt->root = remove_node(pt->root, pe);   //root 可能变
    return 1;
}




/**
 * @brief 
 *
 * @param PNode
 * @param PEle
 *
 * @return 
 */
static PNode get_node(PNode pn, PEle pe)
{
    if(pn == NULL)  return NULL;
    if(*pe == pn->ele)  
        return pn;
    else if(*pe < pn->ele)  
        return get_node(pn->left, pe);
    else 
        return get_node(pn->right, pe);
}

/**
 * @brief 
 *  查询元素
 * @param PTree
 * @param PEle
 *
 * @return 
 */
PEle     get_element(PTree pt, PEle pe)
{
    if(pt == NULL || pe == NULL)   return NULL;
    PNode res = get_node(pt->root, pe);
    if(res == NULL) 
        return NULL;
    else    
        return &res->ele;
}

PNode find_min(PNode pn)
{
    if(pn->left == NULL) return pn;
    return find_min(pn->left);
}

PNode    find_max(PNode pn)
{
    if(pn->right == NULL)  return pn;
    return find_max(pn->right);
}

void     pre_traverse(PTree pt)
{

}


static void mid_node(PNode pn)
{
    if(pn == NULL) return;
    mid_node(pn->left);
    printf("%d ", pn->ele);
    mid_node(pn->right);
}

void     mid_traverse(PTree pt)
{
    if(pt == NULL)  return;
    mid_node(pt->root);
}

void     post_taverse(PTree pt)
{

}




static size_t size_node(PNode pn)
{
    if(pn == NULL)  return 0;
    return 1+size_node(pn->left)+size_node(pn->right);
}

size_t   size_tree(PTree pt)
{
    assert(pt != NULL);
    return size_node(pt->root);
}


// int      set_element(PTree pt, PEle pe);

