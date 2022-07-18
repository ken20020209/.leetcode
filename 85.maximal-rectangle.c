/*
 * @lc app=leetcode id=85 lang=c
 *
 * [85] Maximal Rectangle
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
int maximalRectangle(char **matrix, int matrixSize, int *matrixColSize)
{
    int *heights = (int *)calloc(*matrixColSize, sizeof(int));
    int res = 0;
    for (int i = 0; i < matrixSize; i++)
    {
        for (int j = 0; j < *matrixColSize; j++)
        {
            if (matrix[i][j] == '1')
                heights[j]++;
            else
                heights[j] = 0;
        }
        res = fmax(res, largestRectangleArea(heights, *matrixColSize));
    }
    return res;
}
// @lc code=end
