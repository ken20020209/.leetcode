/*
 * @lc app=leetcode id=37 lang=c
 *
 * [37] Sudoku Solver
 */
#include "header\leetcode.h"

// @lc code=start
void printfBoard(char **board)
{
    printf("\n");
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
bool checker(char **board, int x, int y, char num)
{
    // check row
    for (int i = 0; i < 9; i++)
    {
        if (board[x][i] == num)
        {
            return false;
        }
    }
    // check column
    for (int i = 0; i < 9; i++)
    {
        if (i == x)
            continue;
        if (board[i][y] == num)
        {
            return false;
        }
    }
    // check square
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i + (x / 3) * 3][j + (y / 3) * 3] == num)
            {
                return false;
            }
        }
    }
    return true;
}
void helper(char **board, int x, int y, int *flag)
{
    // printf("x:%d y:%d flag:%d\n", x, y, *flag);
    if (y == 9)
    {
        if (x == 8)
        {
            printf("finded\n");
            *flag = 1;
            return;
        }
        y = 0;
        helper(board, x + 1, y, flag);
        return;
    }
    if (board[x][y] == '.')
    {
        for (int i = '1'; i <= '9'; i++)
        {
            if (checker(board, x, y, i))
            {
                board[x][y] = i;
                // printfBoard(board);
                helper(board, x, y + 1, flag);
                if (*flag == 0)
                    board[x][y] = '.';
            }
        }
    }
    else
    {
        helper(board, x, y + 1, flag);
    }
}
void solveSudoku(char **board, int boardSize, int *boardColSize)
{
    int blank[9][9] = {0};
    int flag = 0;
    helper(board, 0, 0, &flag);
}
// @lc code=end
