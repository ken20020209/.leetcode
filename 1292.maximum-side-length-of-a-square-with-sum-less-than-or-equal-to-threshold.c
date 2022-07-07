/*
 * @lc app=leetcode id=1292 lang=c
 *
 * [1292] Maximum Side Length of a Square with Sum Less than or Equal to Threshold
 */
#include "header\leetcode.h"

// @lc code=start
bool check(int **preSum, int m, int n, int size, int threshold)
{
    for (int i = size; i < m + 1; i++)
    {
        for (int j = size; j < n + 1; j++)
        {
            int sum = preSum[i][j] - preSum[i][j - size] - preSum[i - size][j] + preSum[i - size][j - size];
            if (sum <= threshold)
            {
                return true;
            }
        }
    }
    return false;
}
int maxSideLength(int **mat, int matSize, int *matColSize, int threshold)
{
    // printf("\n");
    int m = matSize;
    int n = *matColSize;
    int high = fmin(m, n);
    int low = 0;
    int mid;
    int res = 0;
    int **preSum = (int **)malloc((m + 1) * sizeof(int *));
    for (int i = 0; i < m + 1; i++)
        preSum[i] = calloc(n + 1, sizeof(int));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            preSum[i + 1][j + 1] = preSum[i][j + 1] + preSum[i + 1][j] - preSum[i][j] + mat[i][j];
        }
    }
    // for (int i = 0; i < m + 1; i++)
    // {
    //     for (int j = 0; j < n + 1; j++)
    //     {
    //         printf("%-5d", preSum[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("\n");
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (check(preSum, m, n, mid, threshold))
        {
            res = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    for (int i = 0; i < m + 1; i++)
        free(preSum[i]);
    free(preSum);
    return res;
}
// @lc code=end
