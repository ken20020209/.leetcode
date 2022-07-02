/*
 * @lc app=leetcode id=1552 lang=c
 *
 * [1552] Magnetic Force Between Two Balls
 */
#include "header\leetcode.h"

// @lc code=start
int cmp(int *a, int *b)
{
    return *a - *b;
}
bool candistr(int *arr, int size, int dist, int balls)
{
    int pos = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] >= pos)
        {
            pos = arr[i] + dist;
            balls--;
            if (balls == 0)
            {
                return true;
            }
        }
    }
    return false;
}
int maxDistance(int *position, int positionSize, int m)
{
    int high = 0;
    int low = 0;
    int res = -1;
    int mid;
    qsort(position, positionSize, sizeof(int), cmp);
    for (int i = 0; i < positionSize; i++)
        high = fmax(high, position[i]);
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (candistr(position, positionSize, mid, m) == true)
        {
            res = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return res;
}
// @lc code=end
