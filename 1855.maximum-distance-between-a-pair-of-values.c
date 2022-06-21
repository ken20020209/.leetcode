/*
 * @lc app=leetcode id=1855 lang=c
 *
 * [1855] Maximum Distance Between a Pair of Values
 */
#include "header\common.h"
// @lc code=start
#define max(a,b) ((((a)>(b))?(a):b))
int b_search(int *a,int size,int target)
{
    int low=0;
    int high=size-1;
    int mid;
    while (low<=high) 
    {
        mid = low+(high-low)/2;
        if (a[mid]<=target) 
        {
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
        
    }
    return low;
}
int bmaxDistance(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
    int max=0;
    for (int i = nums2Size-1; i >= 0; i--)
    {
        int temp=b_search(nums1,nums1Size,nums2[i]);
        //printf("%d=%d\n",nums2[i],temp);
        if (temp!=nums1Size)
        {
            temp=i-temp;
            if(temp>max)
            {
                max=temp;
            }
        }
    }
    return max;
}

int maxDistance(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
    int i = 0, j = 0;
    int max_dist = 0;
    for (i = 0; i < nums1Size; i++) {
        if (j < i) {
            j = i;
        }
        while (j < nums2Size && nums1[i] <= nums2[j]) {
            j++;
        }
        // printf("i %d j %d\n", i, j);
        if (max_dist < j-i-1) {
            max_dist = j-i-1;
        }
    }
    return max_dist;
}
// @lc code=end

