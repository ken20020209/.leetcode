/*
 * @lc app=leetcode id=117 lang=c
 *
 * [117] Populating Next Right Pointers in Each Node II
 */
#include "header\leetcode.h"

struct Node
{
    int val;
    struct Node *left;
    struct Node *right;
    struct Node *next;
};
// @lc code=start
/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *left;
 *     struct Node *right;
 *     struct Node *next;
 * };
 */

struct Node *connect(struct Node *root)
{
    if (root == NULL)
        return root;
    struct Node *node = root->next;
    while (node != NULL && node->left == NULL && node->right == NULL)
    {
        node = node->next;
    }
    if (node != NULL)
    {
        if (node->left != NULL)
            node = node->left;
        else if (node->right != NULL)
            node = node->right;
    }
    if (root->left != NULL)
    {
        root->left->next = root->right;
        if (root->right == NULL)
        {
            root->left->next = node;
        }
    }
    if (root->right != NULL)
    {
        root->right->next = node;
    }

    connect(root->right);
    connect(root->left);
    return root;
}
// @lc code=end
