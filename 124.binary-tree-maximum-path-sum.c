/*
 * @lc app=leetcode id=124 lang=c
 *
 * [124] Binary Tree Maximum Path Sum
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
// O(n^2) serch every node
// int helper(struct TreeNode *root, int first)
// {
//     if (root == NULL)
//         return -1000;
//     int res = root->val;
//     int left = helper(root->left, 0);
//     int right = helper(root->right, 0);
//     if (first)
//     {
//         res = fmax(res, root->val + left + right);
//     }
//     res = fmax(res, root->val + left);
//     res = fmax(res, root->val + right);
//     return res;
// }
// int maxPathSum(struct TreeNode *root)
// {
//     if (root == NULL)
//         return -1000;
//     int res = helper(root, 1);
//     res = fmax(res, maxPathSum(root->left));
//     res = fmax(res, maxPathSum(root->right));
//     return res;
// }

// O(n)
int max;
int helper(struct TreeNode *root)
{
    if (root == NULL)
        return -1000;
    int res = root->val;
    int left = helper(root->left);
    int right = helper(root->right);

    // use res to return the path
    res = fmax(res, root->val + left);
    res = fmax(res, root->val + right);
    // record the max at here node
    max = fmax(max, root->val + left + right);
    max = fmax(max, root->val);
    max = fmax(max, res);
    return res;
}
int maxPathSum(struct TreeNode *root)
{
    max = -1000;
    int res = helper(root);
    return fmax(res, max);
}

// @lc code=end
