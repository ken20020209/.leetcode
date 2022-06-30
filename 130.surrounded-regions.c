/*
 * @lc app=leetcode id=130 lang=c
 *
 * [130] Surrounded Regions
 */
#include "header\leetcode.h"

// @lc code=start

void dfs(char **g, int max_x, int max_y, int x, int y, int dst, int src)
{
    if (x < 0 || y < 0 || x >= max_x || y >= max_y)
        return;
    if (g[x][y] == 'X')
        return;
    if (g[x][y] == src)
    {
        g[x][y] = dst;
        dfs(g, max_x, max_y, x + 1, y, dst, src);
        dfs(g, max_x, max_y, x - 1, y, dst, src);
        dfs(g, max_x, max_y, x, y + 1, dst, src);
        dfs(g, max_x, max_y, x, y - 1, dst, src);
    }
}
void solve(char **board, int boardSize, int *boardColSize)
{
    int m = boardSize;
    int n = *boardColSize;
    for (int i = 0; i < m; i++)
    {
        dfs(board, m, n, i, 0, '$', 'O');
        dfs(board, m, n, i, n - 1, '$', 'O');
    }
    for (int i = 0; i < n; i++)
    {
        dfs(board, m, n, 0, i, '$', 'O');
        dfs(board, m, n, m - 1, i, '$', 'O');
    }
    for (int i = 1; i < m - 1; i++)
    {
        for (int j = 1; j < n - 1; j++)
        {
            dfs(board, m, n, i, j, 'X', 'O');
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dfs(board, m, n, i, j, 'O', '$');
        }
    }
    return board;
}
// @lc code=end
