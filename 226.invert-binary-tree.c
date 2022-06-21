/*
 * @lc app=leetcode id=226 lang=c
 *
 * [226] Invert Binary Tree
 */
#include "header\common.h"
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


struct TreeNode* invertTree(struct TreeNode* root)
{
    if(root==NULL)return root;
    if (root->left == NULL&&root->right == NULL)return root;
    struct TreeNode* temp = root;
    temp=root->left;
    root->left=root->right;
    root->right=temp;
    invertTree(root->left);
    invertTree(root->right);
    return root;
}
// @lc code=end

