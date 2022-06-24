/*
 * @lc app=leetcode id=658 lang=c
 *
 * [658] Find K Closest Elements
 */
#include "header\leetcode.h"

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findClosestElements(int* arr, int arrSize, int k, int x, int* returnSize)
{
    int low=0;
    int high=arrSize-k;
    int mid;
    *returnSize=k;
    while (low<high)
    {
        mid=low+(high-low)/2;
        if(x-arr[mid]>arr[mid+k]-x)
        {
            low=mid+1;
        }
        else
        {
            high=mid;
        }
    }
    int *res=(int*)malloc(k*sizeof(int));
    memcpy(res,arr+low,k*sizeof(int));
    return res;
}
// @lc code=end

