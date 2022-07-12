/*
 * @lc app=leetcode id=215 lang=c
 *
 * [215] Kth Largest Element in an Array
 */
#include "header\leetcode.h"

// @lc code=start

void swap(int *i, int *j)
{
    int temp = *i;
    *i = *j;
    *j = temp;
}
int partition(int *a, int lo, int hi)
{

    int i = lo + 1;
    int j = hi;
    while (true)
    {
        while (i < hi && a[i] < a[lo])
            i++;
        while (j > lo && a[lo] < a[j])
            j--;
        if (i >= j)
        {
            break;
        }
        swap(&a[i], &a[j]);
        i++;
        j--;
    }
    swap(&a[lo], &a[j]);
    return j;
}
void shuffle(int *arr, int arrSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        swap(&arr[i], &arr[rand() % arrSize]);
    }
}
int findKthLargest(int *nums, int numsSize, int k)
{
    shuffle(nums, numsSize);
    k = numsSize - k;
    int lo = 0;
    int hi = numsSize - 1;
    while (lo < hi)
    {
        int j = partition(nums, lo, hi);
        if (j < k)
        {
            lo = j + 1;
        }
        else if (j > k)
        {
            hi = j - 1;
        }
        else
        {
            break;
        }
    }
    return nums[k];
}
// @lc code=end
