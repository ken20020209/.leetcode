/*
 * @lc app=leetcode id=451 lang=c
 *
 * [451] Sort Characters By Frequency
 */
#include "header\leetcode.h"

// @lc code=start

int map[256];
int cmp(char *a, char *b)
{
    if (map[*b] == map[*a])
        return *b - *a;
    return map[*b] - map[*a];
}
char *frequencySort(char *s)
{
    memset(map, 0, sizeof(int) * 256);
    int len = strlen(s);
    for (int i = 0; i < len; i++)
    {
        map[s[i]]++;
    }
    qsort(s, len, sizeof(char), cmp);
    return s;
}
// @lc code=end
