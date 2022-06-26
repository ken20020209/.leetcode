/*
 * @lc app=leetcode id=1894 lang=c
 *
 * [1894] Find the Student that Will Replace the Chalk
 */
#include "header\leetcode.h"

// @lc code=start

int chalkReplacer(int *chalk, int chalkSize, int k)
{
    long int *presum = (long int *)malloc(chalkSize * sizeof(long int));
    presum[0] = chalk[0];
    for (int i = 1; i < chalkSize; i++)
        presum[i] = chalk[i] + presum[i - 1];
    k %= presum[chalkSize - 1];
    // line serch
    // printf("K: %d\n", k);
    // int i;
    // for (i = 0; i < chalkSize; i++)
    // {
    //     // printf("%-5d", chalk[i]);
    //     if (k < presum[i])
    //     {
    //         break;
    //     }
    // }
    // free(presum);
    // return i;
    // bs
    int low = 0;
    int high = chalkSize;
    int mid;
    while (low < high)
    {
        mid = low + (high - low) / 2;
        if (presum[mid] > k)
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }

    free(presum);
    return low;
}
// @lc code=end
