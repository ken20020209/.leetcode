/*
 * @lc app=leetcode id=29 lang=c
 *
 * [29] Divide Two Integers
 */
#include "header\leetcode.h"

// @lc code=start

#define abs(a) (((a) < 0) ? -(a) : (a))
int divide(int dividend, int divisor)
{
    if (dividend == INT_MIN && divisor == -1)
    {
        return INT_MAX;
    }
    long dvd = abs((long)dividend), dvs = abs((long)divisor), res = 0;
    int sign = dividend > 0 ^ divisor > 0 ? -1 : 1;
    while (dvd >= dvs)
    {
        long m = 1;
        long temp = dvs;
        while (temp << 1 <= dvd)
        {
            temp <<= 1;
            m <<= 1;
        }
        dvd -= temp;
        res += m;
    }
    return res * sign;
}
// @lc code=end
