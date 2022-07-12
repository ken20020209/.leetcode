/*
 * @lc app=leetcode id=343 lang=c
 *
 * [343] Integer Break
 */
#include "header\leetcode.h"

// @lc code=start
int dp[60];
int integerBreak(int n)
{
    if (dp[n] != 0)
        return dp[n];
    int ret = 0;
    for (int i = 1; i < n; i++)
    {
        ret = fmax(ret, (n - i) * (i));
        ret = fmax(ret, integerBreak(n - i) * (i));
        ret = fmax(ret, (n - i) * integerBreak(i));
    }
    return dp[n] = ret;
}

// @lc code=end
