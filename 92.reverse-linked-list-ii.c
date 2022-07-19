/*
 * @lc app=leetcode id=92 lang=c
 *
 * [92] Reverse Linked List II
 */
#include "header\leetcode.h"

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *reverseBetween(struct ListNode *head, int left, int right)
{
    int len = right - left + 1;
    struct ListNode *leftN = NULL;
    struct ListNode *node = head;
    for (int i = 1; i < left; i++)
    {
        leftN = node;
        node = node->next;
    }
    struct ListNode *preN = NULL;
    struct ListNode *tail = node;
    struct ListNode *nextN = node->next;
    for (int i = 0; i < len; i++)
    {
        node->next = preN;
        preN = node;
        node = nextN;
        if (nextN != NULL)
            nextN = nextN->next;
    }
    if (leftN != NULL)
        leftN->next = preN;
    if (tail != node)
        tail->next = node;
    return left == 1 ? preN : head;
}
// @lc code=end
