/*
 * @lc app=leetcode id=973 lang=c
 *
 * [973] K Closest Points to Origin
 */
#include "header\leetcode.h"

// @lc code=start

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int dis(int x1, int y1)
{
    return (pow(x1, 2) + pow(y1, 2));
}
int cmp(int *a, int *b)
{
    return *a - *b;
}
int **kClosest(int **points, int pointsSize, int *pointsColSize, int k, int *returnSize, int **returnColumnSizes)
{
    int **res = (int **)malloc(sizeof(int *) * k);
    int temp[pointsSize][2];
    *returnSize = k;
    *returnColumnSizes = (int *)malloc(sizeof(int) * k);
    for (int i = 0; i < k; i++)
    {
        res[i] = (int *)malloc(2 * sizeof(int));
        (*returnColumnSizes)[i] = 2;
    }
    for (int i = 0; i < pointsSize; i++)
    {
        temp[i][0] = dis(points[i][0], points[i][1]);
        temp[i][1] = i;
    }

    qsort(temp, pointsSize, 2 * sizeof(int), cmp);

    for (int i = 0; i < k; i++)
    {
        res[i][0] = points[temp[i][1]][0];
        res[i][1] = points[temp[i][1]][1];
    }

    return res;
}
// @lc code=end
