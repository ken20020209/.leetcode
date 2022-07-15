/*
 * @lc app=leetcode id=31 lang=c
 *
 * [31] Next Permutation
 */
#include "header\leetcode.h"

// @lc code=start

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void reverse(int *a, int size)
{
    for (int i = 0; i < size / 2; i++)
    {
        swap(&a[i], &a[size - 1 - i]);
    }
}
void nextPermutation(int *nums, int numsSize)
{
    int i = numsSize - 1;
    while (i - 1 >= 0 && nums[i - 1] >= nums[i])
    {
        i--;
    }
    if (i != 0)
    {

        int j = numsSize - 1;
        while (nums[j] <= nums[i - 1])
        {
            j--;
        }
        swap(&nums[i - 1], &nums[j]);
    }
    reverse(nums + i, numsSize - i);
}
// @lc code=end
