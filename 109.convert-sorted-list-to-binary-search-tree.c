/*
 * @lc app=leetcode id=109 lang=c
 *
 * [109] Convert Sorted List to Binary Search Tree
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct ListNode *node;
struct TreeNode *reverseInorder(int low, int high)
{
    if (low > high)
        return NULL;
    int mid = low + (high - low) / 2;
    struct TreeNode *ret = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    ret->left = reverseInorder(low, mid - 1);
    ret->val = node->val;
    node = node->next;
    ret->right = reverseInorder(mid + 1, high);
    return ret;
}
struct TreeNode *sortedListToBST(struct ListNode *head)
{
    int size = 0;
    node = head;
    while (head)
    {
        size++;
        head = head->next;
    }
    return reverseInorder(0, size - 1);
}
// @lc code=end
