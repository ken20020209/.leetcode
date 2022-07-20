/*
 * @lc app=leetcode id=229 lang=c
 *
 * [229] Majority Element II
 */
#include "header\leetcode.h"

// @lc code=start

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *majorityElement(int *nums, int numsSize, int *returnSize)
{
    int cnt1 = 0, cnt2 = 0, win1 = 0, win2 = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] == win1)
            cnt1++;
        else if (nums[i] == win2)
            cnt2++;
        else if (cnt1 == 0)
        {
            win1 = nums[i];
            cnt1 = 1;
        }
        else if (cnt2 == 0)
        {
            win2 = nums[i];
            cnt2 = 1;
        }
        else
        {
            cnt1--;
            cnt2--;
        }
    }
    cnt1 = 0;
    cnt2 = 0;
    *returnSize = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] == win1)
            cnt1++;
        if (nums[i] == win2)
            cnt2++;
    }
    int *ans = (int *)malloc(2 * sizeof(int));
    if (cnt1 > numsSize / 3)
    {
        ans[*returnSize] = win1;
        (*returnSize)++;
    }
    if (win1 != win2 && cnt2 > numsSize / 3)
    {
        ans[*returnSize] = win2;
        (*returnSize)++;
    }
    return ans;
}
// @lc code=end
