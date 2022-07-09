/*
 * @lc app=leetcode id=450 lang=c
 *
 * [450] Delete Node in a BST
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
void transplant(struct TreeNode **root, struct TreeNode *parent, struct TreeNode *DeNode, struct TreeNode *ReNode)
{
    // replace node
    // DeNode change to ReNode

    // if node is root
    if (parent == NULL)
        *root = ReNode;
    // find node is left or right
    else if (parent->left == DeNode)
        parent->left = ReNode;
    else
        parent->right = ReNode;
}
// return TreeMInimum parent
struct TreeNode *treeMinimumP(struct TreeNode **parent, struct TreeNode *node)
{
    // fine smallest key node and it parent
    while (node->left != NULL)
    {
        *parent = node;
        node = node->left;
    }
    return node;
}
void TreeDelete(struct TreeNode **root, struct TreeNode *parent, struct TreeNode *node)
{
    // only have one child
    if (node->left == NULL)
        transplant(root, parent, node, node->right);
    else if (node->right == NULL)
        transplant(root, parent, node, node->left);
    // two child
    else
    {
        struct TreeNode *minimumP = node;
        struct TreeNode *minimum = treeMinimumP(&minimumP, node->right);
        if (minimumP != node)
        {
            transplant(root, minimumP, minimum, minimum->right);
            minimum->right = node->right;
        }
        transplant(root, parent, node, minimum);
        minimum->left = node->left;
    }
    free(node);
}
struct TreeNode *deleteNode(struct TreeNode *root, int key)
{
    struct TreeNode *parent = NULL;
    struct TreeNode *node = root;
    // fine delete node
    while (node != NULL)
    {
        if (node->val == key)
            break;
        parent = node;
        if (key > node->val)
            node = node->right;
        else
            node = node->left;
    }
    if (node != NULL)
        TreeDelete(&root, parent, node);

    return root;
}
// @lc code=end
