/*
 * @lc app=leetcode id=16 lang=c
 *
 * [16] 3Sum Closest
 */
#include "header\leetcode.h"

// @lc code=start
#define abs(a) (((a) >= 0) ? (a) : -(a))

int cmp(int *a, int *b)
{
    return *a - *b;
}
int threeSumClosest(int *nums, int numsSize, int target)
{
    qsort(nums, numsSize, sizeof(int), cmp);
    int diff_min = INT_MAX;
    for (int i = 0; i < numsSize; i++)
    {
        int left = i + 1;
        int right = numsSize - 1;
        while (left < right)
        {
            int diff = nums[i] + nums[left] + nums[right] - target;

            if (diff == 0)
            {
                return target;
            }
            else
            {
                if (abs(diff) < abs(diff_min))
                {
                    diff_min = diff;
                }
                if (diff > 0)
                {
                    right--;
                }
                else
                {
                    left++;
                }
            }
        }
    }
    return target + diff_min;
}
// @lc code=end
