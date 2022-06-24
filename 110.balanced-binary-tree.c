/*
 * @lc app=leetcode id=110 lang=c
 *
 * [110] Balanced Binary Tree
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
int abs(a)
{
    return a < 0 ? -a : a;
}
int maxdepth(struct TreeNode *root)
{
    if (root == NULL)
        return 0;
    int l = 1 + maxdepth(root->left);
    int r = 1 + maxdepth(root->right);
    return fmax(l, r);
}

bool isBalanced(struct TreeNode *root)
{
    if(root == NULL)return true;
    int l=maxdepth(root->left);
    int r=maxdepth(root->right);   
    return abs(l-r)<=1&&isBalanced(root->left)&&isBalanced(root->right);
}

// @lc code=end
