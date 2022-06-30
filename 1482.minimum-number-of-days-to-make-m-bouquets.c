/*
 * @lc app=leetcode id=1482 lang=c
 *
 * [1482] Minimum Number of Days to Make m Bouquets
 */
#include "header\leetcode.h"

// @lc code=start

int CanMake(int *arr, int arrsize, int k, int day)
{
    int res = 0;
    int cnt = 0;
    for (int i = 0; i < arrsize; i++)
    {
        if (day >= arr[i])
        {
            cnt++;
            if (cnt >= k)
            {
                res++;
                cnt -= k;
            }
        }
        else
        {
            cnt = 0;
        }
    }
    return res;
}
int cmp(int *a, int *b)
{
    return *a - *b;
}
int minDays(int *bloomDay, int bloomDaySize, int m, int k)
{
    if (bloomDaySize < m * k)
        return -1;
    // int *sortBloomDay = (int *)malloc(bloomDaySize * sizeof(int));
    // memcpy(sortBloomDay, bloomDay, bloomDaySize * sizeof(int));
    // qsort(sortBloomDay, bloomDaySize, sizeof(int), cmp);
    // int high = bloomDaySize - 1;
    int high = 1000000000;
    int low = 0;
    int mid;
    int res = -1;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        //  int bouquet = CanMake(bloomDay, bloomDaySize, k, sortBloomDay[mid]);
        int bouquet = CanMake(bloomDay, bloomDaySize, k, mid);
        // printf("bouquet: %d\n", bouquet);
        // printf("mid: %d\n", mid);
        if (bouquet < m)
        {
            low = mid + 1;
        }
        else
        {
            res = mid;
            high = mid - 1;
        }
    }
    return res;
}
// @lc code=end
