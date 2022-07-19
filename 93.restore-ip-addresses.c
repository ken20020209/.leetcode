/*
 * @lc app=leetcode id=93 lang=c
 *
 * [93] Restore IP Addresses
 */
#include "header\leetcode.h"

// @lc code=start

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void backtrack(char *s, int lens, int index, char **res, int *returnSize, int buf[4], int bufpos)
{
    char temp[4] = {0};
    if (index == lens && bufpos == 4)
    {
        char resbuf[100] = {0};
        sprintf(resbuf, "%d.%d.%d.%d", buf[0], buf[1], buf[2], buf[3]);
        printf("%s\n", resbuf);
        res[*returnSize] = (char *)calloc(strlen(resbuf) + 1, sizeof(char));
        strcpy(res[*returnSize], resbuf);
        (*returnSize)++;
        return;
    }
    if (bufpos > 3)
        return;
    for (int i = 1; i <= 3; i++)
    {
        if (index + i > lens)
            return;
        memcpy(temp, s + index, i * sizeof(char));
        if (temp[0] == '0' && temp[1] != '\0')
            continue;
        buf[bufpos] = atoi(temp);
        if (buf[bufpos] > 255 || buf[bufpos] < 0)
            return;
        backtrack(s, lens, index + i, res, returnSize, buf, bufpos + 1);
        buf[bufpos] = 0;
    }
}
char **restoreIpAddresses(char *s, int *returnSize)
{
    int buf[4] = {0};
    *returnSize = 0;
    char **res = (char **)malloc(sizeof(char *) * 1000);
    backtrack(s, strlen(s), 0, res, returnSize, buf, 0);
    res = (char **)realloc(res, *returnSize * sizeof(char *));
    return res;
}
// @lc code=end
