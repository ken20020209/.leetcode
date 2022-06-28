/*
 * @lc app=leetcode id=989 lang=c
 *
 * [989] Add to Array-Form of Integer
 */
#include "header\leetcode.h"

// @lc code=start

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *addToArrayForm(int *num, int numSize, int k, int *returnSize)
{
    int rsize = 10000;
    int *res = (int *)malloc(sizeof(int) * rsize);
    *returnSize = 0;
    int i=numSize;
    int cur=k;
    while (--i>=0||cur>0)
    {
        if(*returnSize>=rsize)
        {
            rsize*=2;
            res=(int*)realloc(res,rsize*sizeof(int));
        }
        if(i>=0)
        {
            cur+=num[i];
        }
        res[*returnSize]=cur%10;
        cur/=10;
        (*returnSize)++;
    }
    int *temp=(malloc(*returnSize*sizeof(int)));
    for(int i=0; i<*returnSize;i++)
    {
        temp[i]=res[*returnSize-i-1];
    }
    free(res);
    res=temp;
    return res;
}
// @lc code=end
