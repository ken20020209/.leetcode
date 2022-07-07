/*
 * @lc app=leetcode id=445 lang=c
 *
 * [445] Add Two Numbers II
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

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode **st_l1 = malloc(100 * sizeof(struct ListNode *));
    struct ListNode **st_l2 = malloc(100 * sizeof(struct ListNode *));
    struct ListNode *head;
    int carry = 0;
    int top_l1 = -1;
    int top_l2 = -1;

    while (l1 != NULL)
    {
        st_l1[++top_l1] = l1;
        l1 = l1->next;
    }
    while (l2 != NULL)
    {
        st_l2[++top_l2] = l2;
        l2 = l2->next;
    }

    if (top_l2 > top_l1)
    {
        int temp = top_l1;
        top_l1 = top_l2;
        top_l2 = temp;
        struct ListNode **swapNode = st_l1;
        st_l1 = st_l2;
        st_l2 = swapNode;
    }
    while (top_l1 >= 0)
    {
        st_l1[top_l1]->val += carry + (top_l2 >= 0 ? st_l2[top_l2--]->val : 0);
        if (carry == 1)
            carry = 0;
        if (st_l1[top_l1]->val >= 10)
        {
            carry = 1;
            st_l1[top_l1]->val -= 10;
        }
        top_l1--;
    }
    if (carry == 1)
    {
        head = (struct ListNode *)malloc(sizeof(struct ListNode));
        head->val = 1;
        head->next = st_l1[0];
    }
    else
    {
        head = st_l1[0];
    }
    free(st_l1);
    free(st_l2);
    return head;
}
// @lc code=end
