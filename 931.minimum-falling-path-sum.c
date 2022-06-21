/*
 * @lc app=leetcode id=931 lang=c
 *
 * [931] Minimum Falling Path Sum
 */
#include "header\leetcode.h"

// @lc code=start

#define min(a,b) ( ( (a)<(b) )? (a) : (b) )
int minFallingPathSum(int** matrix, int matrixSize, int* matrixColSize)
{
    const int l=matrixSize;
    int dp[l];
    int next[l];
    
    memcpy(dp, matrix[0], l*sizeof(int));
    for (int i = 1; i < l;i++)
    {
        next[0]=min(matrix[i][0]+dp[0], matrix[i][0]+dp[1]);
        for (int j = 1; j < l-1; j++)
        {
            next[j]=min(matrix[i][j]+dp[j-1],min(matrix[i][j]+dp[j],matrix[i][j]+dp[j+1]));
        }
        next[l-1]= min(matrix[i][l-1]+dp[l-1],matrix[i][l-1]+dp[l-2]);
        memcpy(dp, next, l*sizeof(int));
    }
    int res=INT_MAX;
    for (int i = 0; i < matrixSize; i++)
    {
        res=min(res,dp[i]);
    }
    return res;
    
}
// @lc code=end

