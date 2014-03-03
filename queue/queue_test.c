#include "queue.h"
#include <stdio.h>

int main(void)
{
    int i = 0;
    for(i; i < 20; i++){
        enqueue(i);
    }
    printf("size = %d. \n", size());
    printf("dequeue = %d .\n", dequeue());
    printf("dequeue = %d .\n", dequeue());
    printf("dequeue = %d .\n", dequeue());
    printf("dequeue = %d .\n", dequeue());
    printf("cpqueue = %d .\n", cpqueue());
        
    return 0;
}
