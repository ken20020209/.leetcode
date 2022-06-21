/*
 * @lc app=leetcode id=33 lang=c
 *
 * [33] Search in Rotated Sorted Array
 */
#include "header\common.h"
// @lc code=start

int line_search(int* nums, int numsSize, int target)
{
    int temp=numsSize/2;
    for(int i = 0; i < temp; i++)
    {
        if(nums[i] == target)return i;
        if(nums[numsSize-1-i] == target)return numsSize-1-i;
    }
    if(numsSize %2==1)
    {
        if (nums[temp]== target)
        {
            return temp;
        }
        
    }
    return -1;
}
int b_search(int* nums, int numsSize, int target)
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
            high=mid-1;
        }
    }
    //printf("low=%d\n", low);

    if (target>nums[left])
    {
        high=low;
        low=0;
    }
    else
    {
        high=left;
    }

    //printf("high=%d\n", high);
    //printf("low=%d\n", low);
    while (low<=high) 
    {
        mid=low+(high-low)/2;

        if(nums[mid]==target)
        {
            return mid;
        }
        else if (target>nums[mid])
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    return -1;
}
int search(int* nums, int numsSize, int target)
{
    //return line_search(nums, numsSize, target);
    return b_search(nums, numsSize, target);   
}
// @lc code=end

