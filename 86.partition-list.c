/*
 * @lc app=leetcode id=86 lang=c
 *
 * [86] Partition List
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

struct ListNode *partition(struct ListNode *head, int x)
{
    struct ListNode *curnode = head;
    struct ListNode *lxhead = NULL;
    struct ListNode *lxtail = NULL;
    struct ListNode *gexhead = NULL;
    struct ListNode *gextail = NULL;
    while (curnode != NULL)
    {
        if (curnode->val >= x)
        {
            if (gexhead == NULL)
            {
                gexhead = curnode;
                gextail = curnode;
            }
            else
            {
                gextail->next = curnode;
                gextail = curnode;
            }
        }
        else
        {
            if (lxhead == NULL)
            {
                lxhead = curnode;
                lxtail = curnode;
            }
            else
            {
                lxtail->next = curnode;
                lxtail = curnode;
            }
        }
        curnode = curnode->next;
    }
    if (gextail != NULL)
        gextail->next = NULL;
    if (lxtail != NULL)
        lxtail->next = gexhead;
    return lxhead == NULL ? head : lxhead;
}
// @lc code=end
