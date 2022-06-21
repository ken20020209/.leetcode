/*
 * @lc app=leetcode id=1654 lang=c
 *
 * [1654] Minimum Jumps to Reach Home
 */
#include "header\leetcode.h"

// @lc code=start
//#define max(a,b) (((a)>(b))?(a):(b))
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
    if(dequeue_size(dequeue)==0)return 1;
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


//dir 1 is forward 0 is backward
int minimumJumps(int* forbidden, int forbiddenSize, int a, int b, int x)
{
    int map[10001]={0};
    int max_val=x;
    MyDequeue *dequeue = dequeue_create(10);
    for(int i=0; i< forbiddenSize; i++) 
    {
        map[forbidden[i]] =1;
        max_val=max(forbidden[i],max_val);
    }
    max_val+=a+b;
    int dir;
    int pos;
    dequeue_push_back(dequeue,0);//push pos;
    dequeue_push_back(dequeue,1);//push dir;
    int step=0;
    while (!dequeue_is_empty(dequeue))
    {
        
        int size= dequeue_size(dequeue);

        while (size>0 )
        {
            size-=2;
            pos=dequeue_pop_front(dequeue);
            dir=dequeue_pop_front(dequeue);
            if(pos==x)return step;
            if(map[pos]==1)continue;
            map[pos]=1;
            if(dir!=0&&pos>b)
            {
                dequeue_push_back(dequeue,pos-b);
                dequeue_push_back(dequeue,0);
            }
            if(pos<max_val)
            {
                dequeue_push_back(dequeue,pos+a);
                dequeue_push_back(dequeue,1);
            }
            
        }

        step++;
    }
    
    return -1;
}
// @lc code=end
int main()
{
    int arr[]={162,118,178,152,167,100,40,74,199,186,26,73,200,127,30,124,193,84,184,36,103,149,153,9,54,154,133,95,45,198,79,157,64,122,59,71,48,177,82,35,14,176,16,108,111,6,168,31,134,164,136,72,98};
    int a=29;
    int b=98;
    int c=80;
    printf("\n%d\n",minimumJumps(arr,53,a,b,c));
    return 0;
}