/*
 * @lc app=leetcode id=1648 lang=c
 *
 * [1648] Sell Diminishing-Valued Colored Balls
 */
#include "header\leetcode.h"

// @lc code=start

int cmp(int *a, int *b)
{
    return *b - *a;
}
int maxProfit(int *inventory, int inventorySize, int orders)
{
    qsort(inventory, inventorySize, sizeof(int), cmp);
    int mod = 1e9 + 7;
    int res = 0;
    int cur = inventory[0];
    int i = 0;
    while (orders)
    {
        while (i < inventorySize && inventory[i] == cur)
            i++;
        long next = i == inventorySize ? 0 : inventory[i];
        long h = cur - next;
        long cnt = fmin(orders, i * h);
        long r = 0;
        if (orders < i * h)
        {
            h = orders / i;
            r = orders % i;
        }
        long val = cur - h;
        res = (res + (cur + val + 1) * h / 2 * i + val * r) % mod;
        orders -= cnt;
        cur = next;
    }
    return res;
}
// @lc code=end
