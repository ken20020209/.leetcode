/*
 * @lc app=leetcode id=1823 lang=c
 *
 * [1823] Find the Winner of the Circular Game
 */
#include "header\leetcode.h"

// @lc code=start

// int findTheWinner(int n, int k)
// {
//     int queue[600];
//     int qsize = 0;
//     int front = 0;
//     int rear = -1;
//     for (int i = 1; i <= n; i++)
//     {
//         queue[++rear] = i;
//         qsize++;
//     }
//     while (qsize != 1)
//     {
//         for (int i = 0; i < k - 1; i++)
//         {
//             rear++;
//             rear %= 600;
//             front %= 600;
//             queue[rear] = queue[front];
//             front++;
//         }
//         front++;
//         qsize--;
//     }
//     return queue[rear];
// }
int helper(int n, int k)
{
    if (n == 1)
        return 0;
    return (helper(n - 1, k) + k) % n;
}
int findTheWinner(int n, int k)
{
    return helper(n, k) + 1;
}
// @lc code=end
