/*
 * @lc app=leetcode id=228 lang=c
 *
 * [228] Summary Ranges
 */
#include "header\leetcode.h"

// @lc code=start

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **summaryRanges(int *nums, int numsSize, int *returnSize)
{
    *returnSize = 0;
    if (numsSize == 0)
        return (NULL);
    int left = 0;
    int right = left;
    int resCapacity = 2;
    char temp[256];
    int len;
    char **res = (char **)malloc(resCapacity * sizeof(char *));
    while (left < numsSize)
    {

        if (right + 1 < numsSize && nums[right] + 1 == nums[right + 1])
        {
            right++;
        }
        else
        {
            if (right == left)
            {
                sprintf(temp, "%d", nums[left]);
            }
            else
            {
                sprintf(temp, "%d->%d", nums[left], nums[right]);
            }
            len = strlen(temp);
            res[*returnSize] = (char *)malloc((len + 1) * sizeof(char));
            memcpy(res[*returnSize], temp, (len + 1) * sizeof(char));
            (*returnSize)++;
            if (*returnSize == resCapacity)
            {
                resCapacity *= 2;
                res = (char **)realloc(res, resCapacity * sizeof(char *));
            }

            right += 1;
            left = right;
        }
    }
    return res;
}
// @lc code=end
