/*
 * @lc app=leetcode id=123 lang=c
 *
 * [123] Best Time to Buy and Sell Stock III
 */
#include "header\leetcode.h"

// @lc code=start
// re memo
// int memo[100000][5];
// int helper(int *prices, int pricesSize, int day, int chance)
// {

//     int res1;
//     int res2;
//     if (day == pricesSize)
//         return 0;
//     if (chance == 0)
//         return 0;
//     if (memo[day][chance] != -1)
//         return memo[day][chance];
//     // do nothing
//     res1 = helper(prices, pricesSize, day + 1, chance);
//     // buy or sell
//     if (chance % 2 == 0)
//     {
//         res2 = -prices[day] + helper(prices, pricesSize, day + 1, chance - 1);
//     }
//     else
//     {
//         res2 = prices[day] + helper(prices, pricesSize, day + 1, chance - 1);
//     }
//     return memo[day][chance] = fmax(res1, res2);
// }
// int maxProfit(int *prices, int pricesSize)
// {
//     memset(memo, -1, sizeof(memo));
//     return helper(prices, pricesSize, 0, 4);
// }

// dp
int maxProfit(int *prices, int pricesSize)
{
    int fbuy, fsell, sbuy, ssell;
    fbuy = INT_MAX;
    fsell = 0;
    sbuy = INT_MAX;
    ssell = 0;
    for (int i = 0; i < pricesSize; i++)
    {
        fbuy = fmin(fbuy, prices[i]);
        fsell = fmax(fsell, prices[i] - fbuy);
        sbuy = fmin(sbuy, prices[i] - fsell);
        ssell = fmax(ssell, prices[i] - sbuy);
    }
    return ssell;
}
// @lc code=end
