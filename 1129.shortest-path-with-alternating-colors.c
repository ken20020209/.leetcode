/*
 * @lc app=leetcode id=1129 lang=c
 *
 * [1129] Shortest Path with Alternating Colors
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

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shortestAlternatingPaths(int n, int** redEdges, int redEdgesSize, int* redEdgesColSize, int** blueEdges, int blueEdgesSize, int* blueEdgesColSize, int* returnSize){
    *returnSize=n;
    int *res=(int*)malloc(n*sizeof(int));
    memset(res,-1,n*sizeof(int));
    int rvitised[100]={0};
    int bvitised[100]={0};
    //create graph use hash table save it
    int red[100][100];
    int blue[100][100];
    for(int i=0; i<100; i++)
    {
        red[i][0]=0;
        blue[i][0]=0;
    }
    for(int i=0; i<redEdgesSize; i++)
    {
        int top=++red[redEdges[i][0]][0];
        red[redEdges[i][0]][top]=redEdges[i][1];   
    }
    for(int i=0; i<blueEdgesSize; i++)
    {
        int top=++blue[blueEdges[i][0]][0];
        blue[blueEdges[i][0]][top]=blueEdges[i][1];   
    }

    

    MyDequeue* dequeue= dequeue_create(10);
    //push {node,color} push{0,0},{0,1}
    dequeue_push_back(dequeue,0);
    dequeue_push_back(dequeue,0);
    dequeue_push_back(dequeue,0);
    dequeue_push_back(dequeue,1);
    int step=0;
    while (!dequeue_is_empty(dequeue))
    {
        int size= dequeue_size(dequeue);
        while (size>0)
        {
            //printf("size=%d\n",size);
            size-=2;
            int node = dequeue_pop_front(dequeue);
            int color = dequeue_pop_front(dequeue);
            //printf("node=%d color=%d\n",node,color);
            if(res[node]==-1)
                res[node]=step;
            if (color==1)
            {
                //printf("%d\n",red[0][1]);
                for (int i=1; i <= red[node][0]; i++)
                {
                    
                    int nextnode=red[node][i];
                    int nextcolor=0;
                    //printf(" nextnode=%d nextcolor=%d\n",nextnode,nextcolor);
                    if(rvitised[nextnode]==0)
                    {
                        rvitised[nextnode]=1;
                        dequeue_push_back(dequeue,nextnode);
                        dequeue_push_back(dequeue,nextcolor);
                    }
                    
                }
                
            }
            else
            {
                //printf("%d\n",blue[0][0]);
                for (int i=1; i <= blue[node][0]; i++)
                {
                    int nextnode=blue[node][i];
                    int nextcolor=1;
                    //printf(" nextnode=%d nextcolor=%d\n",nextnode,nextcolor);
                    if(bvitised[nextnode]==0)
                    {
                        bvitised[nextnode]=1;
                        dequeue_push_back(dequeue,nextnode);
                        dequeue_push_back(dequeue,nextcolor);
                    }
                    
                }
            }
            
        }
        printf("\n");
        step++;
    }

    res[0]=0;
    return res;
}
// @lc code=end
#include <stdio.h>
int main(int argc, char** argv)
{
    printf("hello world\n");
    return 0;
}
