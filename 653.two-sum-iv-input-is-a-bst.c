/*
 * @lc app=leetcode id=653 lang=c
 *
 * [653] Two Sum IV - Input is a BST
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
bool help(struct TreeNode *node,int k,int *map)
{
    if(node==NULL) return false;
    if(map[50000+node->val]==true) return true;
    else map[50000+k-node->val] = true;
    return help(node->left,k,map)||help(node->right,k,map);
}

bool findTarget(struct TreeNode* root, int k)
{
    int map[100000]={0};
    return help(root,k,map);
}
// @lc code=end

