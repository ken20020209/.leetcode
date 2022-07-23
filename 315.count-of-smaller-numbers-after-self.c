/*
 * @lc app=leetcode id=315 lang=c
 *
 * [315] Count of Smaller Numbers After Self
 */
#include "header\leetcode.h"

// @lc code=start

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// bf
// int *countSmaller(int *nums, int numsSize, int *returnSize)
// {
//     int *res = (int *)malloc(sizeof(int) * numsSize);
//     *returnSize = numsSize;
//     int cnt;
//     for (int i = 0; i < numsSize; i++)
//     {
//         cnt = 0;
//         for (int j = i + 1; j < numsSize; j++)
//         {
//             if (nums[j] < nums[i])
//                 cnt++;
//         }
//         res[i] = cnt;
//     }
//     return res;
// }

// merge sort
// void mergeSort(int *nums, int *res, int *index, int start, int end)
// {
//     if (start >= end)
//         return;
//     int mid = start + (end - start) / 2;
//     mergeSort(nums, res, index, start, mid);
//     mergeSort(nums, res, index, mid + 1, end);
//     int mergenums[end - start + 1];
//     int mergeindex[end - start + 1];
//     int leftpos = start;
//     int rightpos = mid + 1;
//     int mergepos = 0;
//     int cnt = 0;
//     while (leftpos <= mid && rightpos <= end)
//     {
//         if (nums[leftpos] > nums[rightpos])
//         {

//             mergenums[mergepos] = nums[rightpos];
//             mergeindex[mergepos] = index[rightpos];
//             cnt++;
//             mergepos++;
//             rightpos++;
//         }
//         else
//         {
//             mergenums[mergepos] = nums[leftpos];
//             mergeindex[mergepos] = index[leftpos];
//             res[index[leftpos]] += cnt;
//             mergepos++;
//             leftpos++;
//         }
//     }
//     while (leftpos <= mid)
//     {
//         mergenums[mergepos] = nums[leftpos];
//         mergeindex[mergepos] = index[leftpos];
//         res[index[leftpos]] += cnt;
//         mergepos++;
//         leftpos++;
//     }
//     while (rightpos <= end)
//     {
//         mergenums[mergepos] = nums[rightpos];
//         mergeindex[mergepos] = index[rightpos];
//         mergepos++;
//         rightpos++;
//     }
//     mergepos = 0;
//     for (int i = start; i <= end; i++)
//     {
//         nums[i] = mergenums[mergepos];
//         index[i] = mergeindex[mergepos];
//         mergepos++;
//     }
// }
// int *countSmaller(int *nums, int numsSize, int *returnSize)
// {
//     int *res = (int *)calloc(numsSize, sizeof(int));
//     int index[numsSize];
//     for (int i = 0; i < numsSize; i++)
//         index[i] = i;
//     *returnSize = numsSize;
//     mergeSort(nums, res, &index, 0, numsSize - 1);
//     // for (int i = 0; i < numsSize; i++)
//     // {
//     //     printf("%d ", nums[i]);
//     // }
//     // printf("\n");
//     // for (int i = 0; i < numsSize; i++)
//     // {
//     //     printf("%d ", index[i]);
//     // }
//     // printf("\n");
//     return res;
// }

// Binary index tree
int cmp(int *a, int *b)
{
    return *a - *b;
}
int *countSmaller(int *nums, int numsSize, int *returnSize)
{
    int *res = (int *)calloc(numsSize, sizeof(int));
    int buf[numsSize + 1];
    memcpy(buf, nums, numsSize * sizeof(int));
    qsort(buf,numsSize,sizeof(int),cmp);
    int rank[numsSize];
    *returnSize = numsSize;

    // for (int i = 0; i < numsSize; i++)
    // {
    //     printf("%d ", nums[i]);
    // }
    // printf("\n");
    // for (int i = 0; i < numsSize; i++)
    // {
    //     printf("%d ", index[i]);
    // }
    // printf("\n");
    return res;
}
// @lc code=end
