/*
 * @lc app=leetcode id=438 lang=c
 *
 * [438] Find All Anagrams in a String
 */
#include "header\leetcode.h"

// @lc code=start

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int *findAnagrams(char *s, char *p, int *returnSize)
{
    int lens = strlen(s);
    int lenp = strlen(p);
    int map[256] = {0};
    int uq = 0;
    for (int i = 0; i < lenp; i++)
    {
        if (i < lens)
            map[s[i]]--;
        map[p[i]]++;
    }
    *returnSize = 0;
    int *res = (int *)malloc(lens * sizeof(int));
    for (int i = 0; i < lens - lenp + 1; i++)
    {
        uq = 0;
        for (int j = 0; j < 256; j++)
        {
            if (map[j] != NULL)
            {
                uq = 1;
                break;
            }
        }
        if (uq == 0)
        {
            res[(*returnSize)++] = i;
        }
        map[s[i]]++;
        map[s[i + lenp]]--;
    }
    return res;
}
// @lc code=end
