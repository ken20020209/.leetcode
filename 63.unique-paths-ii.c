/*
 * @lc app=leetcode id=63 lang=c
 *
 * [63] Unique Paths II
 */
#include "header\leetcode.h"

// @lc code=start


int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize)
{
    int m=obstacleGridSize;
    int n=*obstacleGridColSize;
    if (obstacleGrid[m-1][n-1] == 1)return 0;

    for(int i=0; i<m; i++)
        for (int j=0; j<n; j++)
            if(obstacleGrid[i][j]==1)obstacleGrid[i][j] = -1;

    for (int i=0; i<m; i++)
    {
        if(obstacleGrid[i][0]==-1)break;
        obstacleGrid[i][0] =1;
    }
    for (int i=0; i<n; i++)
    {
        if(obstacleGrid[0][i]==-1)break;
        obstacleGrid[0][i] =1;
    }
    for (int i=1; i<m; i++)
    {
        for(int j=1;j<n;j++)
        {
            if (obstacleGrid[i][j]==-1)continue;
            int top=obstacleGrid[i-1][j];
            top=top==-1 ?0:top;
            int left=obstacleGrid[i][j-1];
            left=left==-1?0:left;
            obstacleGrid[i][j]=top+left;
        }
    }
    return obstacleGrid[m-1][n-1];
}
// @lc code=end

