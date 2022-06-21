/*
 * @lc app=leetcode id=118 lang=c
 *
 * [118] Pascal's Triangle
 */
#include "header\common.h"
// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes)
{
    int **res=(int**)malloc(numRows*sizeof(int*));
    *returnSize = numRows;
    *returnColumnSizes =(int*)malloc(numRows*sizeof(int));
    for(int i=1; i<=numRows; i++)
    {
        res[i-1]=(int*)malloc(i*sizeof(int));
        (*returnColumnSizes)[i-1]=i;
    }
    res[0][0]=1;
    for (int i = 1; i < numRows; i++)
    {
        int j=0;
        res[i][j]=res[i-1][j];
        for (j = 1; j <i; j++)
        {
            res[i][j]=res[i-1][j]+res[i-1][j-1];   
        }
        res[i][j]=res[i-1][j-1];
    }
    
    return res;
}
// @lc code=end

