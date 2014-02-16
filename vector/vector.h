#ifndef _VECTOR_H_
#define _VECTOR_H_

#include "element.h"

typedef unsigned int size_t;

typedef struct vector{
    PEle    array;
    size_t  counter;
    size_t  max;
}Vector, *PVector;

extern  PVector create(void);
extern  void    destory(PVector);

extern  int     push_front(PVector, PEle);
extern  int     push_back(PVector, PEle);
extern  int     insert(PVector, size_t index, PEle);

extern  int     remove_front(PVector);
extern  int     remove_back(PVector);
extern  int     mremove(PVector, size_t index);

extern  int     set_front(PVector, PEle);
extern  int     set_back(PVector, PEle);
extern  int     set(PVector, size_t index, PEle);

//以下接口也可以设计成通过指针回传结果
extern  PEle    get_front(PVector);
extern  PEle    get_back(PVector);
extern  PEle    get(PVector, size_t index);

extern  size_t  size(PVector);
extern  int     show(PVector);

#endif
