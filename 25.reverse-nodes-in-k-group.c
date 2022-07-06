/*
 * @lc app=leetcode id=25 lang=c
 *
 * [25] Reverse Nodes in k-Group
 */
#include "header\leetcode.h"
struct ListNode
{
    int val;
    struct ListNode *next;
};
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *reverseNode(struct ListNode *head)
{
    struct ListNode *preNode = NULL;
    struct ListNode *curNode = head;
    struct ListNode *nextNode = head->next;
    while (nextNode != NULL)
    {
        curNode->next = preNode;
        preNode = curNode;
        curNode = nextNode;
        nextNode = nextNode->next;
    }
    curNode->next = preNode;
    return curNode;
}
struct ListNode *reverseKGroup(struct ListNode *head, int k)
{
    if (head == NULL)
        return head;
    struct ListNode *node = head;
    struct ListNode *tail = head;
    struct ListNode *nextNode;
    for (int i = 0; i < k; i++)
    {

        if (node == NULL)
        {
            return head;
        }
        tail = node;
        node = node->next;
    }
    nextNode = reverseKGroup(node, k);
    tail->next = NULL;
    tail = reverseNode(head);
    head->next = nextNode;
    head = tail;
    return head;
}
// @lc code=end
