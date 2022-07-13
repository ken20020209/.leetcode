/*
 * @lc app=leetcode id=1201 lang=c
 *
 * [1201] Ugly Number III
 */
#include "header\leetcode.h"

// @lc code=start

long GCD(long a, long b)
{
    if (b)
        while ((a %= b) && (b %= a))
            ;
    return a + b;
}
long LCM(long long a, long long b)
{
    return a * b / GCD(a, b);
}
long nthUglyNumber(long n, long a, long b, long c)
{
    long high = 2e9;
    long low = 1;
    long mid;
    long ab = LCM(a, b);
    long ac = LCM(a, c);
    long bc = LCM(b, c);
    long abc = LCM(a, bc);
    while (low < high)
    {
        mid = low + (high - low) / 2;
        long k = mid / a + mid / b + mid / c - mid / ab - mid / ac - mid / bc + mid / abc;
        if (k >= n)
            high = mid;
        else
            low = mid + 1;
    }
    return low;
}
// @lc code=end
