/*
 * @lc app=leetcode id=583 lang=c
 *
 * [583] Delete Operation for Two Strings
 */
#include "header\leetcode.h"

// @lc code=start

int minDistance(char *word1, char *word2)
{
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    int **dp = (int **)malloc((len1 + 1) * sizeof(int *));
    for (int i = 0; i < len1 + 1; i++)
    {
        dp[i] = (int *)calloc((len2 + 1), sizeof(int));
    }
    int max_len = 0;
    for (int i = 1; i < len1 + 1; i++)
    {
        for (int j = 1; j < len2 + 1; j++)
        {
            dp[i][j] = fmax(dp[i][j - 1], dp[i - 1][j]);
            if (word1[i - 1] == word2[j - 1])
                dp[i][j] = fmax(dp[i][j], dp[i - 1][j - 1] + 1);
        }
    }
    // for (int i = 0; i < len1 + 1; i++)
    // {
    //     for (int j = 0; j < len2 + 1; j++)
    //     {
    //         printf("%d  ", dp[i][j]);
    //     }
    //     printf("\n");
    // }
    max_len = dp[len1][len2];

    return len1 - max_len + len2 - max_len;
}
// @lc code=end
