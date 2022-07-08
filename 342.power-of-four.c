/*
 * @lc app=leetcode id=342 lang=c
 *
 * [342] Power of Four
 */
#include "header\leetcode.h"

// @lc code=start

bool isPowerOfFour(int n)
{
    double a = sqrt(n);
    n = a != (int)a ? -1 : a;
    return n > 0 && 1073741824 % n == 0;
}
// @lc code=end
