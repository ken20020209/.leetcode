/*
 * @lc app=leetcode id=287 lang=c
 *
 * [287] Find the Duplicate Number
 */
#include "header\leetcode.h"

// @lc code=start

// BF TLE
//  int findDuplicate(int* nums, int numsSize)
//  {
//      for(int i = 0; i < numsSize; i++)
//      {
//          for(int j = i+1; j < numsSize; j++)
//          {
//              if(nums[i]==nums[j])
//              {
//                  return nums[i];
//              }
//          }
//      }
//      return -1;
//  }

int findDuplicate(int *nums, int numsSize)
{
    int slow=nums[0];
    int fast=nums[nums[0]];
    while (slow!=fast)
    {
        slow=nums[slow];
        fast=nums[nums[fast]];
    }
    fast=0;
    while (slow!=fast)
    {
        slow=nums[slow];
        fast=nums[fast];
    }
    return fast;
}
// @lc code=end
