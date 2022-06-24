/*
 * @lc app=leetcode id=392 lang=c
 *
 * [392] Is Subsequence
 */
#include "header\leetcode.h"

// @lc code=start

bool isSubsequence(char *s, char *t)
{
    if (*s == '\0')
        return true;

    while (*t != '\0')
    {

        if (*s == *t)
        {
            s++;
        }
        if (*s == '\0')
        {
            return true;
        }
        t++;
    }
    return false;
}
// @lc code=end
