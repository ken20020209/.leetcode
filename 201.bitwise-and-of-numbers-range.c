/*
 * @lc app=leetcode id=201 lang=c
 *
 * [201] Bitwise AND of Numbers Range
 */
#include "header\leetcode.h"

// @lc code=start

int rangeBitwiseAnd(int left, int right)
{
    int step = 0;
    while (left != right)
    {
        left >>= 1;
        right >>= 1;
        step++;
    }

    return left << step;
}
// @lc code=end
