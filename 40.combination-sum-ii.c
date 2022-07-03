/*
 * @lc app=leetcode id=40 lang=c
 *
 * [40] Combination Sum II
 */
#include "header\leetcode.h"

// @lc code=start

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmp(int *a, int *b)
{
    return *a - *b;
}
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
    int preCandidate = -1;
    for (int i = index; i < candidatesSize; i++)
    {
        // sum2 
        // skip same value
        if (preCandidate == candidates[i])
            continue;
        else
            preCandidate = candidates[i];
        // sum2
        arr[arrsize] = candidates[i];
        backtrack(candidates, candidatesSize, target - candidates[i], returnSize, returnColumnSizes, res, ResCapacity, arr, arrsize + 1, i + 1);
    }
}
int **combinationSum(int *candidates, int candidatesSize, int target, int *returnSize, int **returnColumnSizes)
{
    int ResCapacity = 1;
    *returnSize = 0;
    int **res = (int **)malloc(ResCapacity * sizeof(int *));
    *returnColumnSizes = (int *)malloc(ResCapacity * sizeof(int));
    int *temp = (int *)malloc(200 * sizeof(int));
    qsort(candidates, candidatesSize, sizeof(int), cmp); // sum2 need sort
    backtrack(candidates, candidatesSize, target, returnSize, returnColumnSizes, &res, &ResCapacity, temp, 0, 0);
    free(temp);
    return res;
}
int **combinationSum2(int *candidates, int candidatesSize, int target, int *returnSize, int **returnColumnSizes)
{
    // use sort candidates and backtracking skip same candidates in same function
    return combinationSum(candidates, candidatesSize, target, returnSize, returnColumnSizes);
}
// @lc code=end
