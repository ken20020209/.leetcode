/*
 * @lc app=leetcode id=1249 lang=c
 *
 * [1249] Minimum Remove to Make Valid Parentheses
 */
#include "header\leetcode.h"

// @lc code=start

char *minRemoveToMakeValid(char *s)
{
    int openSt[1000] = {0};
    int closeSt[1000] = {0};
    int openTop = -1;
    int closeTop = -1;
    int len = strlen(s);
    for (int i = 0; i < len; i++)
    {
        if (s[i] == '(')
        {
            openSt[++openTop] = i;
        }
        else if (s[i] == ')')
        {
            if (openTop != -1)
            {
                openTop--;
            }
            else
            {
                closeSt[++closeTop] = i;
            }
        }
    }
    while (openTop != -1)
    {
        s[openSt[openTop--]] = 0;
    }
    while (closeTop != -1)
    {
        s[closeSt[closeTop--]] = 0;
    }
    int left = 0;

    for (int i = 0; i < len; i++)
    {
        // for (int i = 0; i < len; i++)
        // {
        //     printf("%c ", s[i]);
        // }
        // printf("\n");
        if (s[i] != 0)
        {
            char temp = s[i];
            s[i] = s[left];
            s[left] = temp;
            left++;
        }
    }
    return s;
}
// @lc code=end
