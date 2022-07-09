/*
 * @lc app=leetcode id=673 lang=c
 *
 * [673] Number of Longest Increasing Subsequence
 */
#include "header\leetcode.h"

// @lc code=start
// int C_[2001];
// int L_[2001];
// int len(int *nums, int numsSize)
// {
//     if (numsSize == 0)
//         return 1;
//     if (L_[numsSize] > 0)
//         return L_[numsSize];
//     int max_len = 1;
//     for (int i = 0; i < numsSize; i++)
//     {
//         if (nums[numsSize] > nums[i])
//         {
//             max_len = fmax(max_len, len(nums, i) + 1);
//         }
//     }
//     return L_[numsSize] = max_len;
// }
// int count(int *nums, int numsSize)
// {
//     if (numsSize == 0)
//         return 1;
//     if (C_[numsSize] > 0)
//         return C_[numsSize];
//     int total_count = 0;
//     int max_len = len(nums, numsSize);
//     for (int i = 0; i < numsSize; i++)
//     {
//         if (nums[numsSize] > nums[i] && len(nums, i) == max_len - 1)
//             total_count += count(nums, i);
//     }
//     if (total_count == 0)
//         total_count = 1;
//     return C_[numsSize] = total_count;
// }
// int findNumberOfLIS(int *nums, int numsSize)
// {

//     memset(C_, 0, 2001 * sizeof(int));
//     memset(L_, 0, 2001 * sizeof(int));
//     int max_len = 0;
//     int res = 0;
//     for (int i = 0; i < numsSize; i++)
//     {
//         max_len = fmax(max_len, len(nums, i));
//     }

//     for (int i = 0; i < numsSize; i++)
//     {
//         if (len(nums, i) == max_len)
//             res += count(nums, i);
//     }
//     return res;
// }

int findNumberOfLIS(int *nums, int numsSize)
{
    int c[numsSize];
    int l[numsSize];
    for (int i = 0; i < numsSize; i++)
    {
        c[i] = 1;
        l[i] = 1;
    }
    for (int i = 0; i < numsSize; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j])
            {
                if (l[j] + 1 > l[i])
                {
                    l[i] = l[j] + 1;
                    c[i] = c[j];
                }
                else if (l[j] + 1 == l[i])
                {
                    c[i] += c[j];
                }
            }
        }
    }
    int max_len = 0;

    for (int i = 0; i < numsSize; i++)
        max_len = fmax(max_len, l[i]);
    int res = 0;
    for (int i = 0; i < numsSize; i++)
        if (l[i] == max_len)
            res += c[i];
    return res;
}
// @lc code=end
