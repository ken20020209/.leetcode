/*
 * @lc app=leetcode id=41 lang=c
 *
 * [41] First Missing Positive
 */
#include "header\leetcode.h"

// @lc code=start
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int firstMissingPositive(int *nums, int numsSize)
{
    for (int i = 0; i < numsSize; i++)
    {
        while (nums[i] > 0 && nums[i] < numsSize && nums[nums[i] - 1] != nums[i])
        {
            swap(&nums[i], &nums[nums[i] - 1]);
        }
    }
    int i;
    for (i = 0; i < numsSize; i++)
    {
        if (nums[i] != i + 1)
            return i + 1;
    }
    return i + 1;
}
// @lc code=end
