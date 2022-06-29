/*
 * @lc app=leetcode id=572 lang=c
 *
 * [572] Subtree of Another Tree
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

bool helper(struct TreeNode *root, struct TreeNode *subRoot)
{
    if (root == NULL && subRoot == NULL)
        return true;
    if (subRoot == NULL || root == NULL)
        return false;
    if (root->val != subRoot->val)
        return false;
    return helper(root->left, subRoot->left) && helper(root->right, subRoot->right);
}
bool isSubtree(struct TreeNode *root, struct TreeNode *subRoot)
{
    if (root == NULL)
        return false;
    return helper(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}
// @lc code=end
