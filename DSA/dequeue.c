#include "../header/leetcode.h"
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

//1test
int main()
{
     MyDequeue *dequeue =  dequeue_create(10);
     int temp=dequeue->capacity;
     for (int i = 0; i < 99; i++)
     {
        dequeue_push_back(dequeue,i);
        
     }
     for (int i = 0; i < 99; i++)
     {
        printf("%d\n",dequeue_pop_front(dequeue));
        if(i==40)dequeue_init(dequeue);
     }
     return 0;
     
}