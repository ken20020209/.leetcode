/*
 * @lc app=leetcode id=540 lang=c
 *
 * [540] Single Element in a Sorted Array
 */
#include "header\leetcode.h"

// @lc code=start

int singleNonDuplicate(int *nums, int numsSize)
{
    int high = numsSize - 1;
    int low = 0;
    int mid;
    while (low < high)
    {
        mid = low + (high - low) / 2;
        printf("mid:%d\n ", mid);
        if ((mid % 2 == 1 && nums[mid] == nums[mid - 1]) || (mid % 2 == 0 && nums[mid] == nums[mid + 1]))
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }
    // printf("%d:%d", low, nums[low]);
    return nums[low];
}
// @lc code=end
