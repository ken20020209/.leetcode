/*
 * @lc app=leetcode id=274 lang=c
 *
 * [274] H-Index
 */
#include "header\leetcode.h"

// @lc code=start

int cmp(int *a, int *b)
{
    return *a - *b;
}
int bshIndex(int *citations, int citationsSize)
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
int hIndex(int *citations, int citationsSize)
{
    qsort(citations, citationsSize, sizeof(int), cmp);
    return bshIndex(citations, citationsSize);
}
// @lc code=end
