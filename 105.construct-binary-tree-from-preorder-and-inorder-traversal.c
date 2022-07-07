/*
 * @lc app=leetcode id=105 lang=c
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
struct TreeNode *helper(int *preorder, int *indexPreoder, int preorderSize, int *inorder, int left, int right, int inorderSize)
{
    if (left > right)
        return NULL;
    struct TreeNode *node = (struct TreeNode *)calloc(1, sizeof(struct TreeNode));
    node->val = preorder[*indexPreoder];

    (*indexPreoder)++;
    int index = -1;
    // line serch
    // can use map or bs to otimizaion
    for (int i = 0; i < inorderSize; i++)
    {
        if (node->val == inorder[i])
        {
            index = i;
            break;
        }
    }
    node->left = helper(preorder, indexPreoder, preorderSize, inorder, left, index - 1, inorderSize);
    node->right = helper(preorder, indexPreoder, preorderSize, inorder, index + 1, right, inorderSize);
    return node;
}
struct TreeNode *buildTree(int *preorder, int preorderSize, int *inorder, int inorderSize)
{
    int indexPreoder = 0;
    struct TreeNode *root = helper(preorder, &indexPreoder, preorderSize, inorder, 0, inorderSize - 1, inorderSize);
    return root;
}
// @lc code=end
