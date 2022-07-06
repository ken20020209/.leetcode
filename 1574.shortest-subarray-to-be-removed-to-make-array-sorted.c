/*
 * @lc app=leetcode id=1574 lang=c
 *
 * [1574] Shortest Subarray to be Removed to Make Array Sorted
 */
#include "header\leetcode.h"

// @lc code=start

int findLengthOfShortestSubarray(int *arr, int arrSize)
{
    int left = 0;
    int right = arrSize - 1;
    while (left + 1 < arrSize && arr[left] <= arr[left + 1])
    {
        left++;
    }
    if (left == arrSize - 1)
        return 0;
    while (right - 1 >= 0 && arr[right - 1] <= arr[right])
    {
        right--;
    }
    // printf("left: %d, right: %d\n", left, right);
    int res = fmin(arrSize - 1 - left, right);
    int i = 0;
    int j = right;
    while (i <= left && j < arrSize)
    {
        if (arr[j] >= arr[i])
        {
            res = fmin(res, j - i - 1);
            i++;
        }
        else
        {
            j++;
        }
    }
    return res;
}
// @lc code=end
