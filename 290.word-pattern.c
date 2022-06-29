/*
 * @lc app=leetcode id=290 lang=c
 *
 * [290] Word Pattern
 */
#include "header\leetcode.h"

// @lc code=start

bool wordPattern(char *pattern, char *s)
{
    int map[256] = {0};
    int lenp = strlen(pattern);
    int hash;
    for (int i = 0; i < lenp; i++)
    {
        hash = 0;
        while (*s != ' ' && *s != '\0')
        {
            if (hash > INT_MAX / 31 + 1)
                hash >>= 16;
            hash = hash * 31 + *s;
            s++;
        }
        if (*s == '\0' && i != lenp - 1)
            return false;
        s++;
        // printf("hash:%d\n", hash);
        if (map[pattern[i]] == 0)
        {
            for (int j = 'a'; j <= 'z'; j++)
            {
                if (map[j] == hash)
                    return false;
            }
            map[pattern[i]] = hash;
        }
        else if (map[pattern[i]] != hash)
        {
            return false;
        }
    }
    if (*(s - 1) != '\0')
        return false;
    return true;
}
// @lc code=end
