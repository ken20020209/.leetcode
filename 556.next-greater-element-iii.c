/*
 * @lc app=leetcode id=556 lang=c
 *
 * [556] Next Greater Element III
 */
#include "header\leetcode.h"

// @lc code=start
void swap(char *a, char *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int cmp(char *a, char *b)
{
    return *a - *b;
}
int nextGreaterElement(int n)
{
    char temp[12];
    int a = n;
    int len = 0;
    int pos;
    int min;
    long int res = 0;
    while (n != 0)
    {
        temp[len++] = n % 10 + '0';
        n /= 10;
    }
    n = -1;
    temp[len] = '\0';
    for (int i = 0; i < len / 2; i++)
    {
        swap(&temp[i], &temp[len - 1 - i]);
    }
    for (int i = len - 2; i >= 0; i--)
    {
        min = INT_MAX;
        for (int j = len - 1; j > i; j--)
        {
            if (temp[j] > temp[i])
            {
                if (temp[j] < min)
                {
                    min = temp[j];
                    pos = j;
                }
            }
        }
        if (min != INT_MAX)
        {
            swap(&temp[i], &temp[pos]);
            pos = i;
            qsort(temp + pos + 1, len - pos - 1, sizeof(char), cmp);

            for (int i = 0; i < len; i++)
            {
                res = res * 10 + temp[i] - '0';
            }
            break;
        }
    }
    if (res == 0)
        res = -1;
    return res > INT_MAX ? -1 : res;
}
// @lc code=end
