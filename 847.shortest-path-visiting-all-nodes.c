/*
 * @lc app=leetcode id=847 lang=c
 *
 * [847] Shortest Path Visiting All Nodes
 */
#include "header\leetcode.h"

// @lc code=start

typedef struct
{
    int front;
    int back;
    int capacity;
    int *data;
}MyDequeue;
int dequeue_init(MyDequeue *dequeue)
{
    if(dequeue==NULL)return 0;
    dequeue->back=-1;
    dequeue->front=0;
    return 1;
}
void dequeue_realloc(MyDequeue *dequeue,int size)
{
    dequeue->capacity=size;
    dequeue->data =(int*)realloc(dequeue->data,size*sizeof(int));
}
void dequeue_free(MyDequeue *dequeue)
{
    free(dequeue->data);
    free(dequeue);
}
int dequeue_size(MyDequeue *dequeue)
{
    return dequeue->back-dequeue->front+1;
}
int dequeue_is_empty(MyDequeue *dequeue)
{
    if(dequeue_size(dequeue)==0)
    {
        dequeue_init(dequeue);
        return 1;
    }
    return 0;
}

int dequeue_push_back(MyDequeue *dequeue, int value)
{
    dequeue->back++;
    if (dequeue->back==dequeue->capacity)
    {
        dequeue_realloc(dequeue, (dequeue->capacity)*2);
    } 
    dequeue->data[dequeue->back] = value;
    return 1;
}
int dequeue_pop_front(MyDequeue *dequeue)
{
    if (dequeue_is_empty(dequeue))return -1;
    dequeue->front++;
    return dequeue->data[dequeue->front-1];
}

MyDequeue *dequeue_create(int size)
{ 
    MyDequeue *dequeue = (MyDequeue *)malloc(sizeof(MyDequeue));
    if (dequeue==NULL)return NULL;
    dequeue->capacity=size;
    dequeue->back=-1;
    dequeue->front=0;
    dequeue->data=(int *)malloc(sizeof(int) * dequeue->capacity);
    return dequeue;
}


int shortestPathLength(int** graph, int graphSize, int* graphColSize)
{
    MyDequeue* dequeue= dequeue_create(10);
    int ans=(1<<graphSize)-1;
    printf("ans:%d\n", ans);
    for (int i=0; i<graphSize; i++)
    {
        dequeue_push_back(dequeue,i);//node
        dequeue_push_back(dequeue,1<<i);//state
    }

    
    int step=0;
    int node;
    int state;
    int map[12][5000]={0};
    while (!dequeue_is_empty(dequeue))
    {
        int size= dequeue_size(dequeue);
        while (size>0 )
        {
            size-=(2);
            node=dequeue_pop_front(dequeue);
            state=dequeue_pop_front(dequeue);
            //printf("node:%d state:%d\n",node,state);
            if (state==ans)return step;
            if (map[node][state]==1)continue;
            map[node][state]=1;
            for (int i = 0; i < graphColSize[node]; i++)
            {
                int push=graph[node][i];
                //printf("    push:%d state:%d\n",push,state|(1<<push));
                dequeue_push_back(dequeue,push);
                dequeue_push_back(dequeue,state|(1<<push));
            }
            
            
            
        }
        printf("\n\n");
        step++;
    }
    return -1;
}
// @lc code=end

