/*
 * @lc app=leetcode id=24 lang=c
 *
 * [24] Swap Nodes in Pairs
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

struct ListNode *swapPairs(struct ListNode *head)
{
    if (head == NULL)
        return head;
    struct ListNode *prev = head;
    struct ListNode *cur = head;
    struct ListNode *next = head;
    if (head->next != NULL)
    {
        head = head->next;
    }
    while (next != NULL && next->next != NULL)
    {
        prev = next;
        cur = next->next;
        next = next->next->next;
        if (next != NULL && next->next != NULL)
        {
            prev->next = next->next;
        }
        else
        {
            prev->next = next;
        }
        cur->next = prev;
    }
    return head;
}
// @lc code=end
