/*
 * @lc app=leetcode id=739 lang=c
 *
 * [739] Daily Temperatures
 */
#include "header\leetcode.h"

// @lc code=start

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// BF TLE
//  int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize)
//  {
//      int *res=(int*)calloc(temperaturesSize, sizeof(int));
//      *returnSize=temperaturesSize;
//      for(int i=0; i<temperaturesSize; i++)
//      {
//          for(int j=i+1; j<temperaturesSize; j++)
//          {
//              if(temperatures[j]>temperatures[i])
//              {
//                  res[i]=j-i;
//                  break;
//              }
//          }
//      }
//      return res;
//  }
int *dailyTemperatures(int *temperatures, int temperaturesSize, int *returnSize)
{
    int *res = (int *)calloc(temperaturesSize, sizeof(int));
    *returnSize = temperaturesSize;
    int stack[100000] = {0};
    int sstop = -1;
    stack[++sstop] = 0;
    stack[++sstop] = temperatures[0];
    for (int i = 1; i < temperaturesSize; i++)
    {
        while (sstop != -1 && stack[sstop] < temperatures[i])
        {
            sstop--;
            res[stack[sstop]] = i - stack[sstop];
            sstop--;
        }
        stack[++sstop] = i;
        stack[++sstop] = temperatures[i];
    }
    return res;
}
// @lc code=end
