/**
 * @file queue_test.c
 * @brief 队列接口测试文件
 * @author Jack Jin - gjinjian@gmail.com
 * @version v0.1
 * @date 2014-03-03
 */

#include "queue.h"
#include <stdio.h>

int main(void)
{
    init(12);

    int i = 0;
    for(i; i < 20; i++){
        enqueue(i);
    }
    printf("size = %d. \n", size());
    printf("dequeue = %d .\n", dequeue());
    printf("dequeue = %d .\n", dequeue());
    printf("dequeue = %d .\n", dequeue());
    printf("dequeue = %d .\n", dequeue());
    printf("dequeue = %d .\n", dequeue());
    printf("dequeue = %d .\n", dequeue());
    printf("dequeue = %d .\n", dequeue());
    printf("dequeue = %d .\n", dequeue());
    printf("dequeue = %d .\n", dequeue());
    printf("dequeue = %d .\n", dequeue());
    printf("dequeue = %d .\n", dequeue());
    printf("dequeue = %d .\n", dequeue());
    //printf("cpqueue = %d .\n", cpqueue());
        
    return 0;
}
