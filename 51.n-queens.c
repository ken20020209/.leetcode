/*
 * @lc app=leetcode id=51 lang=c
 *
 * [51] N-Queens
 */
#include "header\leetcode.h"

// @lc code=start

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
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
void helper(char **board, int x, int y, int n, int queens, char ***res, int *returnSize, int **returnColumnSizes)
{
    // printf("x:%d y:%d queens:%d\n", x, y, queens);
    if (queens == n)
    {

        (*returnColumnSizes)[*returnSize] = n;
        res[*returnSize] = (char **)malloc(n * sizeof(char *));
        for (int j = 0; j < n; j++)
        {
            res[*returnSize][j] = (char *)calloc(n + 1, sizeof(char));
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                res[*returnSize][i][j] = board[i][j];
            }
            res[*returnSize][i][n] = '\0';
        }
        (*returnSize)++;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (check(board, i, y, n))
        {
            board[i][y] = 'Q';
            helper(board, i, y + 1, n, queens + 1, res, returnSize, returnColumnSizes);
            board[i][y] = '.';
        }
    }
}
char ***solveNQueens(int n, int *returnSize, int **returnColumnSizes)
{
    char **board = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++)
        board[i] = (char *)malloc(n * sizeof(char));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            board[i][j] = '.';
    int retsize = n * n * n;
    *returnSize = 0;
    char ***res = (char ***)malloc(retsize * sizeof(char **));
    *returnColumnSizes = (int *)malloc(retsize * sizeof(int));

    helper(board, 0, 0, n, 0, res, returnSize, returnColumnSizes);

    for (int i = 0; i < n; i++)
        free(board[i]);
    free(board);
    // for (int i = 0; i < *returnSize; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         printf("%s\n", res[i][j]);
    //     }
    //     printf("\n");
    // }
    return res;
}
// @lc code=end
