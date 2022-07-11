/*
 * @lc app=leetcode id=236 lang=c
 *
 * [236] Lowest Common Ancestor of a Binary Tree
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
struct TreeNode *lowestCommonAncestor(struct TreeNode *root, struct TreeNode *p, struct TreeNode *q)
{
    if (root == p || root == q || root == NULL)
        return root;
    struct TreeNode *left = lowestCommonAncestor(root->left, p, q);
    struct TreeNode *right = lowestCommonAncestor(root->right, p, q);
    if (left == NULL)
        return right;
    else if (right == NULL)
        return left;
    else
        return root;
}
// @lc code=end
