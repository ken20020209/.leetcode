/*
 * @lc app=leetcode id=47 lang=c
 *
 * [47] Permutations II
 */
#include "header\leetcode.h"

// @lc code=start

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int hash(int *arr, int size)
{
    int hash = 0;
    // printf("size = %d\n", size);
    for (int i = 0; i < size; i++)
    {
        // printf("hash:%d\n", hash);
        hash = hash * 10 + arr[i];
    }
    return hash;
}
void swap(int *nums, int x, int y)
{
    int temp = nums[x];
    nums[x] = nums[y];
    nums[y] = temp;
}
void getResult(int **out, int *nums, int numsSize, int left, int right, int *size, int *map)
{
    if (left == right)
    {
        int key = hash(nums, numsSize);
        int address = key % 100000;
        address = address < 0 ? -address : address;
        while (map[address] != 0 && map[address] != key)
        {
            address = (address + 1) % 100000;
        }

        if (map[address] == 0)
        {
            map[address] = key;
            out[*size] = (int *)malloc(numsSize * sizeof(int));
            memcpy(out[(*size)++], nums, numsSize * sizeof(int));
        }
        return;
    }
    for (int i = left; i <= right; i++)
    {
        swap(nums, left, i);
        getResult(out, nums, numsSize, left + 1, right, size, map);
        swap(nums, left, i);
    }
}

int **permute(int *nums, int numsSize, int *returnSize, int **returnColumnSizes)
{
    int **result = (int **)malloc(1000 * sizeof(int *));
    int *temp = (int *)malloc(numsSize * sizeof(int));
    int size = 0;
    int *map[100000] = {0};
    getResult(result, nums, numsSize, 0, numsSize - 1, &size, map);
    *returnColumnSizes = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
        (*returnColumnSizes)[i] = numsSize;
    *returnSize = size;
    return result;
}
int **permuteUnique(int *nums, int numsSize, int *returnSize, int **returnColumnSizes)
{
    return permute(nums, numsSize, returnSize, returnColumnSizes);
}
// @lc code=end
