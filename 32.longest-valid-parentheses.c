/*
 * @lc app=leetcode id=32 lang=c
 *
 * [32] Longest Valid Parentheses
 */
#include "header\leetcode.h"

// @lc code=start

int longestValidParentheses(char *s)
{

    int stack[100000];
    int top = -1;
    int preOpen = -1;
    int res = 0;
    int cnt = 0;
    int len = strlen(s);
    for (int i = 0; i < len; i++)
    {
        if (s[i] == ')')
        {
            if (preOpen == -1)
            {
                stack[++top] = -1;
            }
            else
            {
                stack[preOpen] = 2;
                int j;
                for (j = preOpen - 1; j >= 0; j--)
                {
                    if (stack[j] == 1)
                    {
                        break;
                    }
                    if (stack[j] == -1)
                        j = 0;
                }
                preOpen = j;
            }
        }
        else if (s[i] == '(')
        {
            stack[++top] = 1;
            preOpen = top;
        }
        else
        {
            printf("error\n");
            return -1;
        }
    }
    for (int i = 0; i <= top; i++)
    {
        // printf("%d ", stack[i]);
        if (stack[i] == -1 || stack[i] == 1)
        {
            cnt = 0;
        }
        else
        {
            cnt += 2;
        }
        res = fmax(cnt, res);
    }
    return res;
}
// @lc code=end
