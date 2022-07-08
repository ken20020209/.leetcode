/*
 * @lc app=leetcode id=171 lang=c
 *
 * [171] Excel Sheet Column Number
 */
#include "header\leetcode.h"

// @lc code=start

int titleToNumber(char *columnTitle)
{
    int len = strlen(columnTitle);
    long int res = 0;
    for (int i = 0; i < len; i++)
    {
        res = (res * 26 + columnTitle[i] - 'A' + 1) % (INT_MAX + 1);
    }
    return res;
}
// @lc code=end
