/*
 * @lc app=leetcode id=409 lang=c
 *
 * [409] Longest Palindrome
 */
#include "header\leetcode.h"

// @lc code=start

int longestPalindrome(char *s)
{
    int map[256] = {0};
    int res = 0;
    int len = strlen(s);
    for (int i = 0; i < len; i++)
    {
        if (map[s[i]] == 1)
        {
            map[s[i]] = 0;
            res += 2;
        }
        else
        {
            map[s[i]] = 1;
        }
    }
    return res != len ? res + 1 : res;
}
// @lc code=end
