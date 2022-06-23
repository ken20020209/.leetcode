/*
 * @lc app=leetcode id=300 lang=c
 *
 * [300] Longest Increasing Subsequence
 */
#include "header\leetcode.h"

// @lc code=start

int lengthOfLIS(int *nums, int numsSize)
{
    int *dp = (int *)calloc(numsSize, sizeof(int));
    int len = 0;
    dp[len] = nums[0];
    int high, low, mid;
    for (int i = 1; i < numsSize; i++)
    {
        if (nums[i] > dp[len])
        {
            len++;
            dp[len] = nums[i];
        }
        else
        {
            if (len < 5)
            {
                //bs
                high = len;
                low = 0;
                while (low < high)
                {
                    mid = low + (high - low) / 2;
                    if (nums[i] == dp[mid])
                    {
                        low = mid;
                        break;
                    }
                    else if (nums[i] > dp[mid])
                    {
                        low = mid + 1;
                    }
                    else
                    {
                        high = mid;
                    }
                }
                dp[low] = nums[i];
            }
            else
            {
                // line search
                for (int j = 0; j <= len; j++)
                {
                    if (nums[i] <= dp[j])
                    {
                        dp[j] = nums[i];
                        break;
                    }
                }
            }
        }
    }
    return len + 1;
}
// @lc code=end
