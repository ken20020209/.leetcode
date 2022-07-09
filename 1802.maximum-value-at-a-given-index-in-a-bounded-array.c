/*
 * @lc app=leetcode id=1802 lang=c
 *
 * [1802] Maximum Value at a Given Index in a Bounded Array
 */
#include "header\leetcode.h"

// @lc code=start

long int sum(long int a)
{
    return a * (a + 1) / 2;
}
long int arrsum(long int a, int n, int index)
{
    if (a == 0)
        return n;
    int left = a - (index + 1);
    int one = 0;
    if (left < 0)
    {
        one += -left;
        left = 0;
    }
    int right = a - (n - index);
    if (right < 0)
    {
        one += -right;
        right = 0;
    }
    long int ret;
    // printf("left: %d, right: %d\n", left, right);
    ret = sum(a) - sum(left) + sum(a) - sum(right) - a;
    return ret + one;
}
int maxValue(int n, int index, int maxSum)
{
    int res = 0;
    int high = 1e9;
    int low = 0;
    int mid;
    while (low <= high)
    {
        mid = low + (high - low) / 2;

        long int totalsum = arrsum(mid, n, index);
        // printf("mid:%d totalsum:%d\n", mid, totalsum);
        if (totalsum <= maxSum)
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
