/*
 * @lc app=leetcode id=52 lang=c
 *
 * [52] N-Queens II
 */
#include "header\leetcode.h"

// @lc code=start

bool check(char **board, int x, int y, int boardsize)
{
    // check col
    for (int i = 0; i < boardsize; i++)
        if (board[i][y] == 'Q')
            return false;
    // check rows
    for (int i = 0; i < boardsize; i++)
        if (board[x][i] == 'Q')
            return false;
    // check diagonally;

    for (int i = 1; i < boardsize; i++)
    {
        if (x - i < 0 || y - i < 0)
            break;
        if (board[x - i][y - i] == 'Q')
            return false;
    }
    for (int i = 1; i < boardsize; i++)
    {
        if (x - i < 0 || y + i >= boardsize)
            break;
        if (board[x - i][y + i] == 'Q')
            return false;
    }
    for (int i = 1; i < boardsize; i++)
    {
        if (x + i >= boardsize || y + i >= boardsize)
            break;
        if (board[x + i][y + i] == 'Q')
            return false;
    }
    for (int i = 1; i < boardsize; i++)
    {
        if (y - i < 0 || x + i >= boardsize)
            break;
        if (board[x + i][y - i] == 'Q')
            return false;
    }
    return true;
}
void helper(char **board, int x, int y, int n, int queens, int *res)
{
    // printf("x:%d y:%d queens:%d\n", x, y, queens);
    if (queens == n)
    {
        (*res)++;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (check(board, i, y, n))
        {
            board[i][y] = 'Q';
            helper(board, i, y + 1, n, queens + 1, res);
            board[i][y] = '.';
        }
    }
}
int totalNQueens(int n)
{
    char **board = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++)
        board[i] = (char *)malloc(n * sizeof(char));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            board[i][j] = '.';
    int res = 0;
    helper(board, 0, 0, n, 0, &res);
    for (int i = 0; i < n; i++)
        free(board[i]);
    free(board);
    return res;
}

// @lc code=end
