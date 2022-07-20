/*
 * @lc app=leetcode id=470 lang=c
 *
 * [470] Implement Rand10() Using Rand7()
 */
#include "header\leetcode.h"

// @lc code=start
// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

int rand10()
{
    int res = INT_MAX;
    while (res > 40)
    {
        res = 7 * (rand7() - 1) + (rand7());
    }
    return res % 10 + 1;
}
// @lc code=end
