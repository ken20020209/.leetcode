/*
 * @lc app=leetcode id=875 lang=c
 *
 * [875] Koko Eating Bananas
 */
#include "header\leetcode.h"

// @lc code=start
long int eatbanaT(int *arr, int size, int speed)
{
    long int ret = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] % speed != 0)
            ret++;
        ret += arr[i] / speed;
    }
    return ret;
}
int minEatingSpeed(int *piles, int pilesSize, int h)
{
    int high = 0;
    int low = 1;
    for (int i = 0; i < pilesSize; i++)
        high = fmax(high, piles[i]);
    int mid;
    int res = -1;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (eatbanaT(piles, pilesSize, mid) <= h)
        {
            res = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return res;
}
// @lc code=end
