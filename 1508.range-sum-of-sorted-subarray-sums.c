/*
 * @lc app=leetcode id=1508 lang=c
 *
 * [1508] Range Sum of Sorted Subarray Sums
 */
#include "header\leetcode.h"

// @lc code=start
int cmp(int *a, int *b)
{
    return *a - *b;
}
int rangeSum(int *nums, int numsSize, int n, int left, int right)
{
    int sum[2000000];
    int size = 0;
    int mod = 1e9 + 7;
    for (int i = 0; i < numsSize; i++)
    {
        int cnt = 0;
        for (int j = i; j < numsSize; j++)
        {
            cnt += nums[j];
            sum[size++] = cnt;
        }
    }
    qsort(sum, size, sizeof(int), cmp);
    long res = 0;
    for (int i = left - 1; i < right; i++)
    {
        res += sum[i];
    }
    return res % mod;
}
// @lc code=end
