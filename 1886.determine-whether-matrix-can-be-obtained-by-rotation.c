/*
 * @lc app=leetcode id=1886 lang=c
 *
 * [1886] Determine Whether Matrix Can Be Obtained By Rotation
 */
#include "header\leetcode.h"

// @lc code=start

void rotate(int **matrix, int matrixSize, int *matrixColSize)
{
    int temp;
    for (int i = 0; i < matrixSize; i++)
    {
        for (int j = i; j < matrixColSize[i]; j++)
        {
            temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
    for (int i = 0; i < matrixSize; i++)
    {
        for (int j = 0; j < matrixColSize[i] / 2; j++)
        {

            temp = matrix[i][j];
            matrix[i][j] = matrix[i][matrixSize - 1 - j];
            matrix[i][matrixSize - 1 - j] = temp;
        }
    }
}
bool check(int **m1, int **m2, int m, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (m1[i][j] != m2[i][j])
                return false;
        }
    }
    return true;
}
bool findRotation(int **mat, int matSize, int *matColSize, int **target, int targetSize, int *targetColSize)
{
    for (int i = 0; i < 4; i++)
    {
        rotate(mat, matSize, matColSize);
        if (check(mat, target, matSize, *matColSize))
            return true;
    }
    return false;
}
// @lc code=end
