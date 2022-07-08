/*
 * @lc app=leetcode id=263 lang=c
 *
 * [263] Ugly Number
 */
#include "header\leetcode.h"

// @lc code=start

bool isUgly(int n)
{
    if (n > 0)
        for (int i = 2; i < 6; i++)
            while (n % i == 0)
                n /= i;
    return n == 1;
}
// @lc code=end
