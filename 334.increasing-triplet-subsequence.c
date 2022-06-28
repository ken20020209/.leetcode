/*
 * @lc app=leetcode id=334 lang=c
 *
 * [334] Increasing Triplet Subsequence
 */
#include "header\leetcode.h"

// @lc code=start

bool increasingTriplet(int *nums, int numsSize)
{
    // i<j<k && nums[i]<nums[j]<nums[k]
    int j, k;
    j = INT_MAX;
    k = INT_MAX;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] <= j)
            j = nums[i];
        else if (nums[i] <= k)
            k = nums[i];
        else
            return true;
    }
    return false;
}
// @lc code=end
