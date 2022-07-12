/*
 * @lc app=leetcode id=1562 lang=c
 *
 * [1562] Find Latest Group of Size M
 */
#include "header\leetcode.h"

// @lc code=start

int findLatestStep(int *arr, int arrSize, int m)
{
    int *length = (int *)calloc(arrSize + 2, sizeof(int));
    int res = -1;
    if (arrSize == m)
        return m;
    for (int i = 0; i < arrSize; i++)
    {
        int pos = arr[i], left = length[pos - 1], right = length[pos + 1];

        length[pos - left] = length[pos + right] = right + left + 1;
        if (left == m || right == m)
            res = i;
    }
    free(length);
    return res;
}
// @lc code=end
