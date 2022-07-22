/*
 * @lc app=leetcode id=99 lang=c
 *
 * [99] Recover Binary Search Tree
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
struct TreeNode *firstnode = NULL;
struct TreeNode *secondnode = NULL;
struct TreeNode *prenode = NULL;
void findinvalid(struct TreeNode *node)
{
    if (node == NULL)
        return;
    findinvalid(node->left);
    if (prenode != NULL)
    {
        if (firstnode == NULL && prenode->val >= node->val)
            firstnode = prenode;
        if (firstnode != NULL && prenode->val >= node->val)
            secondnode = node;
    }
    prenode = node;
    findinvalid(node->right);
}
void recoverTree(struct TreeNode *root)
{
    firstnode = NULL;
    secondnode = NULL;
    prenode = NULL;
    findinvalid(root);

    int temp = firstnode->val;
    firstnode->val = secondnode->val;
    secondnode->val = temp;
}
// @lc code=end
