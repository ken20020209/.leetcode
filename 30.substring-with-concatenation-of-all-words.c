/*
 * @lc app=leetcode id=30 lang=c
 *
 * [30] Substring with Concatenation of All Words
 */
#include "header\leetcode.h"

// @lc code=start

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAPSIZE 10000
#define printf //
int BKDhash(char *s)
{
    long res = 0;
    while (*s)
    {
        res = res * 31 + *s;
        res &= 0xffffffff;
        s++;
    }
    return res & 0x7fffffff;
}
int findAddress(char *mapkey[], char *key)
{
    int address = BKDhash(key) % MAPSIZE;
    while (mapkey[address] != 0 && strcmp(mapkey[address], key) != 0)
        address = address + 1 % MAPSIZE;
    return address;
}
// check with every index at s
int *findSubstring(char *s, char **words, int wordsSize, int *returnSize)
{
    char *key[MAPSIZE] = {0};
    int val[MAPSIZE] = {0};
    char temp[40];
    int capacity = 2;
    *returnSize = 0;
    int *res = (int *)malloc(capacity * sizeof(int));
    for (int i = 0; i < wordsSize; i++)
    {
        int address = findAddress(key, words[i]);
        key[address] = words[i];
        val[address]++;
    }
    int lens = strlen(s);
    int lenw = strlen(*words);
    for (int i = 0; i + lenw * wordsSize <= lens; i++)
    {
        printf("i:%d\n", i);
        for (int j = 0; j < wordsSize; j++)
        {
            printf("    j:%d\n", j);
            memcpy(temp, s + i + j * lenw, sizeof(char) * (lenw));
            temp[lenw] = '\0';
            int address = findAddress(key, temp);
            printf("    address:%d\n", address);
            printf("    temp:%s\n", temp);
            if (key[address] != 0)
            {
                val[address]--;
            }
        }
        int j;
        printf("check val\n");
        for (j = 0; j < MAPSIZE; j++)
        {
            if (val[j] != 0)
                break;
        }
        printf("add res\n");
        if (j == MAPSIZE)
        {
            if (*returnSize == capacity)
            {
                capacity *= 2;
                res = (int *)realloc(res, capacity * sizeof(int));
            }
            res[*returnSize] = i;
            (*returnSize)++;
        }
        memset(val, 0, MAPSIZE * sizeof(int));
        printf("reset map\n");
        for (int j = 0; j < wordsSize; j++)
        {
            int address = findAddress(key, words[j]);
            key[address] = words[j];
            val[address]++;
        }
    }
    return res;
}
// @lc code=end
