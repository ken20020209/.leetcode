/*
 * @lc app=leetcode id=53 lang=c
 *
 * [53] Maximum Subarray
 */

// @lc code=start



#define max(a,b) a>b?a:b

int maxSubArray(int* nums, int numsSize) //dp solution 
{
    //int *dp=malloc(numsSize*sizeof(int));
    int cur;
    int max;
    cur=nums[0];
    max=cur;
    for(int i=1;i<numsSize;i++)
    {
        cur=nums[i]+(cur>0?cur:0);
        max=max(max,cur);
    }
    return max;
}

// @lc code=end

