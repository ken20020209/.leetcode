/*
 * @lc app=leetcode id=112 lang=c
 *
 * [112] Path Sum
 */
struct TreeNode {
     int val;
     struct TreeNode *left;
      struct TreeNode *right;
  };

#include "header/common.h"
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool hasPathSum(struct TreeNode* root, int targetSum){
    if(root==NULL) return false;
    if(targetSum==root->val&&root->left==NULL&&root->right==NULL) return true;
    return hasPathSum(root->left,targetSum-root->val) ||hasPathSum(root->right,targetSum-root->val);
}
// @lc code=end

