/*
 * @lc app=leetcode id=1498 lang=c
 *
 * [1498] Number of Subsequences That Satisfy the Given Sum Condition
 */
#include "header\leetcode.h"

// @lc code=start
int mod = 1e9 + 7;
int cmp(int *a, int *b)
{
    return *a - *b;
}
int numSubseq(int *nums, int numsSize, int target)
{
    qsort(nums, numsSize, sizeof(int), cmp);
    int res = 0;
    int pow[numsSize];
    int left = 0;
    int right = numsSize - 1;
    pow[0] = 1;
    for (int i = 1; i < numsSize; i++)
    {
        pow[i] = (pow[i - 1] * 2) % mod;
    }
    while (left <= right)
    {
        if (nums[left] + nums[right] > target)
        {
            right--;
        }
        else
        {
            res = (res + pow[right - left]) % mod;
            left++;
        }
    }

    return res;
}
// @lc code=end
