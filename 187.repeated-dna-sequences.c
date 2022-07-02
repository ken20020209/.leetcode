/*
 * @lc app=leetcode id=187 lang=c
 *
 * [187] Repeated DNA Sequences
 */
#include "header\leetcode.h"

// @lc code=start

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct statebit
{
    int bit0 : 2;
    int bit1 : 2;
    int bit2 : 2;
    int bit3 : 2;
    int bit4 : 2;
    int bit5 : 2;
    int bit6 : 2;
    int bit7 : 2;
    int bit8 : 2;
    int bit9 : 2;
};
union statedna
{
    int hash;
    struct statebit state;
};

char **findRepeatedDnaSequences(char *s, int *returnSize)
{
    int len = strlen(s);
    int dna[256] = {0};
    int mapsize = 100000;
    // map[i][0]=key;
    // map[i][1]=0 no fine , 1 fine 2 on res;
    int map[100000][2] = {0};
    *returnSize = 0;
    if (len <= 10)
        return NULL;
    char **res = (char **)malloc((*returnSize + 1) * sizeof(char *));
    dna['A'] = 0;
    dna['C'] = 1;
    dna['G'] = 2;
    dna['T'] = 3;
    union statedna statedna;
    statedna.hash = 0;
    statedna.state.bit0 = dna[s[0]];
    statedna.state.bit1 = dna[s[1]];
    statedna.state.bit2 = dna[s[2]];
    statedna.state.bit3 = dna[s[3]];
    statedna.state.bit4 = dna[s[4]];
    statedna.state.bit5 = dna[s[5]];
    statedna.state.bit6 = dna[s[6]];
    statedna.state.bit7 = dna[s[7]];
    statedna.state.bit8 = dna[s[8]];
    statedna.state.bit9 = dna[s[9]];
    for (int i = 10; i <= len; i++)
    {
        int address = statedna.hash % mapsize;
        if (map[address][0] == 0 && map[address][1] == 0)
        {
            map[address][0] = statedna.hash;
            map[address][1] = 1;
        }
        else if (map[address][0] == statedna.hash)
        {
            if (map[address][1] == 1)
            {

                map[address][1] = 2;
                res = (char **)realloc(res, (*returnSize + 1) * sizeof(char *));
                res[*returnSize] = (char *)malloc(11 * sizeof(char));
                memcpy(res[*returnSize], s + i - 10, 10 * sizeof(char));

                res[*returnSize][10] = 0;

                (*returnSize)++;
            }
        }
        if (i == len)
            break;
        statedna.hash >>= 2;
        statedna.state.bit9 = dna[s[i]];
    }
    return res;
}
// @lc code=end
