/*
 * @lc app=leetcode id=338 lang=c
 *
 * [338] Counting Bits
 */
#include "header\leetcode.h"

// @lc code=start

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *countBits(int n, int *returnSize)
{
    *returnSize = n + 1;
    int *res = (int *)malloc((n + 1) * sizeof(int));
    res[0] = 0;
    int max = 1;
    int cur = 1;
    for (int i = 1; i < n + 1; i++)
    {
        res[i] = res[i / 2] + i % 2;
    }
    return res;
}
// @lc code=end
