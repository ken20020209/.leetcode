/*
 * @lc app=leetcode id=275 lang=c
 *
 * [275] H-Index II
 */
#include "header\leetcode.h"

// @lc code=start

int hIndex(int *citations, int citationsSize)
{
    int high = citationsSize - 1;
    int low = 0;
    int mid;
    while (low < high)
    {
        mid = low + (high - low) / 2;
        if (citations[mid] == citationsSize - mid)
        {
            low = mid;
            break;
        }
        else if (citations[mid] > citationsSize - mid)
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    if (citations[low] == 0)
        low++;
    return citationsSize - low;
}
// @lc code=end
