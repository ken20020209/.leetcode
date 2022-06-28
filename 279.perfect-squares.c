/*
 * @lc app=leetcode id=279 lang=c
 *
 * [279] Perfect Squares
 */
#include "header\leetcode.h"

// @lc code=start
//dp
int numSquares(int n)
{
    int *dp = (int *)malloc((n + 1) * sizeof(int));
    for(int i=1;i<=n;i++)dp[i]=INT_MAX;
    dp[0]=0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j*j <= i; j++)
        {
            dp[i]=fmin(dp[i],dp[i-j*j]+1);
        }
    }

    return dp[n];
}
// @lc code=end
int main()
{
    int res=numSquares(12);

    return 0;
}