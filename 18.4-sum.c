/*
 * @lc app=leetcode id=18 lang=c
 *
 * [18] 4Sum
 */
#include "header\leetcode.h"

// @lc code=start

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define printf void;
int cmp(int *a, int *b)
{
    return *a - *b;
}
int **fourSum(int *nums, int numsSize, int target, int *returnSize, int **returnColumnSizes)
{
    qsort(nums, numsSize, sizeof(int), cmp);
    int capacity = 2;
    int **res = (int *)malloc(sizeof(int *) * capacity);
    *returnColumnSizes = (int *)malloc(sizeof(int) * capacity);
    *returnSize = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        for (int j = i + 1; j < numsSize; j++)
        {
            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;
            int left = j + 1;
            int right = numsSize - 1;
            while (left < right)
            {
                printf("%d %d\n", left, right);
                long int sum = (long)nums[i] + nums[j] + nums[left] + nums[right] - target;
                printf("sum:%d\n", sum);
                if (sum == 0)
                {
                    if (*returnSize == capacity)
                    {
                        capacity *= 2;
                        res = (int **)realloc(res, sizeof(int *) * capacity);
                        *returnColumnSizes = (int *)realloc(*returnColumnSizes, sizeof(int) * capacity);
                    }
                    res[*returnSize] = (int *)malloc(sizeof(int) * 4);
                    res[*returnSize][0] = nums[i];
                    res[*returnSize][1] = nums[j];
                    res[*returnSize][2] = nums[left];
                    res[*returnSize][3] = nums[right];
                    (*returnColumnSizes)[*returnSize] = 4;
                    (*returnSize)++;
                    while (left < right && nums[left] == nums[left + 1])
                        ++left;
                    while (left < right && nums[right] == nums[right - 1])
                        --right;
                    left++;
                    right--;
                }
                else if (sum > 0)
                    right--;
                else
                    left++;
            }
        }
    }
    return res;
}
// @lc code=end
