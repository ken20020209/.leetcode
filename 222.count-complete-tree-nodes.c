/*
 * @lc app=leetcode id=222 lang=c
 *
 * [222] Count Complete Tree Nodes
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

int height(struct TreeNode *root)
{
    if (root == NULL)
        return 0;
    return 1 + height(root->left);
}
int countNodes(struct TreeNode *root)
{
    if (root == NULL)
        return 0;
    int l = height(root->left);
    int r = height(root->right);
    int res;
    if (r == l)
    {
        res = 1 << l;
        res += countNodes(root->right);
    }
    else
    {
        res = 1 << l - 1;
        res += countNodes(root->left);
    }
    return res;
}
// @lc code=end
