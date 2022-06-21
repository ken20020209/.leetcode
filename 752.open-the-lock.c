/*
 * @lc app=leetcode id=752 lang=c
 *
 * [752] Open the Lock
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

int key(char *s)
{
    int res=0;
    for (int i = 0; i < strlen(s); i++)
    {
        res=res*10+(s[i]-'0');
    }
    return res;
}
int openLock(char ** deadends, int deadendsSize, char * target)
{
    int map[10000] = {0};
    int find=key(target);
    for (int i = 0; i < deadendsSize; i++)
    {
        //printf("%d ", key(deadends[i]));
        map[key(deadends[i])]=1;
    }

    MyDequeue* dequeue= dequeue_create(10);
    dequeue_push_back(dequeue,0000);
    int step=0;
    int pop;

    //bfs
    while (!dequeue_is_empty(dequeue))
    {

        
        int size= dequeue_size(dequeue);
        while (size>0 )
        {
            
            size-=1;
            pop=dequeue_pop_front(dequeue);
            if(map[pop]==1)continue;
            
            map[pop]=1;
            printf("pop %d \n",pop);
            if(pop==find)return step;
            for (int i = 0; i < strlen(*deadends); i++)
            {
                int newpush;
                int popbit=pop/pow(10,i);
                popbit%=10;
                //down
                if (popbit==0)
                {
                    newpush=pop+pow(10,i)*9;
                }
                else
                {
                    newpush=pop-pow(10,i);
                }
                if(map[newpush]==0)
                {
                    dequeue_push_back(dequeue,newpush);
                }
                //up
                if (popbit==9)
                {
                    newpush=pop-pow(10,i)*9;
                }
                else
                {
                    newpush=pop+pow(10,i);
                }
                if(map[newpush]==0)
                {
                    dequeue_push_back(dequeue,newpush);
                }
            }
            
        }
        printf("\n");
        step++;
    }
    return -1;
}

// @lc code=end
int main()
{
    char *s[]={"0000"};
    int size=1;
    char target[]="8888";
    printf("step %d\n",openLock(s,size,target));
    return 0;
}
