/*
 * @lc app=leetcode id=1818 lang=c
 *
 * [1818] Minimum Absolute Sum Difference
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
int bs(int *arr, int size, int target)
{
    int low = 0;
    int high = size - 1;
    int mid;
    while (low < high)
    {
        mid = low + (high - low) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] > target)
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    if (low > 0)
    {
        if (abs(target - arr[low]) > abs(target - arr[low - 1]))
        {
            return low - 1;
        }
    }
    return low;
}
int minAbsoluteSumDiff(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
    long int sum = 0;
    int n = nums1Size;
    long int res;
    int *sortnums1 = (int *)malloc(nums1Size * sizeof(int));
    memcpy(sortnums1, nums1, nums1Size * sizeof(int));
    qsort(sortnums1, nums1Size, sizeof(int), cmp);
    // for (int i = 0; i < n; i++)
    //     printf("%d  ", sortnums1[i]);
    for (int i = 0; i < n; i++)
        sum += abs(nums1[i] - nums2[i]);
    res = sum;
    for (int i = 0; i < n; i++)
    {
        int j = bs(sortnums1, n, nums2[i]);
        long int temp = sum - abs(nums1[i] - nums2[i]) + abs(sortnums1[j] - nums2[i]);
        res = fmin(res, temp);
    }
    free(sortnums1);
    return res % ((long int)pow(10, 9) + 7);
}
// @lc code=end
