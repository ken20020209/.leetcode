/*
 * @lc app=leetcode id=258 lang=c
 *
 * [258] Add Digits
 */
#include "header\leetcode.h"

// @lc code=start

int addDigits(int num)
{
    if (num == 0)
        return 0;
    if (num % 9 == 0)
        return 9;
    return num % 9;
}

// @lc code=end
