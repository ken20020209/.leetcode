#include "../header/dequeue.h"
void bfs()
{
    MyDequeue* dequeue= dequeue_create(10);
    int visited[1000];
    int step=0;
    int pop;
    while (!dequeue_is_empty(dequeue))
    {
        int size= dequeue_size(dequeue);
        while (size>0 )
        {
            visited[0]=1;//set visited
            pop=dequeue_pop_front(dequeue);
        }
        step++;
    }
    
}