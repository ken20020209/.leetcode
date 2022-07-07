/*
 * @lc app=leetcode id=108 lang=c
 *
 * [108] Convert Sorted Array to Binary Search Tree
 */
#include "header\leetcode.h"
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode *helper(int *nums, int start, int end)
{
    if (end < start)
        return NULL;
    struct TreeNode *root = (struct TreeNode *)calloc(1, sizeof(struct TreeNode));
    int mid = (start + end) / 2;
    root->val = nums[mid];
    // printf("%d\n", root->val);
    root->left = helper(nums, start, mid - 1);
    root->right = helper(nums, mid + 1, end);
    return root;
}
struct TreeNode *sortedArrayToBST(int *nums, int numsSize)
{
    struct TreeNode *root;
    root = helper(nums, 0, numsSize - 1);
    return root;
}
// @lc code=end
