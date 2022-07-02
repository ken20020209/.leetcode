/*
 * @lc app=leetcode id=429 lang=c
 *
 * [429] N-ary Tree Level Order Traversal
 */
#include "header\leetcode.h"
struct Node
{
    int val;
    int numChildren;
    struct Node **children;
};
// @lc code=start
/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **levelOrder(struct Node *root, int *returnSize, int **returnColumnSizes)
{

    if (root == NULL)
    {
        *returnColumnSizes = malloc(0);
        *returnSize = 0;
        return NULL;
    }
    struct Node *queue[10000];
    int front = 0;
    int rear = -1;
    int step = 0;
    int **res = (int **)malloc((step + 1) * sizeof(int *));
    *returnColumnSizes = (int *)malloc((step + 1) * sizeof(int));
    queue[++rear] = root;
    while (front <= rear)
    {
        int size = rear - front + 1;
        res[step] = (int *)malloc(size * sizeof(int));
        (*returnColumnSizes)[step] = size;
        while (size)
        {
            struct Node *node = queue[front++];
            res[step][(*returnColumnSizes)[step] - size] = node->val;
            size--;
            for (int i = 0; i < node->numChildren; i++)
            {
                queue[++rear] = node->children[i];
            }
        }
        step++;
        res = (int **)realloc(res, (step + 1) * sizeof(int *));
        *returnColumnSizes = (int *)realloc(*returnColumnSizes, (step + 1) * sizeof(int));
    }
    *returnSize = step;
    return res;
}
// @lc code=end
