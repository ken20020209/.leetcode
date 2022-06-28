/*
 * @lc app=leetcode id=238 lang=c
 *
 * [238] Product of Array Except Self
 */
#include "header\leetcode.h"

// @lc code=start

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *productExceptSelf(int *nums, int numsSize, int *returnSize)
{
    int *res = (int *)malloc(sizeof(int) * numsSize);
    *returnSize = numsSize;
    res[0] = 1;
    for (int i = 1; i < numsSize; i++)
    {
        res[i] = res[i - 1] * nums[i - 1];
    }
    int left = 1;
    for (int i = numsSize - 1; i >= 0; i--)
    {
        res[i] *= left;
        left *= nums[i];
    }
    return res;
}
// @lc code=end
