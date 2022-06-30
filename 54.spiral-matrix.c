/*
 * @lc app=leetcode id=54 lang=c
 *
 * [54] Spiral Matrix
 */
#include "header\leetcode.h"

// @lc code=start

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void dfs(int **g, int max_x, int max_y, int x, int y, int *res, int dir)
{
    if (x < 0 || y < 0 || x >= max_x || y >= max_y)
        return;
    if (g[x][y] == -10000)
        return;
    *res = g[x][y];
    g[x][y] = -10000;
    res++;
    if (dir == 3)
        dfs(g, max_x, max_y, x - 1, y, res, 3);
    dfs(g, max_x, max_y, x, y + 1, res, 0);
    dfs(g, max_x, max_y, x + 1, y, res, 1);
    dfs(g, max_x, max_y, x, y - 1, res, 2);
    dfs(g, max_x, max_y, x - 1, y, res, 3);
}
int *spiralOrder(int **matrix, int matrixSize, int *matrixColSize, int *returnSize)
{
    *returnSize = matrixSize * *matrixColSize;
    int *res = (int *)malloc(*returnSize * sizeof(int));
    dfs(matrix, matrixSize, *matrixColSize, 0, 0, res, 0);
    return res;
}
// @lc code=end
