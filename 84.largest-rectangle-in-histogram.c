/*
 * @lc app=leetcode id=84 lang=c
 *
 * [84] Largest Rectangle in Histogram
 */
#include "header\leetcode.h"

// @lc code=start

int largestRectangleArea(int *heights, int heightsSize)
{
    int res = 0;
    int stack[10000];
    int top = -1;
    for (int i = 0; i < heightsSize; i++)
    {
        if (top == -1 || heights[i] > heights[stack[top]])
        {
            stack[++top] = i;
        }
        else
        {
            int sum = 0;
            while (top != -1 && heights[i] <= heights[stack[top]])
            {
                int pop = stack[top];
                top--;
                res = fmax(res, heights[pop] * (top == -1 ? i : i - stack[top] - 1));
            }
            stack[++top] = i;
        }
    }
    while (top != -1)
    {
        int pop = stack[top];
        top--;
        res = fmax(res, heights[pop] * (top == -1 ? heightsSize : heightsSize - stack[top] - 1));
    }
    return res;
}
// @lc code=end
