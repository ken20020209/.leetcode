/*
 * @lc app=leetcode id=516 lang=c
 *
 * [516] Longest Palindromic Subsequence
 */
#include "header\leetcode.h"

// @lc code=start

int dp1_longestPalindromeSubseq(char *s)
{
    int len = strlen(s);
    int **dp = (int **)malloc(len * sizeof(int *));
    for (int i = 0; i < len; i++)
        dp[i] = (int *)calloc(len, sizeof(int));
    for (int k = 1; k <= len; k++)
    {
        for (int i = 0; i <= len - k; i++)
        {
            int j = i + k - 1;
            if (j == i)
                dp[i][j] = 1;
            else if (s[i] == s[j])
                dp[i][j] = dp[i + 1][j - 1] + 2;
            else
                dp[i][j] = fmax(dp[i + 1][j], dp[i][j - 1]);
        }
    }
    return dp[0][len - 1];
}
int dp2_longestPalindromeSubseq(char *s)
{
    int len = strlen(s);
    int *dp1 = (int *)calloc(len, sizeof(int));
    int *dp2 = (int *)calloc(len, sizeof(int));
    int *dp3 = (int *)calloc(len, sizeof(int));
    for (int k = 1; k <= len; k++)
    {
        for (int i = 0; i <= len - k; i++)
        {
            int j = i + k - 1;
            if (j == i)
                dp1[i] = 1;
            else if (s[i] == s[j])
                dp1[i] = dp2[i + 1] + 2;
            else
                dp1[i] = fmax(dp3[i + 1], dp3[i]);
        }
        int *temp;
        temp = dp2;
        dp2 = dp3;
        dp3 = dp1;
        dp1 = temp;
    }
    int res=dp3[0];
    free(dp1);
    free(dp2);
    free(dp3);
    return res;
}
int longestPalindromeSubseq(char *s)
{
    return dp2_longestPalindromeSubseq(s);
    return dp1_longestPalindromeSubseq(s);
}
// @lc code=end
