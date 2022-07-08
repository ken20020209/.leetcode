/*
 * @lc app=leetcode id=10 lang=c
 *
 * [10] Regular Expression Matching
 */
#include "header\leetcode.h"

// @lc code=start
bool dp[35][35];
bool helper(char *s, char *p, int i, int j)
{
    int ret = 0;
    if (dp[i][j] == true)
        return true;
    if (*s == '\0' && *p == '\0')
        return true;
    if (*p == '\0')
        return false;

    if (*(p + 1) == '*')
    {
        if (*s != '\0' && (*s == *p || *p == '.'))
            ret |= helper(s + 1, p, i + 1, j);
        ret |= helper(s, p + 2, i, j + 2);
    }
    else
    {
        if (*s != '\0' && (*s == *p || *p == '.'))
            ret |= helper(s + 1, p + 1, i + 1, j + 1);
    }
    dp[i][j] = ret;
    return ret;
}
bool isMatch(char *s, char *p)
{
    int len1 = strlen(s);
    int len2 = strlen(p);

    int ret = helper(s, p, 0, 0);
    for (int i = 0; i <= len1; i++)
    {
        for (int j = 0; j <= len2; j++)
        {
            dp[i][j] = 0;
        }
    }
    return ret;
}
// @lc code=end
