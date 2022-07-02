/*
 * @lc app=leetcode id=503 lang=c
 *
 * [503] Next Greater Element II
 */
#include "header\leetcode.h"

// @lc code=start

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int *nextGreaterElements(int *nums, int numsSize, int *returnSize)
{
    int *res = (int *)malloc(numsSize * sizeof(int));
    *returnSize = numsSize;
    int stack[numsSize];
    int top = -1;
    for (int j = 0; j < 2; j++)
    {
        for (int i = numsSize - 1; i >= 0; i--)
        {
            while (top != -1 && nums[i] >= stack[top])
            {
                top--;
            }

            if (top == -1)
            {
                res[i] = -1;
            }
            else
            {
                res[i] = stack[top];
            }
            stack[++top] = nums[i];
        }
    }
    return res;
}
// @lc code=end
