/*
 * @lc app=leetcode id=15 lang=c
 *
 * [15] 3Sum
 */
#include "header\leetcode.h"

// @lc code=start

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmp(void *a, void *b)
{
    return *(int *)a - *(int *)b;
}
int **threeSum(int *nums, int numsSize, int *returnSize, int **returnColumnSizes)
{

    int left = 0;
    int right = 0;
    int rets = numsSize * numsSize;
    int **res = (int **)malloc(rets * sizeof(int *));
    *returnSize = 0;
    *returnColumnSizes = (int *)malloc(rets * sizeof(int));
    qsort(nums, numsSize, sizeof(int), cmp);

    for (int i = 0; i < numsSize; i++)
    {
        if (i && nums[i] == nums[i - 1])
            continue;
        left = i + 1;
        right = numsSize - 1;
        while (left < right)
        {
            if (nums[i] + nums[left] + nums[right] > 0)
            {
                right--;
            }
            else if (nums[i] + nums[left] + nums[right] < 0)
            {
                left++;
            }
            else
            {
                res[*returnSize] = (int *)malloc(3 * sizeof(int));
                (*returnColumnSizes)[*returnSize] = 3;
                res[*returnSize][0] = nums[i];
                res[*returnSize][1] = nums[left];
                res[*returnSize][2] = nums[right];
                (*returnSize)++;
                while (left < right && nums[left] == nums[left + 1])
                    left++;
                while (left < right && nums[right] == nums[right - 1])
                    right--;
                left++;
                right--;
            }
        }
    }
    res=(int**)realloc(res, sizeof(int*)*(*returnSize));
    *returnColumnSizes=(int*)realloc(*returnColumnSizes, sizeof(int)*(*returnSize));
    return res;
}
// @lc code=end
int main()
{
}
