/*
 * @lc app=leetcode id=71 lang=c
 *
 * [71] Simplify Path
 */
#include "header\leetcode.h"

// @lc code=start

char *simplifyPath(char *path)
{
    char *stack[3000];
    char buf[1000];
    int buftop = -1;
    int top = -1;
    int len = strlen(path);
    for (int i = 0; i < len; i++)
    {
        if (path[i] == '/')
            continue;
        buftop = -1;
        while (i < len && path[i] != '/')
        {
            buf[++buftop] = path[i];
            i++;
        }
        if (buf[0] == '.' && buf[1] == '.' && buftop == 1)
        {
            if (top != -1)
            {
                free(stack[top]);
                top--;
            }
        }
        else if (buf[0] == '.' && buftop == 0)
        {
            continue;
        }
        else
        {
            stack[++top] = (char *)malloc(buftop + 2);
            stack[top][buftop + 1] = '\0';
            memcpy(stack[top], buf, buftop + 1);
        }
        buf[0] = 0;
        buf[1] = 0;
    }
    path[0] = '\0';
    for (int i = 0; i <= top; i++)
    {
        strcat(path, "/");
        strcat(path, stack[i]);
        free(stack[i]);
    }
    if (path[0] == '\0')
        strcat(path, "/");
    return path;
}
// @lc code=end
