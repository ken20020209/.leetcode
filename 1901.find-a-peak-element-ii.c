/*
 * @lc app=leetcode id=1901 lang=c
 *
 * [1901] Find a Peak Element II
 */
#include "header\leetcode.h"

// @lc code=start

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *findPeakGrid(int **mat, int matSize, int *matColSize, int *returnSize)
{
    int m = matSize;
    int n = *matColSize;
    *returnSize = 2;
    int *res = (int *)malloc(2 * sizeof(int));
    int startRow = 0;
    int endRow = m - 1;
    int midRow;
    while (startRow <= endRow)
    {
        midRow = startRow + (endRow - startRow) / 2;
        int maxCol = 0;
        for (int i = 1; i < n; i++)
        {
            if (mat[midRow][i] > mat[midRow][maxCol])
            {
                maxCol = i;
            }
        }
        int isRightBig = midRow + 1 <= endRow ? mat[midRow][maxCol] < mat[midRow + 1][maxCol] : false;
        int isLeftBig = midRow - 1 >= startRow ? mat[midRow][maxCol] < mat[midRow - 1][maxCol] : false;

        if (!isRightBig && !isLeftBig)
        {
            res[0] = midRow;
            res[1] = maxCol;
            break;
        }
        else if (isRightBig)
        {
            startRow = midRow + 1;
        }
        else
        {
            endRow = midRow - 1;
        }
    }
    return res;
}
// @lc code=end
