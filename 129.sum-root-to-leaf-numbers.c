/*
 * @lc app=leetcode id=129 lang=c
 *
 * [129] Sum Root to Leaf Numbers
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

int helper(struct TreeNode *root, int buf)
{
    if (root == NULL)
        return 0;
    buf = buf * 10 + root->val;
    int res = 0;
    if (root->left == NULL && root->right == NULL)
        res += buf;
    res += helper(root->left, buf);
    res += helper(root->right, buf);
    return res;
}
int sumNumbers(struct TreeNode *root)
{
    return helper(root, 0);
}
// @lc code=end
