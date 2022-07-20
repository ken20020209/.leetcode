/*
 * @lc app=leetcode id=233 lang=c
 *
 * [233] Number of Digit One
 */
#include "header\leetcode.h"

// @lc code=start

int countDigitOne(int n)
{
    int countr = 0;
    for (long long i = 1; i <= n; i *= 10)
    {
        long long divider = i * 10;
        countr += (n / divider) * i + fmin(fmax(n % divider - i + 1, 0LL), i);
    }
    return countr;
}

// @lc code=end
