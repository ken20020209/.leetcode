/*
 * @lc app=leetcode id=763 lang=c
 *
 * [763] Partition Labels
 */
#include "header\leetcode.h"

// @lc code=start

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *partitionLabels(char *s, int *returnSize)
{
    int *res = (int *)calloc(26, sizeof(int));
    *returnSize = 0;
    int lens = strlen(s);
    int map[256] = {0};
    for (int i = 0; i <= lens; i++)
        map[s[i]] = i;
    int max = 0;
    for (int i = 0; i <= lens; i++)
    {
        if (i > max || i == lens)
        {
            res[*returnSize] = max;
            (*returnSize)++;
        }
        max = fmax(map[s[i]], max);
    }
    for (int i = *returnSize - 1; i > 0; i--)
    {
        res[i] -= res[i - 1];
    }
    res[0]++;
    return res;
}
// @lc code=end
