/*
 * @lc app=leetcode id=1630 lang=c
 *
 * [1630] Arithmetic Subarrays
 */
#include "header\leetcode.h"

// @lc code=start

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(int *a, int *b)
{
    return *a - *b;
}
bool *checkArithmeticSubarrays(int *nums, int numsSize, int *l, int lSize, int *r, int rSize, int *returnSize)
{
    int n = numsSize;
    int m = lSize;
    *returnSize = m;
    int *temp = (int *)malloc(n * sizeof(int));
    bool *res = (bool *)malloc(*returnSize * sizeof(bool));
    memset(res, 1, *returnSize * sizeof(bool));
    for (int i = 0; i < m; i++)
    {
        // printf("i:%d\n", i);
        int size = r[i] - l[i] + 1;
        memcpy(temp, nums + l[i], size * sizeof(int));
        qsort(temp, size, sizeof(int), cmp);
        for (int j = 2; j < size; j++)
        {
            if (temp[j] - temp[j - 1] != temp[j - 1] - temp[j - 2])
            {
                res[i] = false;
                break;
            }
        }
    }
    free(temp);
    return res;
}
// @lc code=end
