#include "stack.h"

#include <stdio.h>

int main(void)
{
    int i = 0;
    for(i; i < 25; i++){
       if( push(i))
           printf("push sucess!\n");
       else
           printf("push fail!\n");
    }
    printf("top() = %d. size() = %d\n", top(), size());

    if(pop())
        printf("pop sucess!\n");
    else
        printf("pop fail!\n");

    printf("top() = %d. size() = %d\n", top(), size());

    return 0;
}

