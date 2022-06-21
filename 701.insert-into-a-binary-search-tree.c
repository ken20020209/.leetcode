/*
 * @lc app=leetcode id=701 lang=c
 *
 * [701] Insert into a Binary Search Tree
 */
#include "header\leetcode.h"
struct TreeNode {
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


struct TreeNode* insertIntoBST(struct TreeNode* root, int val)
{
    if(root==NULL)
    {
        root=(struct TreeNode *)calloc(1,sizeof(struct TreeNode));
        root->val=val;
        return root;
    } 
    printf("%d\n", root->val);
    if(val>root->val)
    {
        if (root->right==NULL)
        {
           root->right = (struct TreeNode *)calloc(1,sizeof(struct TreeNode));
           root->right->val = val;
           return root;
        }     
        insertIntoBST(root->right, val);
    }
    else
    {
        if (root->left==NULL)
        {
           root->left = (struct TreeNode *)calloc(1,sizeof(struct TreeNode));
           root->left->val = val;
           return root;
        }  
        insertIntoBST(root->left, val);
    }
    return root;
}
// @lc code=end

