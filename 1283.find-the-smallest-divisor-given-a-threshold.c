/*
 * @lc app=leetcode id=1283 lang=c
 *
 * [1283] Find the Smallest Divisor Given a Threshold
 */
#include "header\leetcode.h"

// @lc code=start

int sum(int *nums, int size, int div)
{
    int res = 0;
    int temp;
    for (int i = 0; i < size; i++)
    {
        temp = nums[i];
        if (temp % div != 0)
        {
            res++;
        }
        res += temp / div;
    }
    return res;
}
int smallestDivisor(int *nums, int numsSize, int threshold)
{
    int high = 1e6;
    int low = 1;
    int mid;
    int dsum;
    int res;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        dsum = sum(nums, numsSize, mid);
        // printf("mid: %d, dsum: %d\n", mid, dsum);
        if (dsum <= threshold)
        {
            res = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return low;
}
// @lc code=end
