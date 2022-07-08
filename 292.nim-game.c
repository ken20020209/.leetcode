/*
 * @lc app=leetcode id=292 lang=c
 *
 * [292] Nim Game
 */
#include "header\leetcode.h"

// @lc code=start

bool canWinNim(int n)
{
    return n % 4 != 0;
}
// @lc code=end
