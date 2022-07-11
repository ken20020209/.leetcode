/*
 * @lc app=leetcode id=341 lang=c
 *
 * [341] Flatten Nested List Iterator
 */
#include "header\leetcode.h"

// @lc code=start
/**
 * *********************************************************************
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * *********************************************************************
 *
 * // Return true if this NestedInteger holds a single integer, rather than a nested list.
 * bool NestedIntegerIsInteger(struct NestedInteger *);
 *
 * // Return the single integer that this NestedInteger holds, if it holds a single integer
 * // The result is undefined if this NestedInteger holds a nested list
 * int NestedIntegerGetInteger(struct NestedInteger *);
 *
 * // Return the nested list that this NestedInteger holds, if it holds a nested list
 * // The result is undefined if this NestedInteger holds a single integer
 * struct NestedInteger **NestedIntegerGetList(struct NestedInteger *);
 *
 * // Return the nested list's size that this NestedInteger holds, if it holds a nested list
 * // The result is undefined if this NestedInteger holds a single integer
 * int NestedIntegerGetListSize(struct NestedInteger *);
 * };
 */

struct NestedIterator
{
    int *data;
    int capacity;
    int size;
    int next;
};

struct NestedIterator *nestedIterCreate(struct NestedInteger **nestedList, int nestedListSize)
{
    struct NestedIterator *iter = (struct NestedIterator *)malloc(sizeof(struct NestedIterator));
    struct NestedInteger **temp;
    iter->next = 0;
    iter->size = 0;
    iter->capacity = 2;
    iter->data = (int *)malloc(iter->capacity * sizeof(int));
    struct NestedInteger **stack[10000];
    struct NestedInteger *pop;
    int top = -1;
    for (int i = 0; i < nestedListSize; i++)
    {
        stack[++top] = nestedList[i];
        while (top >= 0)
        {
            pop = stack[top--];
            int size = NestedIntegerGetListSize(pop);
            if (size > 0)
            {
                temp = NestedIntegerGetList(pop);
                for (int i = size - 1; i >= 0; i--)
                {
                    stack[++top] = temp[i];
                }
            }
            else if (NestedIntegerIsInteger(pop))
            {
                if (iter->size == iter->capacity)
                {
                    iter->capacity *= 2;
                    iter->data = (int *)realloc(iter->data, iter->capacity * sizeof(int));
                }
                iter->data[iter->size++] = NestedIntegerGetInteger(pop);
            }
        }
    }

    return iter;
}

bool nestedIterHasNext(struct NestedIterator *iter)
{
    if (iter->next < iter->size)
        return true;
    return false;
}

int nestedIterNext(struct NestedIterator *iter)
{

    if (nestedIterHasNext(iter))
    {
        return iter->data[iter->next++];
    }
    return NULL;
}

/** Deallocates memory previously allocated for the iterator */
void nestedIterFree(struct NestedIterator *iter)
{
    free(iter);
}

/**
 * Your NestedIterator will be called like this:
 * struct NestedIterator *i = nestedIterCreate(nestedList, nestedListSize);
 * while (nestedIterHasNext(i)) printf("%d\n", nestedIterNext(i));
 * nestedIterFree(i);
 */
// @lc code=end
