/*
 * @lc app=leetcode id=43 lang=c
 *
 * [43] Multiply Strings
 */
#include "header\leetcode.h"

// @lc code=start

char *multiply(char *num1, char *num2)
{
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int lenr = len1 + len2;
    int cur;
    int pos;
    for (int i = 0; i < len1; i++)
        num1[i] -= '0';
    for (int i = 0; i < len2; i++)
        num2[i] -= '0';
    int ress = 1000;
    char *res = (char *)calloc(ress, sizeof(char));
    for (int i = len1 - 1; i >= 0; i--)
    {
        for (int j = len2 - 1; j >= 0; j--)
        {
            pos = len2 - 1 - j + len1 - 1 - i;
            cur = num1[i] * num2[j];
            while (cur > 0)
            {
                cur += res[pos];
                res[pos++] = cur % 10;
                cur /= 10;
            }
        }
    }
    while (lenr - 1 >= 0 && res[lenr - 1] == 0)
        lenr--;
    for (int i = 0; i < lenr; i++)
        printf("%d ", res[i]);
    for (int i = 0; i < lenr; i++)
        res[i] += '0';
    res[lenr] = '\0';
    for (int k = 0; k < lenr / 2; k++)
    {
        char temp;
        temp = res[k];
        res[k] = res[lenr - 1 - k];
        res[lenr - 1 - k] = temp;
    }
    if (lenr == 0)
        res[0] = '0';
    return res;
}
// @lc code=end
//+ (res[pos] != 0 ? str[res[pos]] : 0)