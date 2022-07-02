/*
 * @lc app=leetcode id=1838 lang=c
 *
 * [1838] Frequency of the Most Frequent Element
 */
#include "header\leetcode.h"

// @lc code=start

int cmp(int *a, int *b)
{
    return *a - *b;
}
int maxFrequency(int *nums, int numsSize, int k)
{
    qsort(nums, numsSize, sizeof(int), cmp);
    long sum = 0;
    int res = 1;
    int j = 0;
    for (int i = 0; i < numsSize; i++)
    {

        sum += nums[i];

        while (sum + k < (long)nums[i] * (i - j + 1))
        {
            sum -= nums[j++];
        }
        res = fmax(res, i - j + 1);
    }

    return res;
}
// @lc code=end
