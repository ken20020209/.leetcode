/*
 * @lc app=leetcode id=79 lang=c
 *
 * [79] Word Search
 */
#include "header\leetcode.h"

// @lc code=start
bool dfs(char **g, int x, int y, int max_x, int max_y, char *word, int wordsize)
{
    // printf("    x: %d y: %d\n", x, y);
    // printf("    wordsize: %d\n", wordsize);
    if (wordsize == 0)
        return true;
    if (g[x][y] == '#')
        return false;
    char temp = g[x][y];
    bool res = false;

    g[x][y] = '#';
    if (x + 1 < max_x && g[x + 1][y] == word[wordsize - 1])
        res |= dfs(g, x + 1, y, max_x, max_y, word, wordsize - 1);
    // printf("test\n");
    if (x - 1 >= 0 && g[x - 1][y] == word[wordsize - 1])
        res |= dfs(g, x - 1, y, max_x, max_y, word, wordsize - 1);
    // printf("test\n");
    if (y + 1 < max_y && g[x][y + 1] == word[wordsize - 1])
        res |= dfs(g, x, y + 1, max_x, max_y, word, wordsize - 1);
    // printf("test\n");
    if (y - 1 >= 0 && g[x][y - 1] == word[wordsize - 1])
        res |= dfs(g, x, y - 1, max_x, max_y, word, wordsize - 1);
    // printf("test\n");
    g[x][y] = temp;
    return res;
}
bool exist(char **board, int boardSize, int *boardColSize, char *word)
{
    for (int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < *boardColSize; j++)
        {
            // printf("i:%d j:%d\n", i, j);
            if (board[i][j] == word[strlen(word) - 1] && dfs(board, i, j, boardSize, *boardColSize, word, strlen(word) - 1))
                return true;
        }
    }
    return false;
}
// @lc code=end
