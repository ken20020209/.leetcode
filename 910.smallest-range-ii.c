/*
 * @lc app=leetcode id=910 lang=c
 *
 * [910] Smallest Range II
 */
#include "header\leetcode.h"

// @lc code=start

int cmp(int *a, int *b)
{
    return *a - *b;
}
int smallestRangeII(int *nums, int numsSize, int k)
{
    qsort(nums, numsSize, sizeof(int), cmp);
    int min = nums[0];
    int max = nums[numsSize - 1];
    int res = max - min;
    int i;
    for (i = 0; i < numsSize - 1; i++)
    {
        int a = nums[i];
        int b = nums[i + 1];
        max = fmax(nums[numsSize - 1] - k, a + k);
        min = fmin(nums[0] + k, b - k);
        res = fmin(res, max - min);
    }
    return res;
}
// @lc code=end
