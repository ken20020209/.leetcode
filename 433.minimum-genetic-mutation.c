/*
 * @lc app=leetcode id=433 lang=c
 *
 * [433] Minimum Genetic Mutation
 */
#include "header\leetcode.h"

// @lc code=start

//bug cant use same key at dict , the node link list have bug
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

typedef struct node
{
    char *s;
    struct node *next;
}node;

typedef struct 
{
    node*node[1000000];
}dict;

dict *dict_create(void)
{
    dict *d=calloc(1, sizeof(dict));
    return d;
}
node* node_create(int size)
{
    node *n=calloc(1, sizeof(node));
    n->s=malloc(size+1);
    return n;
}
int nodekey(char *arr)
{
    long int ret=0;
    int len=strlen(arr);
    for(int i=0; i<len; i++)
    {
        ret=(31)*ret+arr[i];
    }
    ret%=1000000;
    return ret>0?ret:-ret;

}
int dict_insert(dict *d,char *s)
{
    int key=nodekey(s);
    //printf("key=%d\n",key);
    if (d->node[key]==NULL)
    {
        d->node[key]=node_create(strlen(s)+1);
        memcpy(d->node[key]->s,s,strlen(s)+1);
    }
    else
    {
        node* temp=d->node[key];
        while (temp->next!=NULL)
        {
            if(strcmp(temp->s,s)==0)
            {
                return 0;
            }
            else
            {
                temp=temp->next;
            }
        }
        if(strcmp(temp->s,s)==0)return 0;
        temp->next=node_create(strlen(s)+1);
        memcpy(temp->s,s,strlen(s)+1);
    }
    return 1;   
}
int dict_check(dict *d,char *s)
{
    int key=nodekey(s);

    if(d->node[key]==NULL)return 0;

    node *temp=d->node[key];

    while (temp!=NULL)
    {
        if(strcmp(temp->s,s)==0)return 1;
        temp=temp->next;
    }
    return 0;
}
int ladderLength(char * beginWord, char * endWord, char ** wordList, int wordListSize)
{
    int len=strlen(beginWord);
    dict *d=dict_create();
    for (int i=0;i<wordListSize;i++)
    {
        dict_insert(d,wordList[i]);
    }
    MyDequeue* dequeue= dequeue_create(10);
    for (int i=0;i<=len;i++)
    {
        dequeue_push_back(dequeue,beginWord[i]);
    }
    int step=0;
    char pop[11]={0};
    while (!dequeue_is_empty(dequeue))
    {
        printf("step=%d\n",step);
        int size= dequeue_size(dequeue);
        printf("size=%d\n",size);
        while (size>0 )
        {
            for (int i=0;i<=len;i++)
            {
                pop[i]=dequeue_pop_front(dequeue);
            }
            if(strcmp(pop,endWord)==0)return step;
            for (int j = 0; j < len; j++)
            {         
                char temp=pop[j];
                for(int i='A';i<='T';i++)
                {
                    
                    pop[j]=i;
                    if(dict_check(d,pop)==1)
                    {
                        int key =nodekey(pop);
                        if (d->node[key]->next==NULL)
                        {
                            d->node[key]=NULL;
                        }
                        else
                        {
                            printf("2\n");
                            d->node[key]=d->node[key]->next;
                        }
                        
                        //printf("%s\n",pop);
                        for (int i=0;i<=len;i++)
                        {
                            dequeue_push_back(dequeue,pop[i]);
                        }
                    }
                }
                pop[j]=temp;
            }

            size=size-len-1;
        }
        step++;
    }
    return -1;
}
int minMutation(char * start, char * end, char ** bank, int bankSize){
    return ladderLength(start,end,bank,bankSize);
}
// @lc code=end

