/*
 * @lc app=leetcode id=38 lang=c
 *
 * [38] Count and Say
 */
#include "header\leetcode.h"

// @lc code=start
char buf[10000];
char res[10000];
char *countAndSay(int n)
{
    sprintf(res, "%d\0", 1);
    for (int i = 1; i < n; i++)
    {
        int len = strlen(res);
        int bufSize = 0;
        int cnt = 1;
        int cur;
        cur = res[0];
        for (int j = 1; j <= len; j++)
        {
            if (cur == res[j])
            {
                cnt++;
            }
            else
            {
                sprintf(buf + bufSize, "%d%c\0", cnt, cur);
                bufSize += 2;
                cur = res[j];
                cnt = 1;
            }
        }
        memcpy(res, buf, sizeof(char) * (bufSize + 1));
        // printf("%s\n", buf);
    }
    return res;
}
// @lc code=end
