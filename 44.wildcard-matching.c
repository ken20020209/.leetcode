/*
 * @lc app=leetcode id=44 lang=c
 *
 * [44] Wildcard Matching
 */
#include "header\leetcode.h"

// @lc code=start

// //dp
// bool isMatch(char *s, char *p)
// {
//     int lens = strlen(s);
//     int lenp = strlen(p);
//     int **dp = (int **)malloc((lenp + 1) * sizeof(int *));
//     for (int i = 0; i < lenp + 1; i++)
//     {
//         dp[i] = (int *)calloc(lens + 1, sizeof(int));
//     }
//     dp[0][0] = 1;
//     for (int i = 1; i <= lenp; i++)
//     {
//         if (p[i - 1] == '*')
//         {
//             dp[i][0] = true;
//         }
//         else
//         {
//             break;
//         }
//     }
//     for (int i = 1; i <= lenp; i++)
//     {
//         for (int j = 1; j <= lens; j++)
//         {
//             if (p[i - 1] == s[j - 1] || p[i - 1] == '?')
//             {
//                 dp[i][j] = dp[i - 1][j - 1];
//             }
//             else if (p[i - 1] == '*')
//             {
//                 dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
//             }
//         }
//     }

//     int res = dp[lenp][lens];
//     // for (int i = 0; i < lenp + 1; i++)
//     // {
//     //     for (int j = 0; j < lens + 1; j++)
//     //     {
//     //         printf("%d ", dp[i][j]);
//     //     }
//     //     printf("\n");
//     // }
//     // printf("\n");
//     for (int i = 0; i < lenp + 1; i++)
//     {
//         free(dp[i]);
//     }
//     free(dp);
//     return res;
// }
bool isMatch(char *s, char *p)
{
    const char *star = NULL;
    const char *ss = s;
    while (*s)
    {
        // advancing both pointers when (both characters match) or ('?' found in pattern)
        // note that *p will not advance beyond its length
        if ((*p == '?') || (*p == *s))
        {
            s++;
            p++;
            continue;
        }

        // * found in pattern, track index of *, only advancing pattern pointer
        if (*p == '*')
        {
            star = p++;
            ss = s;
            continue;
        }

        // current characters didn't match, last pattern pointer was *, current pattern pointer is not *
        // only advancing pattern pointer
        if (star)
        {
            p = star + 1;
            s = ++ss;
            continue;
        }

        // current pattern pointer is not star, last patter pointer was not *
        // characters do not match
        return false;
    }

    // check for remaining characters in pattern
    while (*p == '*')
    {
        p++;
    }

    return !*p;
}
// @lc code=end
