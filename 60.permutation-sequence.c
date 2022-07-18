/*
 * @lc app=leetcode id=60 lang=c
 *
 * [60] Permutation Sequence
 */
#include "header\leetcode.h"

// @lc code=start
int factorials[11];
int factorial(int n)
{
    if (factorials[n] != 0)
        return factorials[n];
    if (n == 1 || n == 0)
        return 1;
    return factorials[n] = (n * factorial(n - 1));
}
char *getPermutation(int n, int k)
{
    char arr[n];
    char *res = malloc(n + 1);
    char buf[2] = {0};
    res[0] = '\0';
    for (int i = 0; i < n; i++)
        arr[i] = i + '1';
    for (int i = 0; i < n; i++)
    {
        int perGroup = factorial(n - 1 - i);
        int Group = (k - 1) / perGroup;
        k = k % perGroup;
        k = k == 0 ? perGroup : k;
        buf[0] = arr[Group];
        strcat(res, buf);
        for (int i = Group; i < n - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
    }
    return res;
}
// @lc code=end
