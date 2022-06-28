/*
 * @lc app=leetcode id=435 lang=c
 *
 * [435] Non-overlapping Intervals
 */
#include "header\leetcode.h"

// @lc code=start

int cmp(void **a, void **b)
{
    if (**(int **)a == **(int **)b)
        return *((*(int **)a) + 1) - *((*(int **)b) + 1);
    else
        return **(int **)a - **(int **)b;
}
int eraseOverlapIntervals(int **intervals, int intervalsSize, int *intervalsColSize)
{
    int inS = intervalsSize;
    int inC = *intervalsColSize;
    int cnt = 1;
    qsort(intervals, intervalsSize, sizeof(int **), cmp);

    // for (int i = 0; i < inS; i++)
    // {
    //     printf("%d,%d\n", intervals[i][0], intervals[i][1]);
    // }
    int min=intervals[inS-1][0];
    for (int i = inS - 2; i >= 0; i--)
    {
        if(intervals[i][1]<=min)
        {
            cnt++;
            min=intervals[i][0];
        }
    }
    return inS-cnt;
}
// @lc code=end
