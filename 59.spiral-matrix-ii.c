/*
 * @lc app=leetcode id=59 lang=c
 *
 * [59] Spiral Matrix II
 */
#include "header\leetcode.h"

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void dfs(int **g,int max_x,int max_y,int x, int y,int *val ,int dir)
{
    if (x<0 || y<0||x>=max_x || y>=max_y) return;
    if(g[x][y]!=0) return;
    g[x][y]=*val;
    (*val)++;
    if(dir==3)dfs(g,max_x,max_y,x-1, y,val,3);
    dfs(g,max_x,max_y,x, y+1,val,0);
    dfs(g,max_x,max_y,x+1, y,val,1);
    dfs(g,max_x,max_y,x, y-1,val,2);
    dfs(g,max_x,max_y,x-1, y,val,3);
    
}
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes)
{
    *returnSize = n;
    *returnColumnSizes = (int*)malloc(n*sizeof(int));
    int **res=(int**)malloc(n*sizeof(int*));
    for(int i=0; i<n; i++)
    {
        res[i]=(int*)calloc(n,sizeof(int));
        (*returnColumnSizes)[i]=n;
    }
    int val=1;
    dfs(res,n,n,0,0,&val,0);
    return res;
}
// @lc code=end

