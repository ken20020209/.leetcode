/*
 * @lc app=leetcode id=56 lang=c
 *
 * [56] Merge Intervals
 */
#include "header\leetcode.h"
#include "header\readtestcase.h"
// @lc code=start

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmp(const void **a, const void **b)
{
    return **(int **)a - **(int **)b;
}
int **merge(int **intervals, int intervalsSize, int *intervalsColSize, int *returnSize, int **returnColumnSizes)
{
    int inL = intervalsSize;
    int inC = *intervalsColSize;
    int pos = 0;
    int **res = (int **)malloc(inL * sizeof(int *));
    *returnSize = 0;
    qsort(intervals, inL, sizeof(int *), cmp);
    // for (int  i = 0; i < inL; i++)
    // {
    //     printf("%d,%d\n",intervals[i][0],intervals[i][1]);
    // }
    res[*returnSize] = (int *)malloc(2 * sizeof(int));
    res[*returnSize][0] = intervals[0][0];
    res[*returnSize][1] = intervals[0][1];
    for (int i = 1; i < inL; i++)
    {
        if (res[*returnSize][1] < intervals[i][0])
        {
            (*returnSize)++;
            res[*returnSize] = (int *)malloc(2 * sizeof(int));
            res[*returnSize][0] = intervals[i][0];
            res[*returnSize][1] = intervals[i][1];
        }
        else
        {
            res[*returnSize][1] = fmax(res[*returnSize][1], intervals[i][1]);
        }
    }
    (*returnSize)++;
    *returnColumnSizes = (int *)malloc(*returnSize * sizeof(int));
    for (int i = 0; i < *returnSize; i++)
        (*returnColumnSizes)[i] = 2;
    res = (int **)realloc(res, *returnSize * sizeof(int *));
    return res;
}
// @lc code=end
int main()
{
    char **str = readtestcase();
    int **intervals;
    int intervalsSize;
    int *intervalsColSize;
    int returnSize;
    int *returnC;
    intervals = stoiaa(str[0], &intervalsSize, &intervalsColSize);
    merge(intervals, intervalsSize, intervalsColSize, &returnSize, &returnC);

    return 0;
}