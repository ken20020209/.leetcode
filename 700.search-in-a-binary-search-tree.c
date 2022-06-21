/*
 * @lc app=leetcode id=700 lang=c
 *
 * [700] Search in a Binary Search Tree
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


struct TreeNode* searchBST(struct TreeNode* root, int val)
{
    if(root == NULL)return NULL;
    if(root->val == val)return root;
    struct TreeNode *res1=searchBST(root->left, val);
    struct TreeNode *res2=searchBST(root->right, val);
    return res1!=NULL?res1:res2;
}
// @lc code=end

