/*
 * @lc app=leetcode id=97 lang=c
 *
 * [97] Interleaving String
 */
#include "header\leetcode.h"

// @lc code=start
// recursion TLE may use memoization
// recursion with memoization
#define memosize 100
int memo[memosize][memosize];
bool helper(char *s1, char *s2, char *s3)
{
    if (memo[(int)s1 % memosize][(int)s2 % memosize] != -1)
        return memo[(int)s1 % memosize][(int)s2 % memosize];
    if (*s1 == 0 && *s2 == 0 && *s3 == 0)
        return true;
    if (*s3 == 0)
        return false;
    int res = 0;
    if (*s1 != 0 && *s1 == *s3)
        res |= helper(s1 + 1, s2, s3 + 1);
    if (*s2 != 0 && *s2 == *s3)
        res |= helper(s1, s2 + 1, s3 + 1);
    return memo[(int)s1 % memosize][(int)s2 % memosize] = res;
}
bool isInterleave(char *s1, char *s2, char *s3)
{
    memset(memo, -1, sizeof(memo));
    return helper(s1, s2, s3);
}
// dp
// bool isInterleave(char *s1, char *s2, char *s3)
// {
//     int len1 = strlen(s1), len2 = strlen(s2), len3 = strlen(s3);
//     if (len3 != len1 + len2)
//         return false;
//     int dp[len1 + 1][len2 + 1];
//     memset(dp, 0, sizeof(dp));
//     dp[0][0] = true;
//     for (int i = 0; i <= len1; i++)
//     {
//         for (int j = 0; j <= len2; j++)
//         {
//             if (i != 0 && s1[i - 1] == s3[i + j - 1])
//                 dp[i][j] |= dp[i - 1][j];
//             if (j != 0 && s2[j - 1] == s3[i + j - 1])
//                 dp[i][j] |= dp[i][j - 1];
//         }
//     }
//     return dp[len1][len2];
// }
// @lc code=end
