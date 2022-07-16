/*
 * @lc app=leetcode id=57 lang=c
 *
 * [57] Insert Interval
 */
#include "header\leetcode.h"

// @lc code=start

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define EXTENDSIZE 2
typedef struct
{
    int capacity;
    int size;
    void **data;
} Vector;
Vector *vector_create(int size)
{
    Vector *v = (Vector *)malloc(sizeof(Vector));
    v->data = (void **)malloc(sizeof(void *) * size);
    v->size = 0;
    v->capacity = size;
    return v;
}
void vector_extend(Vector *v)
{
    v->capacity *= EXTENDSIZE;
    v->data = (void **)realloc(v->data, v->capacity * sizeof(void *));
}
void vecotr_add(Vector *v, void *data)
{

    if (v->size == v->capacity)
    {
        vector_extend(v);
    }
    v->data[v->size] = data;
    v->size++;
}
int **insert(int **intervals, int intervalsSize, int *intervalsColSize, int *newInterval, int newIntervalSize, int *returnSize, int **returnColumnSizes)
{
    Vector *v = vector_create(200);
    int **res = (int **)v->data;
    int start = newInterval[0];
    int end = newInterval[1];
    int i = 0;
    while (i < intervalsSize && intervals[i][1] < start)
    {
        vecotr_add(v, intervals[i]);
        i++;
    }
    while (i < intervalsSize && intervals[i][0] <= end)
    {
        start = fmin(start, intervals[i][0]);
        end = fmax(end, intervals[i][1]);
        i++;
    }
    int *merge = (int *)malloc(2 * sizeof(int));
    merge[0] = start;
    merge[1] = end;
    vecotr_add(v, merge);
    while (i < intervalsSize)
    {
        vecotr_add(v, intervals[i]);
        i++;
    }

    *returnSize = v->size;
    *returnColumnSizes = (int *)malloc(*returnSize * sizeof(int));
    for (int i = 0; i < *returnSize; i++)
        (*returnColumnSizes)[i] = 2;
    free(v);
    return res;
}
// @lc code=end
