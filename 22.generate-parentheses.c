/*
 * @lc app=leetcode id=22 lang=c
 *
 * [22] Generate Parentheses
 */
#include "header\leetcode.h"

// @lc code=start

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void backtrace(int n, int *returnSize, int open, int close, char *str, int strsize, char ***res, int *rescapacity)
{
    if (strsize == 2 * n)
    {
        // printf("%s\n", str);
        (*res)[*returnSize] = (char *)calloc((n * 2 + 1), sizeof(char));
        memcpy((*res)[*returnSize], str, strsize);
        (*returnSize)++;
        if (*returnSize == *rescapacity)
        {
            (*rescapacity) *= 2;
            // printf("%d\n", *rescapacity);
            *res = (char **)realloc(*res, *rescapacity * sizeof(char *));
        }
    }
    if (open < n)
    {
        str[strsize] = '(';
        backtrace(n, returnSize, open + 1, close, str, strsize + 1, res, rescapacity);
    }
    if (close < open)
    {
        str[strsize] = ')';
        backtrace(n, returnSize, open, close + 1, str, strsize + 1, res, rescapacity);
    }
}
char **generateParenthesis(int n, int *returnSize)
{
    *returnSize = 0;
    int rescapacity = 2;
    char **res = (char **)malloc(sizeof(char *) * rescapacity);
    char *temp = (char *)calloc((n * 2 + 1), sizeof(char));

    backtrace(n, returnSize, 0, 0, temp, 0, &res, &rescapacity);
    free(temp);
    return res;
}
// @lc code=end
