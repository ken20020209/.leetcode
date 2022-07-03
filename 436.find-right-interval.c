/*
 * @lc app=leetcode id=436 lang=c
 *
 * [436] Find Right Interval
 */
#include "header\leetcode.h"

// @lc code=start

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(int **a, int **b)
{
    return **a - **b;
}

int *findRightInterval(int **intervals, int intervalsSize, int *intervalsColSize, int *returnSize)
{
    int *res = (int *)malloc(intervalsSize * sizeof(int));
    int *pos = (int *)malloc(intervalsSize * sizeof(int));
    *returnSize = intervalsSize;
    memset(res, -1, intervalsSize * sizeof(int));
    for (int i = 0; i < intervalsSize; i++)
    {
        pos[i] = intervals[i][1];
        intervals[i][1] = i;
    }
    qsort(intervals, intervalsSize, sizeof(int *), cmp);
    for (int i = 0; i < intervalsSize; i++)
    {
        // printf("%d %d pos:%d\n", intervals[i][0], intervals[i][1], pos[intervals[i][1]]);
        int min = -1;
        int high = intervalsSize - 1;
        int low = 0;
        int mid;
        while (low <= high)
        {
            mid = low + (high - low) / 2;
            if (intervals[mid][0] >= pos[intervals[i][1]])
            {
                min = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        if (min != -1)
        {
            res[intervals[i][1]] = intervals[min][1];
        }
    }
    free(pos);
    return res;
}
// @lc code=end
