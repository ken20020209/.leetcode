/*
 * @lc app=leetcode id=707 lang=c
 *
 * [707] Design Linked List
 */
#include "header\leetcode.h"

// @lc code=start
typedef struct Node
{
    int val;
    struct Node *next;
} Node;
typedef struct
{
    int length;
    Node *head;

} MyLinkedList;

MyLinkedList *myLinkedListCreate()
{
    MyLinkedList *obj = (MyLinkedList *)calloc(1, sizeof(MyLinkedList));
    return obj;
}
Node *myLinkListSerch(MyLinkedList *obj, int index)
{
    if (index >= obj->length || index < 0)
        return NULL;
    Node *node = obj->head;
    for (int i = 0; i < index; i++)
    {
        node = node->next;
    }
    return node;
}
int myLinkedListGet(MyLinkedList *obj, int index)
{
    // printf("GET\n");
    if (index >= obj->length)
        return -1;
    return myLinkListSerch(obj, index)->val;
}
void myLinkedListAddAtHead(MyLinkedList *obj, int val)
{
    // printf("AddAtHead\n");
    Node *node = (Node *)calloc(1, sizeof(Node));
    node->val = val;
    obj->length++;
    if (obj->head == NULL)
    {
        obj->head = node;
    }
    else
    {
        node->next = obj->head;
        obj->head = node;
    }
}

void myLinkedListAddAtTail(MyLinkedList *obj, int val)
{
    // printf("AddAtTail\n");
    Node *node = (Node *)calloc(1, sizeof(Node));
    node->val = val;
    // printf("obj.length = %d\n", obj->length);
    if (obj->length == 0)
        myLinkedListAddAtHead(obj, val);
    else
    {
        myLinkListSerch(obj, obj->length - 1)->next = node;
        obj->length++;
    }
}

void myLinkedListAddAtIndex(MyLinkedList *obj, int index, int val)
{
    // printf("AddAtIndex\n");
    if (index == 0)
    {
        myLinkedListAddAtHead(obj, val);
    }
    else if (index >= obj->length)
    {
        for (int i = obj->length; i < index; i++)
        {
            myLinkedListAddAtTail(obj, -1);
        }
        myLinkedListAddAtTail(obj, val);
    }
    else
    {
        Node *node = (Node *)calloc(1, sizeof(Node));
        node->val = val;
        Node *pre = myLinkListSerch(obj, index - 1);
        node->next = pre->next;
        pre->next = node;
        obj->length++;
    }
}

void myLinkedListDeleteAtIndex(MyLinkedList *obj, int index)
{
    // printf("DeleteAtIndex\n");
    if (index >= obj->length)
        return;
    Node *pre;
    Node *next;
    if (index != 0)
    {
        pre = myLinkListSerch(obj, index - 1);
        next = pre->next->next;
        free(pre->next);
        pre->next = next;
    }
    else
    {
        next = obj->head->next;
        free(obj->head);
        obj->head = next;
    }
    obj->length--;
}

void myLinkedListFree(MyLinkedList *obj)
{
    Node *cur = obj->head;
    Node *next = obj->head;
    while (next != NULL)
    {
        next = next->next;
        free(cur);
        cur = next;
    }
    free(obj);
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);

 * myLinkedListAddAtHead(obj, val);

 * myLinkedListAddAtTail(obj, val);

 * myLinkedListAddAtIndex(obj, index, val);

 * myLinkedListDeleteAtIndex(obj, index);

 * myLinkedListFree(obj);
*/
// @lc code=end
