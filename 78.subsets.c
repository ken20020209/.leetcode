/*
 * @lc app=leetcode id=78 lang=c
 *
 * [78] Subsets
 */
#include "header\leetcode.h"

// @lc code=start

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void helper(int *nums, int numsSize, int **res, int *returnSize, int **returnColumnSizes, int index, int size, int *arr)
{

    arr[size++] = nums[index];

    (*returnSize)++;
    (*returnColumnSizes)[*returnSize - 1] = size;
    res[*returnSize - 1] = (int *)malloc(size * sizeof(int));

    memcpy(res[*returnSize - 1], arr, size * sizeof(int));

    for (int i = index + 1; i < numsSize; i++)
    {
        helper(nums, numsSize, res, returnSize, returnColumnSizes, i, size, arr);
    }
}
int **subsets(int *nums, int numsSize, int *returnSize, int **returnColumnSizes)
{
    int temp = 0;
    *returnSize = 1;
    int resCapacity = 10000;
    int *arr = (int *)malloc(numsSize * sizeof(int));
    int **res = (int **)malloc(resCapacity * sizeof(int *));
    *returnColumnSizes = (int *)malloc(resCapacity * sizeof(int));
    res[*returnSize - 1] = (int *)malloc(0);
    (*returnColumnSizes)[0] = 0;

    for (int i = 0; i < numsSize; i++)
    {
        helper(nums, numsSize, res, returnSize, returnColumnSizes, i, 0, arr);
    }
    free(arr);
    return res;
}
// @lc code=end
