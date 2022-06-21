/*
 * @lc app=leetcode id=119 lang=c
 *
 * [119] Pascal's Triangle II
 */
#include "header\common.h"
// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// nCr = n!/(n-r)!/r!;
int nCr(int n,int r)
{
    long long int res=1;
    int temp=n-r;
    int temp2=1;
    while (n>r)
    {
        res*=n;
        n--;
        if(temp2<=temp&&res%temp2==0)
        {
            res/=temp2;
            temp2++;
        }
    }
    return res;
    
    
}
int* getRow(int rowIndex, int* returnSize)
{
    *returnSize=rowIndex+1;
    int *res=(int*)malloc(*returnSize*sizeof(int));
    for (int i = 0; i < *returnSize; i++)
    {
        res[i]=(int)nCr(rowIndex,i);
    }
    
    return res;
}
// @lc code=end

