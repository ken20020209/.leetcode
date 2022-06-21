/*
 * @lc app=leetcode id=198 lang=c
 *
 * [198] House Robber
 */
#include "header\common.h"
// @lc code=start
#define max(a,b) ((((a)>(b))?(a):b))

int rob(int* nums, int numsSize)
{
    if (numsSize == 1)return nums[0];
    
    int dp[numsSize];
    memset(dp, 0, numsSize*sizeof(int));
    dp[0]=nums[0];
    dp[1]=max(nums[0],nums[1]);
    for (int i = 2; i < numsSize; i++)
    {
        dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
    }
    return max(dp[numsSize-1],dp[numsSize-2]);
}
// @lc code=end

