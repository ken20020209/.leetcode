/*
 * @lc app=leetcode id=150 lang=c
 *
 * [150] Evaluate Reverse Polish Notation
 */
#include "header\leetcode.h"

// @lc code=start

int evalRPN(char **tokens, int tokensSize)
{
    int stack[10000];
    int top = -1;
    int a, b;
    for (int i = 0; i < tokensSize; i++)
    {
        if (strlen(tokens[i]) > 1)
        {
            stack[++top] = atoi(tokens[i]);
        }
        else
        {
            switch (tokens[i][0])
            {
            case '+':
                b = stack[top--];
                a = stack[top--];
                stack[++top] = a + b;
                break;
            case '-':
                b = stack[top--];
                a = stack[top--];
                stack[++top] = a - b;
                break;
            case '*':
                b = stack[top--];
                a = stack[top--];
                stack[++top] = a * b;
                break;
            case '/':
                b = stack[top--];
                a = stack[top--];
                stack[++top] = a / b;
                break;
            default:
                stack[++top] = atoi(tokens[i]);
                break;
            }
        }
    }
    return stack[top];
}
// @lc code=end
