/*
 * @lc app=leetcode id=68 lang=c
 *
 * [68] Text Justification
 */
#include "header\leetcode.h"

// @lc code=start

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

char **fullJustify(char **words, int wordsSize, int maxWidth, int *returnSize)
{
    int capacity = 20;
    *returnSize = 0;
    char **res = (char **)malloc(capacity * sizeof(char *));
    char *buf = (char *)malloc((maxWidth + 1) * sizeof(char));
    buf[maxWidth] = '\0';
    char *queue[1000];
    int rear = -1;
    int left = maxWidth;
    for (int i = 0; i < wordsSize; i++)
    {
        int len = strlen(words[i]);

        if (left - len - rear <= 0)
        {
            int space = left;
            int leftspace = rear == 0 ? space : space % rear;
            int rightspace = rear == 0 ? 0 : space / rear;
            int pos = 0;
            memset(buf, ' ', maxWidth * sizeof(char));
            if (rear == 0)
            {
                memcpy(buf, queue[0], strlen(queue[0]));
            }
            else
            {
                for (int j = 0; j <= rear; j++)
                {
                    // printf("    %s\n", queue[j]);

                    memcpy(buf + pos, queue[j], strlen(queue[j]));
                    // printf("    buf:%s\n", buf);
                    // printf("    leftspace:%d\n", leftspace);
                    pos += strlen(queue[j]) + rightspace + (leftspace-- <= 0 ? 0 : 1);
                }
            }
            // printf("buf:%s\n", buf);
            res[*returnSize] = (char *)malloc((maxWidth + 1) * sizeof(char));
            memcpy(res[*returnSize], buf, (maxWidth + 1) * sizeof(char));
            (*returnSize)++;
            rear = -1;
            left = maxWidth;
        }
        left -= len;
        queue[++rear] = words[i];
    }
    memset(buf, ' ', maxWidth * sizeof(char));
    int pos = 0;
    for (int j = 0; j <= rear; j++)
    {
        memcpy(buf + pos, queue[j], strlen(queue[j]));
        pos += strlen(queue[j]) + 1;
    }
    // printf("buf:%s\n", buf);
    res[*returnSize] = (char *)malloc((maxWidth + 1) * sizeof(char));
    memcpy(res[*returnSize], buf, (maxWidth + 1) * sizeof(char));
    (*returnSize)++;
    free(buf);
    return res;
}
// @lc code=end
