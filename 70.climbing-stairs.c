/*
 * @lc app=leetcode id=70 lang=c
 *
 * [70] Climbing Stairs
 */
#include "header\common.h"
// @lc code=start


int climbStairs(int n)
{
    int dp[46];
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}
// @lc code=end

