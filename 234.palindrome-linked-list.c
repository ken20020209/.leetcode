/*
 * @lc app=leetcode id=234 lang=c
 *
 * [234] Palindrome Linked List
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
// O(n)time O(1) space;
bool isPalindrome(struct ListNode *head)
{
    // fine midle
    struct ListNode *fast = head;
    struct ListNode *slow = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    fast = slow->next;
    // if fast ==NULL means linked list only have one node
    if (fast == NULL)
        return true;
    slow->next = NULL;
    // reverse list
    struct ListNode *pre = NULL;
    struct ListNode *cur = fast;
    struct ListNode *next = fast->next;
    while (next != NULL)
    {
        cur->next = pre;
        pre = cur;
        cur = next;
        next = next->next;
    }
    cur->next = pre;
    // check palindrome
    while (cur != NULL)
    {
        // printf("cur:%d head:%d\n", cur->val, head->val);
        if (cur->val != head->val)
            return false;
        cur = cur->next;
        head = head->next;
    }
    return true;
}
// @lc code=end
