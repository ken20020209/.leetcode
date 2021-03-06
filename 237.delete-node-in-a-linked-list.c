/*
 * @lc app=leetcode id=237 lang=c
 *
 * [237] Delete Node in a Linked List
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
void deleteNode(struct ListNode *node)
{
    node->val = node->next->val;
    node->next = node->next->next;
}
// @lc code=end
