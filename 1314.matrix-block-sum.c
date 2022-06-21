/*
 * @lc app=leetcode id=1314 lang=c
 *
 * [1314] Matrix Block Sum
 */
#include "header\leetcode.h"

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int** matrixBlockSum(int** mat, int matSize, int* matColSize, int k, int* returnSize, int** returnColumnSizes)
{
    int n=matSize;
    int m=*matColSize;
    *returnSize=n;
    (*returnColumnSizes)=(int*)malloc(sizeof(int)*n);
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
            dp[i][j]=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            dp[i][j]=mat[i-1][j-1]+dp[i][j-1]+dp[i-1][j]-dp[i-1][j-1];

    /*
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=m; j++) 
        {
            printf("%d ",dp[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    */
    for(int i=1; i<=n; i++)
    {
        (*returnColumnSizes)[i-1]=m;
        for(int j=1; j<=m; j++) 
        {
            int c1=(j-k>0)? j-k : 1;
            int r1=(i-k>0)? i-k : 1;
            int c2=(j+k>m)? m : j+k;
            int r2=(i+k>n)? n : i+k;
            mat[i-1][j-1]=dp[r2][c2]+dp[r1-1][c1-1]-dp[r2][c1-1]-dp[r1-1][c2];
        }
    }
    
    return mat;
}
// @lc code=end

