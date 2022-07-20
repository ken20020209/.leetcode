/*
 * @lc app=leetcode id=239 lang=c
 *
 * [239] Sliding Window Maximum
 */
#include "header\leetcode.h"

// @lc code=start

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// bf
//  int *maxSlidingWindow(int *nums, int numsSize, int k, int *returnSize)
//  {
//      *returnSize = numsSize - k + 1;
//      int *res = (int *)malloc(*returnSize * sizeof(int));
//      int max;
//      for (int i = 0; i < *returnSize; i++)
//      {
//          max = INT_MIN;
//          for (int j = i; j < i + k; j++)
//          {
//              max = fmax(nums[j], max);
//          }
//          res[i] = max;
//      }
//      return res;
//  }

int *maxSlidingWindow(int *nums, int numsSize, int k, int *returnSize)
{
    *returnSize = numsSize - k + 1;
    int *res = (int *)malloc(*returnSize * sizeof(int));
    int respos = 0;
    int dequeue[numsSize];
    int front = 0;
    int rear = -1;
    int size = 0;
    for (int i = 0; i < numsSize; i++)
    {
        while (size != 0 && dequeue[front] < i - k + 1)
        {
            front++;
            size--;
        }
        while (size != 0 && nums[dequeue[rear]] < nums[i])
        {
            rear--;
            size--;
        }
        dequeue[++rear] = i;
        size++;
        if (i >= k - 1)
        {
            res[respos++] = nums[dequeue[front]];
        }
    }
    return res;
}
// @lc code=end
