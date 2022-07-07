/*
 * @lc app=leetcode id=103 lang=c
 *
 * [103] Binary Tree Zigzag Level Order Traversal
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
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int **zigzagLevelOrder(struct TreeNode *root, int *returnSize, int **returnColumnSizes)
{

    struct TreeNode *queue[10000];
    int front = 0;
    int rear = -1;
    queue[++rear] = root;
    int step = 0;
    *returnSize = 0;
    int **res = (int **)malloc(0);
    *returnColumnSizes = (int *)malloc(0);
    if (root == NULL)
        return res;
    while (front <= rear)
    {
        int size = rear - front + 1;

        res = (int **)realloc(res, (step + 1) * sizeof(int *));
        res[step] = (int *)malloc(size * sizeof(int));
        *returnColumnSizes = (int *)realloc(*returnColumnSizes, (step + 1) * sizeof(int));
        (*returnColumnSizes)[step] = size;

        int start = rear;
        int end = front;
        front = rear + 1;
        for (int i = start; i >= end; i--)
        {
            res[step][start - i] = queue[i]->val;
            if (step % 2 == 1)
            {
                if (queue[i]->right != NULL)
                    queue[++rear] = queue[i]->right;
                if (queue[i]->left != NULL)
                    queue[++rear] = queue[i]->left;
            }
            else
            {
                if (queue[i]->left != NULL)
                    queue[++rear] = queue[i]->left;
                if (queue[i]->right != NULL)
                    queue[++rear] = queue[i]->right;
            }
        }
        step++;
    }
    *returnSize = step;
    return res;
}
// @lc code=end
