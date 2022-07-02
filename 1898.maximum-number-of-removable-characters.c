/*
 * @lc app=leetcode id=1898 lang=c
 *
 * [1898] Maximum Number of Removable Characters
 */
#include "header\leetcode.h"

// @lc code=start
int checksq(char *s, char *p)
{
    while (*s != '\0' && *p != '\0')
    {
        if (*p == *s)
            p++;
        s++;
    }
    if (*p == '\0')
        return true;
    else
        return false;
}
int maximumRemovals(char *s, char *p, int *removable, int removableSize)
{
    int len = strlen(s);
    char *temp = (char *)malloc(len * sizeof(char));
    int high = removableSize - 1;
    int low = 0;
    int mid;
    int res = -1;
    int premid = -1;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        // printf("mid: %d\n", mid);
        if (mid > premid)
        {
            if (premid == -1)
                premid = 0;
            for (int i = premid; i <= mid; i++)
            {

                temp[removable[i]] = s[removable[i]];
                s[removable[i]] = '#';
            }
        }
        else
        {
            for (int i = premid; i > mid; i--)
            {
                s[removable[i]] = temp[removable[i]];
            }
        }
        // printf("%s\n", s);
        if (checksq(s, p) == true)
        {
            res = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
        premid = mid;
    }
    free(temp);
    return res + 1;
}
// @lc code=end
