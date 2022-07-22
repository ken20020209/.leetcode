/*
 * @lc app=leetcode id=106 lang=c
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
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
int map[7000];
struct TreeNode *helper(int *inorder, int *postorder, int left, int right, int *postIndex)
{
    if (left > right)
        return NULL;
    struct TreeNode *node = (struct TreeNode *)calloc(1, sizeof(struct TreeNode));
    (*postIndex)--;
    node->val = postorder[*postIndex];
    int index = 0;
    // for (int i = left; i <= right; i++)
    // {
    //     if (inorder[i] == postorder[*postIndex])
    //     {
    //         index = i;
    //         break;
    //     }
    // }
    index = map[postorder[*postIndex] + 3000];
    node->right = helper(inorder, postorder, index + 1, right, postIndex);
    node->left = helper(inorder, postorder, left, index - 1, postIndex);
    return node;
}
struct TreeNode *buildTree(int *inorder, int inorderSize, int *postorder, int postorderSize)
{
    int index = postorderSize;
    for (int i = 0; i < inorderSize; i++)
    {
        map[inorder[i] + 3000] = i;
    }
    return helper(inorder, postorder, 0, inorderSize - 1, &index);
}
// @lc code=end
