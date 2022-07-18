/*
 * @lc app=leetcode id=80 lang=c
 *
 * [80] Remove Duplicates from Sorted Array II
 */
#include "header\leetcode.h"

// @lc code=start

int removeDuplicates(int *nums, int numsSize)
{
    int left = 0;
    int right = 0;
    int cnt = 0;
    int curnum = nums[0];
    while (right < numsSize)
    {
        if (curnum == nums[right])
        {
            right++;
            cnt++;
        }
        else
        {
            if (cnt == 1)
            {
                nums[left] = curnum;
                left++;
            }
            else if (cnt >= 2)
            {
                nums[left] = curnum;
                nums[left + 1] = curnum;
                left += 2;
            }
            cnt = 0;
            curnum = nums[right];
        }
    }
    if (cnt == 1)
    {
        nums[left] = curnum;
        left++;
    }
    else if (cnt >= 2)
    {
        nums[left] = curnum;
        nums[left + 1] = curnum;
        left += 2;
    }
    return left;
}
// @lc code=end
