/*
 * @lc app=leetcode id=153 lang=c
 *
 * [153] Find Minimum in Rotated Sorted Array
 */
#include "header\leetcode.h"

// @lc code=start


int findMin(int* nums, int numsSize)
{
    int low=0;
    int high=numsSize-1;
    int mid;
    int left=numsSize-1;
    while (low<high) 
    {
        mid=low+(high-low)/2;
        if (nums[left]<nums[mid])
        {
            low=mid+1;
        }
        else
        {
            high=mid;
        }
    }
    return nums[low];
}
// @lc code=end

