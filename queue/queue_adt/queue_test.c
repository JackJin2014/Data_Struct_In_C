#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define M 10

int main(int argc, char *argv[])
{
    int i, j, N=atoi(argv[1]);
    PQueue queues[M];
    
    srand(time(NULL));
    for(i = 0; i < M; i++)
        queues[i] = init(N);    //N 没用

    for(j = 0; j < N; j++)
       enqueue(queues[rand() % M], j);

    for(i = 0; i < M; i++, printf("\n"))
        for(j = 0; !is_empty(queues[i]); j++)
            printf("%3d ", dequeue(queues[i]));

    return 0;
}
