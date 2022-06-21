/*
 * @lc app=leetcode id=1306 lang=c
 *
 * [1306] Jump Game III
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
    return dequeue->back-dequeue->front;
}
int dequeue_is_empty(MyDequeue *dequeue)
{
    if(dequeue_size(dequeue)==-1)return 1;
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

bool canReach(int* arr, int arrSize, int start)
{
    MyDequeue* queue= dequeue_create(1000);
    int *visited=(int*)calloc(arrSize, sizeof(int));
    int pos;

    dequeue_push_back(queue,start);
    
    while (!dequeue_is_empty(queue))
    {
        int size= dequeue_size(queue);
 
        while (size>=0)
        {
            pos=dequeue_pop_front(queue);
            if(visited[pos]==1)
            {
                size--;
                continue;
            }
            visited[pos]=1;
            if(arr[pos]==0)
            {
                free(visited);
                dequeue_free(queue);
                return true;
            }
            if(pos-arr[pos]>=0)dequeue_push_back(queue,pos-arr[pos]);
            if(arr[pos]+pos<arrSize)dequeue_push_back(queue,arr[pos]+pos);
            size--;
        }
    }
    free(visited);
    dequeue_free(queue);
    return false;
}
// @lc code=end
int main()
{
    int a[]={4,2,3,0,3,1,2};
    printf("%d",canReach(a,7,5));
    return 0;
}
