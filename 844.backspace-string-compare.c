/*
 * @lc app=leetcode id=844 lang=c
 *
 * [844] Backspace String Compare
 */
#include "header\leetcode.h"

// @lc code=start

bool backspaceCompare(char *s, char *t)
{
    int lens = strlen(s) - 1;
    int lent = strlen(t) - 1;
    int cnt;
    while (lens >= 0 || lent >= 0)
    {
        cnt = 0;
        for (int i = lens; i >= lens - cnt; i--)
            if (i >= 0 && s[i] == '#')
            {
                cnt++;
                lens--;
            }
        lens -= cnt;
        cnt = 0;
        for (int i = lent; i >= lent - cnt; i--)
            if (i >= 0 && t[i] == '#')
            {
                cnt++;
                lent--;
            }

        lent -= cnt;
        // printf("ls:%d lt:%d\n", lens,lent);
        if (lens >= 0 && lent < 0)
            return false;
        if (lent >= 0 && lens < 0)
            return false;
        if ((lens >= 0 && lent >= 0 && s[lens] != t[lent]))
            return false;
        lens--;
        lent--;
    }
    return true;
}
// @lc code=end
