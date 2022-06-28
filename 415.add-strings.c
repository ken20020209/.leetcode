/*
 * @lc app=leetcode id=415 lang=c
 *
 * [415] Add Strings
 */
#include "header\leetcode.h"

// @lc code=start

char *addStrings(char *num1, char *num2)
{
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int max = fmax(len1, len2) + 1;
    char *res = (char *)calloc(max + 1, sizeof(char));
    int cur;
    for (int i = 0; i < len1; i++)
        num1[i] -= '0';
    for (int i = 0; i < len2; i++)
        num2[i] -= '0';
    for (int i = 0; i < max; i++)
    {
        cur = (len1 - i - 1 >= 0 ? num1[len1 - i - 1] : 0) + (len2 - i - 1 >= 0 ? num2[len2 - i - 1] : 0) + res[i];
        if (cur > 0)
        {
            res[i] = cur % 10;
            res[i + 1] = cur / 10;
        }
    }
    for (int i = 0; i < max; i++)
        res[i] += '0';
    if (res[max - 1] == '0')
    {
        res[max - 1] = 0;
        max--;
    }
    for (int i = 0; i < max / 2; i++)
    {
        char temp = res[i];
        res[i] = res[max - i - 1];
        res[max - i - 1] = temp;
    }
    return res;
}
// @lc code=end
