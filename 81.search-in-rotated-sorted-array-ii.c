/*
 * @lc app=leetcode id=81 lang=c
 *
 * [81] Search in Rotated Sorted Array II
 */
#include "header\leetcode.h"

// @lc code=start
// line search
// bool search(int *nums, int numsSize, int target)
// {
//     for (int i = 0; i < numsSize; i++)
//     {
//         if (nums[i] == target)
//             return true;
//     }
//     return false;
// }
int b_search(int *nums, int numsSize, int target)
{
    int l = 0;
    int r = numsSize - 1;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (nums[mid] == target)
            return true;
        // with duplicates we can have this contdition, just update left & right
        if ((nums[l] == nums[mid]) && (nums[r] == nums[mid]))
        {
            l++;
            r--;
        }
        // first half
        // first half is in order
        else if (nums[l] <= nums[mid])
        {
            // target is in first  half
            if ((nums[l] <= target) && (nums[mid] > target))
                r = mid - 1;
            else
                l = mid + 1;
        }
        // second half
        // second half is order
        // target is in second half
        else
        {
            if ((nums[mid] < target) && (nums[r] >= target))
                l = mid + 1;
            else
                r = mid - 1;
        }
    }
    return false;
}
bool search(int *nums, int numsSize, int target)
{
    return b_search(nums, numsSize, target);
}
// @lc code=end
