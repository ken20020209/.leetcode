/*
 * @lc app=leetcode id=611 lang=c
 *
 * [611] Valid Triangle Number
 */
#include "header\leetcode.h"

// @lc code=start

int cmp(int *a, int *b)
{
    return *a - *b;
}
int triangleNumber(int *nums, int numsSize)
{
    int res = 0;
    qsort(nums, numsSize, sizeof(int), cmp);
    // for (int i = 0; i < numsSize; i++)
    // {
    //     for (int j = i + 1; j < numsSize; j++)
    //     {
    //         for (int k = j + 1; k < numsSize; k++)
    //         {
    //             if (nums[i] + nums[j] > nums[k])
    //                 res++;
    //         }
    //     }
    // }
    for (int left = 0; left < numsSize - 2; left++)
    {
        int right = left + 2;
        for (int mid = left + 1; mid < numsSize - 1 && nums[left] != 0; mid++)
        {
            while (right < numsSize && nums[left] + nums[mid] > nums[right])
            {
                right++;
            }
            // printf("r:%d mid:%d\n",right,mid);
            res = res + right - mid - 1;
        }
    }

    return res;
}
// @lc code=end
