/*
 * @lc app=leetcode id=986 lang=c
 *
 * [986] Interval List Intersections
 */
#include "header\leetcode.h"

// @lc code=start

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **intervalIntersection(int **firstList, int firstListSize, int *firstListColSize, int **secondList, int secondListSize, int *secondListColSize, int *returnSize, int **returnColumnSizes)
{
    int resS = 2;
    int **res = (int **)malloc(resS * sizeof(int *));
    *returnColumnSizes = (int *)malloc(resS * sizeof(int));
    *returnSize = 0;
    int i = 0;
    int j = 0;
    while (i < firstListSize && j < secondListSize)
    {
        if (firstList[i][0] <= secondList[j][1] && secondList[j][0] <= firstList[i][1])
        {
            if (*returnSize == resS)
            {
                resS *= 2;
                res = (int **)realloc(res, resS * sizeof(int *));
                *returnColumnSizes = (int *)realloc(*returnColumnSizes, resS * sizeof(int));
            }
            res[*returnSize] = (int *)malloc(2 * sizeof(int));
            (*returnColumnSizes)[*returnSize] = 2;
            res[*returnSize][0] = fmax(firstList[i][0], secondList[j][0]);
            res[*returnSize][1] = fmin(firstList[i][1], secondList[j][1]);
            (*returnSize)++;
        }
        if (firstList[i][1] <= secondList[j][1])
            i++;
        else
            j++;
    }

    return res;
}
// @lc code=end
