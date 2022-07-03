/*
 * @lc app=leetcode id=160 lang=c
 *
 * [160] Intersection of Two Linked Lists
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
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
{
    struct ListNode *slow;
    struct ListNode *fast;
    struct ListNode *temp;
    slow = headA;
    while (slow->next != NULL)
    {
        slow = slow->next;
    }
    temp = slow;
    slow->next = headB;
    slow = headA;
    fast = headA;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            // printf("slow:%d fast:%d\n", slow->val, fast->val);
            fast = headA;
            while (slow != fast)
            {

                slow = slow->next;
                fast = fast->next;
                // printf("slow:%d fast:%d\n", slow->val, fast->val);
            }
            temp->next = NULL;
            return slow;
        }
    }
    temp->next = NULL;
    return 0;
}
// @lc code=end
