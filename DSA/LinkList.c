#include <stdio.h>
#include <stdlib.h>
typedef struct LinkListNode
{
    void *val;
    struct LinkListNode *pre;
    struct LinkListNode *next;
} LinkListNode;
typedef struct LinkList
{
    int size;
    struct LinkListNode *head;
    struct LinkListNode *tail;
} LinkList;
LinkListNode *LinkListNode_New(void *val)
{
    LinkListNode *node = (LinkListNode *)malloc(sizeof(LinkListNode));
    node->pre = NULL;
    node->next = NULL;
    node->val = val;
    return node;
}
LinkList *LinkList_New()
{
    LinkList *list = (LinkList *)malloc(sizeof(LinkList));
    list->size = 0;
    list->head = NULL;
    return list;
}
void LinkList_push(LinkList *list, LinkListNode *node)
{
    if (list->size == 0)
        list->head = node;
    list->size++;
    list->tail->next = node;
    node->pre = list->tail;
    list->tail = node;
}
void LinkList_delete(LinkList *list, int index)
{
    if (index >= list->size)
    {
        printf("out of bound\n");
        return;
    }
    if (list->size == 1)
    {
        free(list->head);
        list->head = NULL;
        list->tail = NULL;
    }
    else if (index == list->size - 1)
    {
        list->tail->pre->next = NULL;
        free(list->tail);
        list->tail = NULL;
    }
    else
    {
        LinkListNode *node = list->head;
        for (int i = 0; i < index; i++)
        {
            node = node->next;
        }
        node->pre->next = node->next;
        node->next->pre = node->pre;
        free(node);
    }
}