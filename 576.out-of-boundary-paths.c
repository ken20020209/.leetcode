/*
 * @lc app=leetcode id=576 lang=c
 *
 * [576] Out of Boundary Paths
 */
#include "header\leetcode.h"

// @lc code=start

// int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
// {
//     int dp[m][n][maxMove + 1];
//     int dir[] = {-1, 0, 1, 0, -1};
//     int mod = (1e9) + 7;
//     memset(dp, 0, sizeof(dp));
//     for (int step = 1; step <= maxMove; step++)
//     {
//         for (int x = 0; x < m; x++)
//         {
//             for (int y = 0; y < n; y++)
//             {
//                 for (int d = 0; d < 4; d++)
//                 {
//                     int nx = x + dir[d];
//                     int ny = y + dir[d + 1];
//                     if (nx < 0 || ny < 0 || nx >= m || ny >= n)
//                         dp[x][y][step] += 1;
//                     else
//                         dp[x][y][step] = (dp[x][y][step] + dp[nx][ny][step - 1]) % mod;
//                 }
//             }
//         }
//     }
//     return dp[startRow][startColumn][maxMove];
// }
int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
{
    int dp1[m][n];
    int dp2[m][n];
    int dir[] = {-1, 0, 1, 0, -1};
    int mod = (1e9) + 7;
    memset(dp1, 0, sizeof(dp1));
    memset(dp2, 0, sizeof(dp2));
    for (int step = 1; step <= maxMove; step++)
    {
        for (int x = 0; x < m; x++)
        {
            for (int y = 0; y < n; y++)
            {
                for (int d = 0; d < 4; d++)
                {
                    int nx = x + dir[d];
                    int ny = y + dir[d + 1];
                    if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                        dp1[x][y] += 1;
                    else
                        dp1[x][y] = (dp1[x][y] + dp2[nx][ny]) % mod;
                }
            }
        }
        memcpy(dp2, dp1, sizeof(dp2));
        memset(dp1, 0, sizeof(dp1));
    }
    return dp2[startRow][startColumn];
}
// @lc code=end
