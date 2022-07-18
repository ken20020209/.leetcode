/*
 * @lc app=leetcode id=1658 lang=c
 *
 * [1658] Minimum Operations to Reduce X to Zero
 */
#include "header\leetcode.h"

// @lc code=start

int minOperations(int *nums, int numsSize, int x)
{
    for (int i = 1; i < numsSize; i++)
    {
        nums[i] += nums[i - 1];
    }
    // for (int i = 0; i < numsSize; i++)
    // {
    //     printf(" %d ", nums[i]);
    // }
    // printf("\n");
    int res = -1;
    int left = -1;
    int right = 0;
    while (right < numsSize && left < numsSize)
    {
        int leftval = left == -1 ? 0 : nums[left];
        int rightval = nums[right];
        int val = rightval - leftval;
        val = nums[numsSize - 1] - val - x;
        // printf("left:%dright:%d\n", left, right);
        // printf("    val:%d\n", val);
        if (val > 0)
        {
            right++;
        }
        else if (val < 0)
        {
            left++;
        }
        else
        {
            res = fmax(res, right - left);
            right++;
        }
    }
    res = res == -1 ? -1 : numsSize - res;
    return res;
}
// @lc code=end
