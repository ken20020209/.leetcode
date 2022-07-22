/*
 * @lc app=leetcode id=107 lang=c
 *
 * [107] Binary Tree Level Order Traversal II
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

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **levelOrderBottom(struct TreeNode *root, int *returnSize, int **returnColumnSizes)
{
    *returnColumnSizes = (int *)calloc(1000, sizeof(int));
    *returnSize = 0;
    if (root == NULL)
        return NULL;
    struct TreeNode *queue[3000];
    int front = 0;
    int rear = -1;
    int buf[1000];
    int bufSize = 0;
    int **res = (int **)malloc(1000 * sizeof(int *));
    queue[++rear] = root;
    while (front <= rear)
    {
        int size = rear - front + 1;
        bufSize = 0;
        while (size)
        {

            size--;
            buf[bufSize++] = queue[front]->val;
            if (queue[front]->left != NULL)
                queue[++rear] = queue[front]->left;
            if (queue[front]->right != NULL)
                queue[++rear] = queue[front]->right;
            front++;
        }
        (*returnColumnSizes)[*returnSize] = bufSize;
        res[*returnSize] = (int *)malloc(bufSize * sizeof(int));
        memcpy(res[*returnSize], buf, bufSize * sizeof(int));
        (*returnSize)++;
    }
    res = (int **)realloc(res, *returnSize * sizeof(int *));
    *returnColumnSizes = (int *)realloc(*returnColumnSizes, *returnSize * sizeof(int));
    for (int i = 0; i < *returnSize / 2; i++)
    {
        int *swapres = res[i];
        int swapcol = (*returnColumnSizes)[i];

        res[i] = res[*returnSize - 1 - i];
        (*returnColumnSizes)[i] = (*returnColumnSizes)[*returnSize - 1 - i];

        res[*returnSize - 1 - i] = swapres;
        (*returnColumnSizes)[*returnSize - 1 - i] = swapcol;
    }
    return res;
}
// @lc code=end
