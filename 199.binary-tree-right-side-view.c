/*
 * @lc app=leetcode id=199 lang=c
 *
 * [199] Binary Tree Right Side View
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

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int helper(struct TreeNode *node, int *res, int depth)
{

    if (node == NULL)
        return 0;
    // printf("%d\n", node->val);
    int left = helper(node->left, res, depth + 1);
    res[depth] = node->val;
    int right = helper(node->right, res, depth + 1);
    return fmax(left, right) + 1;
}
int *rightSideView(struct TreeNode *root, int *returnSize)
{
    int *res = (int *)malloc(sizeof(int) * 100);
    *returnSize = helper(root, res, 0);
    return res;
}
// @lc code=end
