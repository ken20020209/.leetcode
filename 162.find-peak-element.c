/*
 * @lc app=leetcode id=162 lang=c
 *
 * [162] Find Peak Element
 */
#include "header\leetcode.h"

// @lc code=start


int findPeakElement(int* nums, int numsSize)
{
    int high=numsSize-1;
    int low=0;
    int mid;
    while(low<high)
    {
        mid=(high+low)/2;
        if(nums[mid]>nums[mid+1])
        {
            high=mid;
        }
        else
        {
            low=mid+1;
        }

    }
    return low;
}
// @lc code=end

