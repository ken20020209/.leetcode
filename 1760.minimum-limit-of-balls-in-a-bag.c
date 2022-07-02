/*
 * @lc app=leetcode id=1760 lang=c
 *
 * [1760] Minimum Limit of Balls in a Bag
 */
#include "header\leetcode.h"

// @lc code=start

int minimumSize(int *nums, int numsSize, int maxOperations)
{
    int high = 1e9;
    int low = 1;
    int res;
    int mid;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        // printf("mid:%d\n", mid);
        int cnt = 0;
        for (int i = 0; i < numsSize; i++)
        {
            cnt += (nums[i] - 1) / mid;
        }
        // printf("    cnt:%d\n", cnt);

        if (cnt <= maxOperations)
        {
            res = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return res;
}
// @lc code=end
