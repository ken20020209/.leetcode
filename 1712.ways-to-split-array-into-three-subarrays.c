/*
 * @lc app=leetcode id=1712 lang=c
 *
 * [1712] Ways to Split Array Into Three Subarrays
 */
#include "header\leetcode.h"

// @lc code=start

int sum(int *arr, int start, int end)
{
    return arr[end] - (start == 0 ? 0 : arr[start - 1]);
}
int helper(int *arr, int size, int index, int searchLeft)
{
    int mid;
    int res = -1;
    int leftval, midval, rightval;
    int high = size - 2;
    int low = index;
    leftval = sum(arr, 0, index - 1);
    while (low <= high)
    {

        mid = low + (high - low) / 2;
        midval = sum(arr, index, mid);
        rightval = sum(arr, mid + 1, size - 1);
        if (leftval <= midval && midval <= rightval)
        {
            res = mid;
            if (searchLeft)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else if (leftval > midval)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return res;
}
int waysToSplit(int *nums, int numsSize)
{
    int res = 0;
    int mod = 1e9 + 7;
    for (int i = 1; i < numsSize; i++)
    {
        nums[i] += nums[i - 1];
    }
    for (int i = 1; i <= numsSize - 2; i++)
    {
        if (sum(nums, 0, i - 1) > sum(nums, i, numsSize - 1))
            break;

        int left = helper(nums, numsSize, i, 1);
        int right = helper(nums, numsSize, i, 0);
        // printf("left:%d right:%d\n", left, right);
        if (left == -1 || right == -1)
            continue;
        res = (res + right - left + 1) % mod;
    }
    return res;
}
// @lc code=end
