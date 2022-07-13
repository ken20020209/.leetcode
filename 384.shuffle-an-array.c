/*
 * @lc app=leetcode id=384 lang=c
 *
 * [384] Shuffle an Array
 */
#include "header\leetcode.h"

// @lc code=start

typedef struct
{
    int size;
    int *randarr;
    int *arr;
} Solution;
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
Solution *solutionCreate(int *nums, int numsSize)
{
    Solution *obj = (Solution *)malloc(sizeof(Solution));
    obj->size = numsSize;
    obj->arr = (int *)malloc(sizeof(int) * numsSize);
    obj->randarr = (int *)malloc(sizeof(int) * numsSize);
    memcpy(obj->arr, nums, numsSize * sizeof(int));
    memcpy(obj->randarr, nums, numsSize * sizeof(int));
    return obj;
}

int *solutionReset(Solution *obj, int *retSize)
{
    *retSize = obj->size;
    return obj->arr;
}

int *solutionShuffle(Solution *obj, int *retSize)
{
    *retSize = obj->size;
    for (int i = 0; i < obj->size; i++)
    {
        int random = rand() % obj->size;
        swap(&obj->randarr[i], &obj->randarr[random]);
    }
    return obj->randarr;
}

void solutionFree(Solution *obj)
{
    free(obj->randarr);
    free(obj->arr);
    free(obj);
}

/**
 * Your Solution struct will be instantiated and called as such:
 * Solution* obj = solutionCreate(nums, numsSize);
 * int* param_1 = solutionReset(obj, retSize);

 * int* param_2 = solutionShuffle(obj, retSize);

 * solutionFree(obj);
*/
// @lc code=end
