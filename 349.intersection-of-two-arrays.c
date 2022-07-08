/*
 * @lc app=leetcode id=349 lang=c
 *
 * [349] Intersection of Two Arrays
 */
#include "header\leetcode.h"

// @lc code=start

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *intersection(int *nums1, int nums1Size, int *nums2, int nums2Size, int *returnSize)
{
    int map[1001] = {0};
    *returnSize = 0;
    int *res = (int *)malloc(sizeof(int) * 1000);
    for (int i = 0; i < nums1Size; i++)
    {
        map[nums1[i]] = 1;
    }
    for (int i = 0; i < nums2Size; i++)
    {
        if (map[nums2[i]] == 1)
        {
            res[*returnSize] = nums2[i];
            (*returnSize)++;
            map[nums2[i]] = 0;
        }
    }
    return res;
}
// @lc code=end
