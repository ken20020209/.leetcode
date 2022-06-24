/*
 * @lc app=leetcode id=896 lang=c
 *
 * [896] Monotonic Array
 */
#include "header\leetcode.h"

// @lc code=start

bool isMonotonic(int *nums, int numsSize)
{
    if (numsSize <= 2)
        return true;
    int state = 0;
    int i;
    int temp;
    for (i = 1; i < numsSize; i++)
    {
        temp = nums[i] - nums[i - 1];
        if(temp!=0)
        {
            state =temp;
            break;
        }
    }
    if(temp>0)
    {
        for (i=i+1; i < numsSize; i++)
        {
            if(nums[i]-nums[i-1]<0)return false;
        }
        
    }
    else
    {
        for (i=i+1; i < numsSize; i++)
        {
            if(nums[i]-nums[i-1]>0)return false;
        }
    }
    // for (i=i+1; i < numsSize; i++)
    // {
    //      temp = nums[i] - nums[i - 1];
    //     if (temp == 0)
    //     {
    //         continue;
    //     }
    //     else if (temp < 0)
    //     {
    //         if (state > 0)
    //         {
    //             return false;
    //         }
    //     }
    //     else
    //     {
    //         if (state < 0)
    //         {
    //             return false;
    //         }
    //     }
    // }
    return true;
}
// @lc code=end
