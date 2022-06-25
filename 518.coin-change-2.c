/*
 * @lc app=leetcode id=518 lang=c
 *
 * [518] Coin Change 2
 */
#include "header\leetcode.h"

// @lc code=start

int change(int amount, int *coins, int coinsSize)
{
    if(amount==0)return 1;
    if (amount == 0)
        return 0;
    int *dp = (int *)calloc(amount + 1, sizeof(int));
    dp[0]=1;
    for (int i = 0; i < coinsSize; i++)
    {
        int coin=coins[i];
        for(int j=coin;j<amount+1;j++)
        {
            dp[j]+=dp[j-coin];
        }
    }
    int res = dp[amount];
    // for (int i = 0; i < amount + 1; i++)
    // {
    //     printf("i:%d %d\n", i, dp[i]);
    // }

    free(dp);
    return res;
}
// @lc code=end
