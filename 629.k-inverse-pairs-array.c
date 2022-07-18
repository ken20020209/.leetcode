/*
 * @lc app=leetcode id=629 lang=c
 *
 * [629] K Inverse Pairs Array
 */
#include "header\leetcode.h"

// @lc code=start
#define MOD 1000000007
int kInversePairs(int n, int k)
{
    int dp[n + 1][k + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {

            if (j == 0)
            {
                dp[i][j] = 1;
            }
            else
            {
                // for (int k = 0; k <= fmin(j, i - 1); k++)
                // {
                //     dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % MOD;
                // }
                int val = (dp[i - 1][j] - (j - i >= 0 ? dp[i - 1][j - i] : 0)) % MOD;
                dp[i][j] = (dp[i][j - 1] + val) % MOD;
            }
            // for (int i = 0; i <= n; i++)
            // {
            //     for (int j = 0; j <= k; j++)
            //     {
            //         printf("%d ", dp[i][j]);
            //     }
            //     printf("\n");
            // }
            // printf("\n");
        }
    }
    return (dp[n][k] + MOD - (k > 0 ? dp[n][k - 1] : 0)) % MOD;
}
// @lc code=end
