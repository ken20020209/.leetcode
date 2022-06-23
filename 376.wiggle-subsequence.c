/*
 * @lc app=leetcode id=376 lang=c
 *
 * [376] Wiggle Subsequence
 */
#include "header\leetcode.h"

// @lc code=start

//O(n) time o(n) space
int wiggleMaxLength(int* nums, int numsSize)
{
    int *dp= (int *)calloc(numsSize, sizeof(int));
    int state= 0;
    int len=0;
    dp[0]=nums[0];
    for(int i=1; i<numsSize; i++)
    {
        if(nums[i]==dp[len])
        {
            continue;
        }
        else if(nums[i]>dp[len])
        {
            if(state==1||state==0)
            {
                len++;
                dp[len]=nums[i];
                state=-1;
            }
            else
            {
                dp[len]=nums[i];
            }
        }
        else
        {
            if(state==-1||state==0)
            {
                len++;
                dp[len]=nums[i];
                state=1;
            }
            else
            {
                dp[len]=nums[i];
            }
        }
    }
    free(dp);
    return len+1;
}
// @lc code=end

