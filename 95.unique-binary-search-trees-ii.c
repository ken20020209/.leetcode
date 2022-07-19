/*
 * @lc app=leetcode id=95 lang=c
 *
 * [95] Unique Binary Search Trees II
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
struct TreeNode **generateTrees(int n, int *returnSize)
{
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = i + 1;
    }
}
// @lc code=end
