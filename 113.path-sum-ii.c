/*
 * @lc app=leetcode id=113 lang=c
 *
 * [113] Path Sum II
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
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define RESSIZE 1000
void dfs(struct TreeNode *node, int targetSum, int *buf, int bufSize, int **res, int *returnSize, int **returnColumnSizes)
{
    if (node == NULL)
        return;
    buf[bufSize] = node->val;
    bufSize++;
    targetSum -= node->val;
    if (node->left == NULL & node->right == NULL && targetSum == 0)
    {
        res[*returnSize] = (int *)malloc(bufSize * sizeof(int));
        memcpy(res[*returnSize], buf, bufSize * sizeof(int));
        (*returnColumnSizes)[*returnSize] = bufSize;
        (*returnSize)++;
    }
    dfs(node->left, targetSum, buf, bufSize, res, returnSize, returnColumnSizes);
    dfs(node->right, targetSum, buf, bufSize, res, returnSize, returnColumnSizes);
}
int **pathSum(struct TreeNode *root, int targetSum, int *returnSize, int **returnColumnSizes)
{
    int buf[RESSIZE];
    int **res = (int **)malloc(RESSIZE * sizeof(int *));
    *returnSize = 0;
    *returnColumnSizes = (int *)malloc(RESSIZE * sizeof(int));
    dfs(root, targetSum, buf, 0, res, returnSize, returnColumnSizes);
    return res;
}
// @lc code=end
