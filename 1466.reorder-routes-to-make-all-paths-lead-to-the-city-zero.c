/*
 * @lc app=leetcode id=1466 lang=c
 *
 * [1466] Reorder Routes to Make All Paths Lead to the City Zero
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
int dequeue_push_front(MyDequeue *dequeue, int value)
{
    dequeue->front--;
    if (dequeue->front==-1)
    {
        return 0;
    } 
    dequeue->data[dequeue->front] = value;
    return 1;
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
int dequeue_pop_back(MyDequeue *dequeue)
{
    if (dequeue_is_empty(dequeue))return -1;
    dequeue->back--;
    return dequeue->data[dequeue->back+1];
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
int dequeue_get_back(MyDequeue *dequeue)
{
    if (dequeue_is_empty(dequeue))return -1;
    return dequeue->data[dequeue->back];
}
int dequeue_get_front(MyDequeue *dequeue)
{
    if (dequeue_is_empty(dequeue))return -1;
    return dequeue->data[dequeue->front];
}

int minReorder(int n, int** connections, int connectionsSize, int* connectionsColSize)
{

    int visited[n];

    int res=0;
    MyDequeue **m=(MyDequeue **)malloc(n*sizeof(MyDequeue *));
    
    //int **m=(int **)malloc(n*sizeof(int*));
    memset(visited, 0, n*sizeof(int));

    for (int i = 0; i < n; i++)
    {
        m[i]=dequeue_create(10);
        //m[i]=(int*)malloc(n*sizeof(int));
        //memset(m[i],-1,n*sizeof(int));
    }

    for (int i = 0; i < connectionsSize; i++)
    {
        //m[connections[i][0]][connections[i][1]]=true;
        dequeue_push_back(m[connections[i][0]],connections[i][1]);
        dequeue_push_back(m[connections[i][0]],true);
        //m[connections[i][1]][connections[i][0]]=false;
        dequeue_push_back(m[connections[i][1]],connections[i][0]);
        dequeue_push_back(m[connections[i][1]],false);
    }
    //printf("%d\n",dequeue_size(m[0]));
    /*
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d  ",m[i][j]);
        }
        printf("\n");
        
    }
    */

    MyDequeue* dequeue= dequeue_create(10);
    int step=0;
    dequeue_push_back(dequeue,0);
    visited[0]=true;
    while(!dequeue_is_empty(dequeue))
    {
        int size= dequeue_size(dequeue);
        while (size>0 )
        {
            size--;
            int pop=dequeue_pop_front(dequeue);
            //printf("pop=%d\n", pop);
            while (!dequeue_is_empty(m[pop]))
            {
                int push=dequeue_pop_front(m[pop]);
                int bit=dequeue_pop_front(m[pop]);
                //printf(" push=%d bit=%d\n",push, bit);
                if (visited[push]==0)
                {
                    visited[push]=1;
                    if (bit==true)
                    {
                        res++;
                    }
                    dequeue_push_back(dequeue,push);
                }
                
            }
            
            /*
            for (int i = 0; i < n; i++)
            {
                if (m[pop][i]==true&&visited[i]==0)
                {
                        visited[pop]=1;
                        //printf("++ push:%d\n",i);
                        res++;
                        dequeue_push_back(dequeue,i);
                }
                else if (m[pop][i]==false&&visited[i]==0)
                {
                        visited[pop]=1;
                        //printf(" push:%d\n",i);
                        dequeue_push_back(dequeue,i);
                }   
            }
            */

        }
        //printf("\n");
        step++;
    }

    dequeue_free(dequeue);
    for (int i = 0; i < n; i++)
    {
        dequeue_free(m[i]);
    }
    free(m);
    return res;
}
// @lc code=end

