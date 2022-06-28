/*
 * @lc app=leetcode id=1367 lang=c
 *
 * [1367] Linked List in Binary Tree
 */
#include "header\leetcode.h"
struct ListNode
{
    int val;
    struct ListNode *next;
};

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
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
bool dfs(struct ListNode *head, struct TreeNode *root)
{
    if (head == NULL)
        return true;
    if (root == NULL)
        return false;
    return head->val == root->val && (dfs(head->next, root->left) || dfs(head->next, root->right));
}
bool isSubPath(struct ListNode *head, struct TreeNode *root)
{
    if (head == NULL)
        return true;
    if (root == NULL)
        return false;
    return dfs(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
}
// @lc code=end
