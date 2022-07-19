/*
 * @lc app=leetcode id=87 lang=c
 *
 * [87] Scramble String
 */
#include "header\leetcode.h"

// @lc code=start
// TLE
// bool isScramble(char *s1, char *s2)
// {
//     int map[26] = {0};
//     if (strcmp(s1, s2) == 0)
//         return true;
//     int len = strlen(s1);
//     for (int i = 0; i < len; i++)
//     {
//         map[s1[i] - 'a']++;
//         map[s2[i] - 'a']--;
//     }
//     for (int i = 0; i < 26; i++)
//         if (map[i])
//             return false;

//     for (int i = 1; i < len; i++)
//     {
//         char str1[30] = {0};
//         char str2[30] = {0};
//         char str3[30] = {0};
//         char str4[30] = {0};
//         memcpy(str1, s1, i);
//         memcpy(str2, s2, i);
//         memcpy(str3, s1 + i, len - i);
//         memcpy(str4, s2 + i, len - i);
//         // printf("%s %s\n", str1, str3);
//         // printf("%s %s\n", str2, str4);
//         if (isScramble(str1, str2) && isScramble(str3, str4))
//             return true;
//         str1[i] = '\0';
//         str2[i] = '\0';
//         str3[len - i] = '\0';
//         str4[len - i] = '\0';
//         memcpy(str1, s1, i);
//         memcpy(str2, s2 + len - i, i);
//         memcpy(str3, s1 + i, len - i);
//         memcpy(str4, s2, len - i);
//         // printf("%s %s\n", str1, str3);
//         // printf("%s %s\n", str2, str4);
//         // printf("\n");
//         if (isScramble(str1, str2) && isScramble(str3, str4))
//             return true;
//     }
//     return false;
// }

// dp
bool isScramble(char *s1, char *s2)
{
    int length = strlen(s1);
    int dp[31][30][30] = {0};
    int map[26] = {0};
    if (strcmp(s1, s2) == 0)
        return true;
    int len = strlen(s1);
    for (int i = 0; i < len; i++)
    {
        map[s1[i] - 'a']++;
        map[s2[i] - 'a']--;
    }
    for (int i = 0; i < 26; i++)
        if (map[i])
            return false;
    for (int len = 1; len <= length; len++)
    {
        for (int i = 0; i + len <= length; i++)
        {
            for (int j = 0; j + len <= length; j++)
            {
                if (len == 1)
                {
                    dp[len][i][j] = s1[i] == s2[j];
                }
                else
                {
                    for (int k = 1; k < len; k++)
                    {
                        dp[len][i][j] = dp[k][i][j] && dp[len - k][i + k][j + k] || dp[k][i][j + len - k] && dp[len - k][i + k][j];
                        if (dp[len][i][j])
                            break;
                    }
                }
            }
        }
    }
    return dp[length][0][0];
}
// @lc code=end
