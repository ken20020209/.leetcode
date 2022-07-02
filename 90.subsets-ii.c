/*
 * @lc app=leetcode id=90 lang=c
 *
 * [90] Subsets II
 */
#include "header\leetcode.h"

// @lc code=start

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define MAPSIZE 3000
int cmp(int *a, int *b)
{
    return *a - *b;
}
long int hashval(int *nums, int size)
{
    long int hash = 0;
    for (int i = 0; i < size; i++)
    {
        hash = hash * 10 + 10 + nums[i];
    }
    return hash;
}
void helper(int *nums, int numsSize, int **res, int *returnSize, int **returnColumnSizes, int index, int size, int *arr, long int *map)
{

    arr[size++] = nums[index];
    int temp[20];

    for (int i = 0; i < size; i++)
    {
        temp[i] = arr[i];
    }
    qsort(temp, size, sizeof(int), cmp);
    long int hash = hashval(temp, size);
    int address = hash % MAPSIZE;
    while (map[address] != -1 && map[address] != hash)
    {
        address = address + 1 % MAPSIZE;
    }
    if (map[address] == -1)
    {
        map[address] = hash;
        (*returnSize)++;
        (*returnColumnSizes)[*returnSize - 1] = size;
        res[*returnSize - 1] = (int *)malloc(size * sizeof(int));

        memcpy(res[*returnSize - 1], temp, size * sizeof(int));
    }

    for (int i = index + 1; i < numsSize; i++)
    {
        helper(nums, numsSize, res, returnSize, returnColumnSizes, i, size, arr, map);
    }
}
int **subsets(int *nums, int numsSize, int *returnSize, int **returnColumnSizes)
{
    int temp = 0;
    *returnSize = 1;
    int resCapacity = 1500;
    long int map[MAPSIZE] = {0};
    memset(map, -1, sizeof(long int) * MAPSIZE);
    int *arr = (int *)malloc(numsSize * sizeof(int));
    int **res = (int **)malloc(resCapacity * sizeof(int *));
    *returnColumnSizes = (int *)malloc(resCapacity * sizeof(int));
    res[*returnSize - 1] = (int *)malloc(0);
    (*returnColumnSizes)[0] = 0;

    for (int i = 0; i < numsSize; i++)
    {
        helper(nums, numsSize, res, returnSize, returnColumnSizes, i, 0, arr, map);
    }
    free(arr);
    return res;
}
int **subsetsWithDup(int *nums, int numsSize, int *returnSize, int **returnColumnSizes)
{
    return subsets(nums, numsSize, returnSize, returnColumnSizes);
}
// @lc code=end
