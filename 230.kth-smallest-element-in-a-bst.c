/*
 * @lc app=leetcode id=230 lang=c
 *
 * [230] Kth Smallest Element in a BST
 */
#include "header\leetcode.h"

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void helper(struct TreeNode *node, int *k, int *res)
{
    if (*k == 0)
        return;
    if (node == NULL)
        return;
    int ret = 0;
    helper(node->left, k, res);
    (*k)--;
    if (*k == 0)
    {
        *res = node->val;
    }
    helper(node->right, k, res);
}
int kthSmallest(struct TreeNode *root, int k)
{
    int res = 0;
    helper(root, &k, &res);
    return res;
}
// @lc code=end
