/*
 * @lc app=leetcode id=89 lang=c
 *
 * [89] Gray Code
 */
#include "header\leetcode.h"

// @lc code=start

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int *grayCode(int n, int *returnSize)
{
    *returnSize = 1 << n;
    int *res = (int *)malloc(*returnSize * sizeof(int));
    for (int i = 0; i < *returnSize; i++)
    {
        res[i] = i ^ i >> 1;
    }
    return res;
}
// @lc code=end
