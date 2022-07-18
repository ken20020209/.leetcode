/*
 * @lc app=leetcode id=76 lang=c
 *
 * [76] Minimum Window Substring
 */
#include "header\leetcode.h"

// @lc code=start

char *minWindow(char *s, char *t)
{
    int mapt[128] = {0};
    int maps[128] = {0};
    int lens = strlen(s);
    int lent = strlen(t);
    int ansleft = -1;
    int ansright = lens;
    int left = 0;
    int right = 0;
    int flag = 0;
    for (int i = 0; i < lent; i++)
    {
        mapt[t[i]]++;
    }
    while (s[right])
    {
        maps[s[right]]++;
        flag = 0;
        for (int i = 0; i < 128; i++)
        {
            if (maps[i] < mapt[i])
            {
                flag = 1;
                break;
            }
        }
        while (flag == 0)
        {
            if (right - left < ansright - ansleft)
            {
                ansright = right;
                ansleft = left;
            }
            maps[s[left]]--;
            left++;
            for (int i = 0; i < 128; i++)
            {
                if (maps[i] < mapt[i])
                {
                    flag = 1;
                    break;
                }
            }
        }
        right++;
    }
    // printf("ansleft: %d\n", ansleft);
    // printf("ansright: %d\n", ansright);
    if (ansleft == -1)
        return "";
    char *res = malloc(ansright - ansleft + 2);
    res[ansright - ansleft + 1] = 0;
    for (int i = ansleft; i <= ansright; i++)
    {
        res[i - ansleft] = s[i];
    }
    return res;
}
// @lc code=end
