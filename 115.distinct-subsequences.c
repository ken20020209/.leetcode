/*
 * @lc app=leetcode id=115 lang=c
 *
 * [115] Distinct Subsequences
 */
#include "header\leetcode.h"

// @lc code=start
// recursion with memo
// #define MEMOSIZE 1000
// int memo[MEMOSIZE][MEMOSIZE];
// int helper(char *s, char *t)
// {
//     int res = 0;
//     if (memo[(int)s % MEMOSIZE][(int)t % MEMOSIZE] != -1)
//         return memo[(int)s % MEMOSIZE][(int)t % MEMOSIZE];
//     if (*t == '\0')
//         return 1;
//     if (*s == '\0')
//         return 0;
//     // int i = 0;
//     // while (*(s + i))
//     // {
//     //     if (*(s + i) == *t)
//     //     {
//     //         res += helper(s + i + 1, t + 1);
//     //     }
//     //     i++;
//     // }
//     if (*s == *t)
//         res += helper(s + 1, t + 1);
//     res += helper(s + 1, t);
//     return memo[(int)s % MEMOSIZE][(int)t % MEMOSIZE] = res;
// }
// int numDistinct(char *s, char *t)
// {
//     memset(memo, -1, sizeof(memo));
//     return helper(s, t);
// }

// dp
int numDistinct(char *s, char *t)
{
    int res = 0;
    int lens = strlen(s);
    int lent = strlen(t);
    int dp[lens + 1][lent + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < lens; i++)
        dp[i][0] = 1;
    for (int i = 0; i < lens; i++)
    {
        for (int j = 0; j < lent; j++)
        {
            if (s[i] == t[j])
                dp[i + 1][j + 1] = ((long)dp[i + 1][j + 1] + dp[i][j]) % INT_MAX;
            dp[i + 1][j + 1] = ((long)dp[i + 1][j + 1] + dp[i][j + 1]) % INT_MAX;
        }
    }
    return dp[lens][lent];
}
// @lc code=end
int main()
{
    char s[] = "rabbbit";
    char t[] = "rabbit";
    printf("%d\n", numDistinct(s, t));
    return 0;
}