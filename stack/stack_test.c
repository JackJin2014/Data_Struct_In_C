#include "stack.h"
#include <stdio.h>


int main(void)
{
    init(50);

    int i = 0;
    for(i; i < 25; i++){
       if( push(i))
           printf("push sucess!\n");
       else
           printf("push fail!\n");
    }
    printf("top() = %d. size() = %d\n", top(), size());

    Ele ele;
    if(ele = pop())
        printf("pop sucess! ele = %d\n", ele);
    else
        printf("pop fail!\n");

    printf("top() = %d. size() = %d\n", top(), size());
    return 0;
}

