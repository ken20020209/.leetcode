/*
 * @lc app=leetcode id=15 lang=c
 *
 * [15] 3Sum
 */
#include "header\leetcode.h"

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
//O(n^3) time TLE BF
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{

    int left=0;
    int right=0;
    int cur=0;
    int **res=(int**)malloc(numsSize*sizeof(int*));
    *returnSize=0;
    *returnColumnSizes=(int*)malloc(numsSize*sizeof(int));
    for(int i=0; i<numsSize; i++)
    {
        res[i]=(int*)malloc(3*sizeof(int));
        (*returnColumnSizes)[i]=3;
    }
    for(int i=0; i<numsSize; i++)
    {
        for (int j=i+1; j<numsSize; j++)
        {
            for (int k=j+1; k<numsSize; k++)
            {
                if (nums[i]+nums[j]+nums[k]==0)
                {
                    res[*returnSize][0]=nums[i];
                    res[*returnSize][1]=nums[j];
                    res[*returnSize][2]=nums[k];
                    (*returnSize)++;
                }
            }
        }        
    }
    return res;
}
// @lc code=end
int main()
{

}
