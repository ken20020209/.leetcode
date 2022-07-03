/*
 * @lc app=leetcode id=39 lang=c
 *
 * [39] Combination Sum
 */
#include "header\leetcode.h"

// @lc code=start

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void backtrack(int *candidates, int candidatesSize, int target, int *returnSize, int **returnColumnSizes, int ***res, int *ResCapacity, int *arr, int arrsize, int index)
{
    // printf("size:%d\n", arrsize);
    if (target == 0)
    {
        (*res)[*returnSize] = (int *)malloc(arrsize * sizeof(int));
        (*returnColumnSizes)[*returnSize] = arrsize;
        memcpy((*res)[*returnSize], arr, arrsize * sizeof(int));
        (*returnSize)++;
        if ((*returnSize) == (*ResCapacity))
        {
            (*ResCapacity) *= 2;
            *res = (int **)realloc(*res, (*ResCapacity) * sizeof(int *));
            *returnColumnSizes = (int *)realloc(*returnColumnSizes, (*ResCapacity) * sizeof(int));
        }
        return;
    }
    if (target < 0)
        return;
    for (int i = index; i < candidatesSize; i++)
    {
        arr[arrsize] = candidates[i];
        backtrack(candidates, candidatesSize, target - candidates[i], returnSize, returnColumnSizes, res, ResCapacity, arr, arrsize + 1, i);
    }
}
int **combinationSum(int *candidates, int candidatesSize, int target, int *returnSize, int **returnColumnSizes)
{
    int ResCapacity = 1;
    *returnSize = 0;
    int **res = (int **)malloc(ResCapacity * sizeof(int *));
    *returnColumnSizes = (int *)malloc(ResCapacity * sizeof(int));
    int *temp = (int *)malloc(200 * sizeof(int));
    backtrack(candidates, candidatesSize, target, returnSize, returnColumnSizes, &res, &ResCapacity, temp, 0, 0);
    free(temp);
    return res;
}
// @lc code=end
