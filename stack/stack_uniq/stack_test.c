//前提：假定元素值的范围是0-max_size-1

#include "stack.h"
#include <stdio.h>

// max=30   push(40)  index[40]能不能成立?

int main(void)
{
    init(30);

    int i = 0;
    for(i; i < 25; i++){
       if( push(i))
           printf("push sucess!\n");
       else
           printf("push fail!\n");
    }
    printf("top() = %d. size() = %d\n", top(), size());

    //if( push(40))         //OK ? 嗯 C中程序员负责 数组边界的检查 
    if( push(20))
        printf("push sucess!\n");
    else
        printf("push fail!\n");

    printf("pop ele = %d\n", pop());

#if 0
    Ele ele;
    if(ele = pop())
        printf("pop sucess! ele = %d\n", ele);
    else
        printf("pop fail!\n");

    printf("top() = %d. size() = %d\n", top(), size());
#endif

    return 0;
}

