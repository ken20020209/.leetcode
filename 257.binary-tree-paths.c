/*
 * @lc app=leetcode id=257 lang=c
 *
 * [257] Binary Tree Paths
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

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void dfs(struct TreeNode *node, char *buf, int *returnSize, char **res)
{

    if (node == NULL)
        return;
    int prelen = strlen(buf);
    if (prelen == 0)
        sprintf(buf, "%d", node->val);
    else
        sprintf(buf, "%s->%d", buf, node->val);
    int curlen = strlen(buf);
    if (node->left == NULL && node->right == NULL)
    {
        int len = strlen(buf);
        res[*returnSize] = malloc((len + 1) * sizeof(char));
        strcpy(res[*returnSize], buf);
        (*returnSize)++;
    }
    dfs(node->left, buf, returnSize, res);
    dfs(node->right, buf, returnSize, res);
    buf[prelen] = '\0';
}
char **binaryTreePaths(struct TreeNode *root, int *returnSize)
{
    char buf[1000] = {0};
    *returnSize = 0;
    char **res = (char **)malloc(sizeof(char *) * 40);
    dfs(root, buf, returnSize, res);
    return res;
}
// @lc code=end
