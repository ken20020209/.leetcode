/*
 * @lc app=leetcode id=82 lang=c
 *
 * [82] Remove Duplicates from Sorted List II
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

struct ListNode *deleteDuplicates(struct ListNode *head)
{

    struct ListNode *preNode;
    struct ListNode *Sentinel = (struct ListNode *)malloc(sizeof(struct ListNode));
    Sentinel->next=head;
    preNode = Sentinel;
    while (head != NULL)
    {
        if (head->next != NULL && head->val == head->next->val)
        {
            while (head->next != NULL && head->val == head->next->val)
                head = head->next;
            preNode->next = head->next;
        }
        else
        {
            preNode = preNode->next;
        }
        head = head->next;
    }
    preNode=Sentinel->next;
    free(Sentinel);
    return preNode;
}
// @lc code=end
