/*
 * @lc app=leetcode id=713 lang=c
 *
 * [713] Subarray Product Less Than K
 */
#include "header\leetcode.h"

// @lc code=start

int numSubarrayProductLessThanK(int *nums, int numsSize, int k)
{
    if(k<=1)return 0;
    int prod=1;
    int left=0;
    int res=0;
    for(int right=0; right<numsSize; right++)
    {
        prod*=nums[right];
        while (prod>=k)prod/=nums[left++];
        res+=right-left+1; 
    }
    
    return res;
}
// @lc code=end
