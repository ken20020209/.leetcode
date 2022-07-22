/*
 * @lc app=leetcode id=114 lang=c
 *
 * [114] Flatten Binary Tree to Linked List
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

void flatten(struct TreeNode *root)
{
    while (root != NULL)
    {
        struct TreeNode *left = root->left;
        struct TreeNode *right = root->right;
        struct TreeNode *last = left;
        if (last != NULL)
        {
            root->right = left;
            while (last->right != NULL)
            {
                last = last->right;
            }
            last->right = right;
            root->left = NULL;
        }
        root = root->right;
    }
}
// @lc code=end
