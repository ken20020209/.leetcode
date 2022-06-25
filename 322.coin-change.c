/*
 * @lc app=leetcode id=322 lang=c
 *
 * [322] Coin Change
 */
#include "header\leetcode.h"

// @lc code=start
// it dp
int coinChange(int *coins, int coinsSize, int amount)
{
    if (amount == 0)
        return 0;
    int *dp = (int *)calloc(amount + 1, sizeof(int));

    for (int i = 0; i < coinsSize; i++)
    {
        if (coins[i] < amount + 1)
            dp[coins[i]] = 1;
    }
    for (int i = 0; i < amount + 1; i++)
    {
        if (dp[i] != 0)
        {
            for (int j = 0; j < coinsSize; j++)
            {
                if (i + (long)coins[j] < amount + 1)
                {
                    if (dp[i + coins[j]] == 0)
                    {
                        dp[i + coins[j]] = dp[i] + 1;
                    }
                    else
                    {
                        dp[i + coins[j]] = fmin(dp[i + coins[j]], dp[i] + 1);
                    }
                }
            }
        }
    }
    int res = dp[amount];
    // for (int i = 0; i < amount + 1; i++)
    // {
    //     printf("i:%d %d\n", i, dp[i]);
    // }

    free(dp);
    return res == 0 ? -1 : res;
}

// @lc code=end
