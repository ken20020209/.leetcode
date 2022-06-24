/*
 * @lc app=leetcode id=72 lang=c
 *
 * [72] Edit Distance
 */
#include "header\leetcode.h"

// @lc code=start
int helper(char *word1, char *word2, int len1, int len2, int **dp)
{
    int res;
    if (len1 == 0)
        return len2;
    if (len2 == 0)
        return len1;
    if (dp[len1][len2] >= 0)
        return dp[len1][len2];
    if (word1[len1 - 1] == word2[len2 - 1])
    {
        res = helper(word1, word2, len1 - 1, len2 - 1, dp);
    }
    else
    {
        int replaceChar = helper(word1, word2, len1 - 1, len2 - 1, dp);
        int insertChar = helper(word1, word2, len1, len2 - 1, dp);
        int deleteChar = helper(word1, word2, len1 - 1, len2, dp);
        res = 1 + fmin(replaceChar, fmin(insertChar, deleteChar));
    }
    dp[len1][len2] = res;
    return res;
}
int minDistance(char *word1, char *word2)
{

    int len1 = strlen(word1);
    int len2 = strlen(word2);
    int res;
    // if (len1 == 0)
    //     return len2;
    // if (len2 == 0)
    //     return len1;
    int **dp = (int **)calloc(len1 + 1, sizeof(int *));
    for (int i = 0; i < len1 + 1; i++)
    {
        dp[i] = (int *)calloc(len2 + 1, sizeof(int));
        memset(dp[i], -1, (len2 + 1) * sizeof(int));
    }
    res = helper(word1, word2, len1, len2, dp);
    for (int i = 0; i < len1 + 1; i++)
    {
        free(dp[i]);
    }
    free(dp);
    return res;
}
// @lc code=end
int main()
{
    char *word1 = "intention\0";
    char *word2 = "execution\0";
    printf("%d",minDistance(word1, word2));
    return 0;
}