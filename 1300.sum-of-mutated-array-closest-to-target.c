/*
 * @lc app=leetcode id=1300 lang=c
 *
 * [1300] Sum of Mutated Array Closest to Target
 */
#include "header\leetcode.h"

// @lc code=start
int abs(int a)
{
    return a < 0 ? -a : a;
}
int cmp(int *a, int *b)
{
    return *a - *b;
}
long int sum(int *arr, int arrSize, int change)
{
    long int sum = 0;
    int i;
    for (i = 0; i < arrSize; i++)
    {
        if (arr[i] >= change)
            break;
        else
            sum += arr[i];
    }
    sum += (arrSize - i) * change;
    return sum;
}
int findBestValue(int *arr, int arrSize, int target)
{
    qsort(arr, arrSize, sizeof(int), cmp);
    int high = 1e5;
    int low = 0;
    int mid;
    int res = 0;
    if (sum(arr, arrSize, INT_MAX) < target)
        return arr[arrSize - 1];
    while (low < high)
    {
        mid = low + (high - low) / 2;
        long int val = sum(arr, arrSize, mid);
        val = val - target;
        if (val >= 0)
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }

    if (abs(sum(arr, arrSize, low - 1) - target) <= abs(sum(arr, arrSize, low) - target))
    {
        res = low - 1;
    }
    else
        res = low;
    return res;
}
// @lc code=end
