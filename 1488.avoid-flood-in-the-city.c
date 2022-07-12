/*
 * @lc app=leetcode id=1488 lang=c
 *
 * [1488] Avoid Flood in The City
 */
#include "header\leetcode.h"

// @lc code=start

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAPSIZE 100000
struct pair
{
    int key;
    int val;
    int pos;
};
int *avoidFlood(int *rains, int rainsSize, int *returnSize)
{
    int *res = (int *)malloc(sizeof(int) * rainsSize);
    int temp[MAPSIZE];
    int *arr = temp;
    struct pair map[MAPSIZE] = {0};

    int size = 0;
    *returnSize = rainsSize;
    for (int i = 0; i < rainsSize; i++)
    {
        if (rains[i] == 0)
        {
            arr[size++] = i;
        }
        else
        {
            res[i] = -1;
            int address = rains[i] % MAPSIZE;
            while (map[address].key != 0 && map[address].key != rains[i])
            {
                address = (address + 1) % MAPSIZE;
            }
            map[address].key = rains[i];
            if (map[address].val == 1)
            {
                int pos = -1;
                int high = size - 1;
                int low = 0;
                int mid;
                while (low <= high)
                {
                    mid = low + (high - low) / 2;
                    if (arr[mid] > map[address].pos)
                    {
                        pos = mid;
                        high = mid - 1;
                    }
                    else
                    {
                        low = mid + 1;
                    }
                }
                if (pos == -1)
                {
                    *returnSize = 0;
                    break;
                }
                size--;
                res[arr[pos]] = rains[i];
                for (int i = pos; i > 0; i--)
                {
                    arr[i] = arr[i - 1];
                }
                arr++;
                map[address].pos = i;
            }
            else
            {
                map[address].val = 1;
                map[address].pos = i;
            }
        }
    }
    while (size != 0)
    {
        res[arr[--size]] = 1;
    }

    return res;
}
// @lc code=end
