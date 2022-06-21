/*
 * @lc app=leetcode id=98 lang=c
 *
 * [98] Validate Binary Search Tree
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

bool validBSTChecker(struct TreeNode* root, long min, long max) {
    if (root == NULL) return true;
    
    if (root->val <= min || root->val >= max) return false;
    
    return validBSTChecker(root->left, min, root->val) && validBSTChecker(root->right, root->val, max);
}

bool isValidBST(struct TreeNode* root){
    return validBSTChecker(root, LONG_MIN, LONG_MAX);
}

// @lc code=end

