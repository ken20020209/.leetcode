/*
 * @lc app=leetcode id=268 lang=c
 *
 * [268] Missing Number
 */
#include "header\leetcode.h"

// @lc code=start

// sum=n(n+1)/2;
// sum - sum(nums) =miss numsber
int missingNumber(int *nums, int numsSize)
{
    int res = (numsSize * (numsSize + 1)) / 2;
    for (int i = 0; i < numsSize; i++)
        res -= nums[i];
    return res;
}
// @lc code=end
