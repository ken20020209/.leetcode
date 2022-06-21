/*
 * @lc app=leetcode id=120 lang=c
 *
 * [120] Triangle
 */
#include "header\leetcode.h"
// @lc code=start
#define max(a,b) ((((a)>(b))?(a):b))
#define min(a,b) ((((a)<(b))?(a):b))
//dfs O(n^) TLE
int dfs(int **triangle,int triangleSize,int* triangleColSize,int i,int depth)
{
    
    if(depth>=triangleSize)return 0;
    if(i>=triangleColSize[depth])return 0;
    int sum=triangle[depth][i];

    sum+=min(dfs(triangle,triangleSize,triangleColSize,i,depth+1),dfs(triangle,triangleSize,triangleColSize,i+1,depth+1));
    return sum;
}
int dp(int ** triangle, int triangleSize, int* triangleColSize)
{
    int pre[triangleSize];
    int cur[triangleSize];
    int res=INT_MAX;
    pre[0]=triangle[0][0];
    if(triangleSize==1)return pre[0];
    for(int i=1;i<triangleSize;i++)
    {
        /*
        for (int j = 0; j < triangleColSize[i]-1; j++)
        {
            printf("%d ",pre[j]);
        }
        printf("\n");
        */
        for (int j = 0; j < triangleColSize[i]; j++)
        {
            if(j==0||j==triangleColSize[i]-1)cur[j]=triangle[i][j]+ (j==0?pre[j]:pre[j-1]);
            else
            cur[j]=min(triangle[i][j]+pre[j],triangle[i][j]+pre[j-1]);
        }
        /*
        for (int j = 0; j < triangleColSize[i]; j++)
        {
            printf("%d ",cur[j]);
        }
        printf("\n\n");
        */
        memcpy(pre,cur,triangleSize*sizeof(int));
        
    }

    for(int i=0;i<triangleSize;i++)
    {
        res=min(res,cur[i]);
    }
    return res;
}
int minimumTotal(int** triangle, int triangleSize, int* triangleColSize)
{
    return dp(triangle,triangleSize,triangleColSize);
    //return dfs(triangle,triangleSize,triangleColSize,0,0);
}
// @lc code=end