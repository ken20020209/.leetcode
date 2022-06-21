/*
 * @lc app=leetcode id=62 lang=c
 *
 * [62] Unique Paths
 */
#include "header\leetcode.h"

// @lc code=start


int uniquePaths(int m, int n)
{
    int res[m][n];
    res[0][0]=1;
    for(int i=1; i<m; i++)
    {
        res[i][0]=1;
    }
    for(int i=1; i<n; i++)
    {
        res[0][i]=1;
    }
    for(int i=1; i<m; i++)
    {
        for(int j=1; j<n; j++)
        {
            res[i][j]=res[i-1][j]+res[i][j-1];
        }
    }
    return res[m-1][n-1];
}
// @lc code=end

