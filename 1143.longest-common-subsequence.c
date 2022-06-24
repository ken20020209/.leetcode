/*
 * @lc app=leetcode id=1143 lang=c
 *
 * [1143] Longest Common Subsequence
 */
#include "header\leetcode.h"

// @lc code=start

int dp1_longestCommonSubsequence(char *text1, char *text2)
{
    int len1 = strlen(text1);
    int len2 = strlen(text2);
    int **dp = (int **)calloc((len1 + 1), sizeof(int *));
    for (int i = 0; i < len1 + 1; i++)
    {
        dp[i] = (int *)calloc((len2 + 1), sizeof(int));
    }
    for (int i = 0; i < len1; i++)
    {
        for (int j = 0; j < len2; j++)
        {
            if (text1[i] == text2[j])
            {
                dp[i + 1][j + 1] = dp[i][j] + 1;
            }
            else
            {
                dp[i + 1][j + 1] = fmax(dp[i + 1][j], dp[i][j + 1]);
            }
        }
    }
    int res = dp[len1][len2];
    for (int i = 0; i < len1 + 1; i++)
    {
        free(dp[i]);
    }
    free(dp);

    return res;
}
int dp_2longestCommonSubsequence(char *text1, char *text2)
{
    int len1 = strlen(text1);
    int len2 = strlen(text2);
    int *dp1 = (int *)calloc((len2 + 1), sizeof(int));
    int *dp2 = (int *)calloc((len2 + 1), sizeof(int));
    for (int i = 0; i < len1; i++)
    {
        for (int j = 0; j < len2; j++)
        {
            if (text1[i] == text2[j])
            {
                dp2[j + 1] = dp1[j] + 1;
            }
            else
            {
                dp2[j + 1] = fmax(dp2[j], dp1[j + 1]);
            }
        }

        int *temp;
        temp = dp1;
        dp1 = dp2;
        dp2 = temp;
    }
    int res = dp1[len2];
    free(dp1);
    free(dp2);

    return res;
}
int longestCommonSubsequence(char *text1, char *text2)
{
    return dp_2longestCommonSubsequence(text1, text2);
    return dp1_longestCommonSubsequence(text1, text2);
}
// @lc code=end
