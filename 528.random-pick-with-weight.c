/*
 * @lc app=leetcode id=528 lang=c
 *
 * [528] Random Pick with Weight
 */
#include "header\leetcode.h"

// @lc code=start

typedef struct
{
    int size;
    int sum;
    int *probability;

} Solution;

Solution *solutionCreate(int *w, int wSize)
{
    srand(time(NULL));
    Solution *obj = (Solution *)malloc(sizeof(Solution));
    obj->size = wSize;
    obj->probability = (int *)malloc(wSize * sizeof(int));
    obj->probability[0] = w[0];
    // printf("%d ", w[0]);
    for (int i = 1; i < wSize; i++)
    {
        // printf("%d ", w[i]);
        obj->probability[i] = obj->probability[i - 1] + w[i];
    }
    obj->sum = obj->probability[wSize - 1];
    return obj;
}

int solutionPickIndex(Solution *obj)
{
    int random = rand() % obj->sum;
    int low = 0;
    int high = obj->size - 1;
    int mid;
    int ret = 0;
    while (low < high)
    {
        mid = low + (high - low) / 2;
        if (obj->probability[mid] <= random)
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }

    return low;
}

void solutionFree(Solution *obj)
{
    free(obj->probability);
    free(obj);
}

/**
 * Your Solution struct will be instantiated and called as such:
 * Solution* obj = solutionCreate(w, wSize);
 * int param_1 = solutionPickIndex(obj);

 * solutionFree(obj);
*/
// @lc code=end
