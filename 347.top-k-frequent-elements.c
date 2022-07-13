/*
 * @lc app=leetcode id=347 lang=c
 *
 * [347] Top K Frequent Elements
 */
#include "header\leetcode.h"

// @lc code=start

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define abs(a) (((a) < 0) ? -(a) : (a))
#define MAPSIZE 100000

int map[MAPSIZE][2];
int findAddress(int key)
{
    int address = key % MAPSIZE;
    address = abs(address);
    while (map[address][1] != 0 && map[address][0] != key)
        address = address + 1 % MAPSIZE;
    return address;
}
int cmp(int *a, int *b)
{
    return map[findAddress(*b)][1] - map[findAddress(*a)][1];
}
int *topKFrequent(int *nums, int numsSize, int k, int *returnSize)
{
    memset(map, 0, 2 * sizeof(int) * MAPSIZE);
    int arr[10000];
    int size = 0;
    int *res = (int *)malloc(sizeof(int) * k);
    *returnSize = k;
    for (int i = 0; i < numsSize; i++)
    {
        int address = findAddress(nums[i]);
        if (map[address][1] == 0)
        {
            arr[size++] = nums[i];
        }
        map[address][0] = nums[i];
        map[address][1]++;
    }
    // for (int i = 0; i < size; i++)
    //     printf("%d ", arr[i]);
    // printf("\n");
    qsort(arr, size, sizeof(int), cmp);
    // for (int i = 0; i < size; i++)
    //     printf("%d ", arr[i]);
    // printf("\n");
    memcpy(res, arr, sizeof(int) * k);
    return res;
}
// @lc code=end
