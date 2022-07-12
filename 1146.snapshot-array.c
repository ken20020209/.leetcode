/*
 * @lc app=leetcode id=1146 lang=c
 *
 * [1146] Snapshot Array
 */
#include "header\leetcode.h"

// @lc code=start
// typedef struct
// {
//     int snap_id;
//     int val;
// } pair;
// typedef struct
// {
//     int capacity;
//     int size;
//     int *data;
//     // pair *data;
// } entry;
// typedef struct
// {
//     int snap_id;
//     int length;
//     entry **entry;
// } SnapshotArray;

// SnapshotArray *snapshotArrayCreate(int length)
// {
//     SnapshotArray *obj = (SnapshotArray *)malloc(sizeof(SnapshotArray));
//     obj->length = length;
//     obj->snap_id = 0;
//     obj->entry = (entry **)malloc(obj->length * sizeof(entry *));
//     for (int i = 0; i < obj->length; i++)
//     {
//         obj->entry[i] = (entry *)malloc(sizeof(entry));
//         obj->entry[i]->capacity = 1;
//         obj->entry[i]->data = (int *)calloc(obj->entry[i]->capacity, sizeof(int));
//     }
//     return obj;
// }

// void snapshotArraySet(SnapshotArray *obj, int index, int val)
// {
//     // printf("set\n");
//     if (obj->snap_id >= obj->entry[index]->capacity)
//     {
//         int preSize = obj->entry[index]->capacity;
//         obj->entry[index]->capacity = obj->snap_id + 1;
//         obj->entry[index]->data = (int *)realloc(obj->entry[index]->data, obj->entry[index]->capacity * sizeof(int));
//         for (int i = preSize; i < obj->snap_id; i++)
//         {
//             // printf("%d\n", obj->entry[index]->data[preSize - 1]);
//             obj->entry[index]->data[i] = obj->entry[index]->data[preSize - 1];
//         }
//     }
//     obj->entry[index]->data[obj->snap_id] = val;
// }

// int snapshotArraySnap(SnapshotArray *obj)
// {
//     return obj->snap_id++;
// }

// int snapshotArrayGet(SnapshotArray *obj, int index, int snap_id)
// {
//     if (snap_id >= obj->entry[index]->capacity)
//     {
//         return obj->entry[index]->data[obj->entry[index]->capacity - 1];
//     }
//     return obj->entry[index]->data[snap_id];
// }

// void snapshotArrayFree(SnapshotArray *obj)
// {
//     free(obj);
// }

typedef struct
{
    int capacity;
    int size;
    int *snap_id;
    int *val;
} entry;
typedef struct
{
    int snap_id;
    int length;
    entry **entry;
} SnapshotArray;

SnapshotArray *snapshotArrayCreate(int length)
{
    SnapshotArray *obj = (SnapshotArray *)malloc(sizeof(SnapshotArray));
    obj->length = length;
    obj->snap_id = 0;
    obj->entry = (entry **)malloc(obj->length * sizeof(entry *));
    for (int i = 0; i < obj->length; i++)
    {
        obj->entry[i] = (entry *)malloc(sizeof(entry));
        obj->entry[i]->capacity = 1;
        obj->entry[i]->size = 0;
        obj->entry[i]->snap_id = (int *)calloc(obj->entry[i]->capacity, sizeof(int));
        obj->entry[i]->val = (int *)calloc(obj->entry[i]->capacity, sizeof(int));
    }
    return obj;
}

void snapshotArraySet(SnapshotArray *obj, int index, int val)
{
    // printf("set\n");
    if (obj->entry[index]->size >= obj->entry[index]->capacity)
    {
        obj->entry[index]->capacity *= 2;
        obj->entry[index]->snap_id = (int *)realloc(obj->entry[index]->snap_id, obj->entry[index]->capacity * sizeof(int));
        obj->entry[index]->val = (int *)realloc(obj->entry[index]->val, obj->entry[index]->capacity * sizeof(int));
    }
    if (obj->entry[index]->size != 0 && obj->snap_id == obj->entry[index]->snap_id[obj->entry[index]->size - 1])
    {
        obj->entry[index]->snap_id[obj->entry[index]->size - 1] = obj->snap_id;
        obj->entry[index]->val[obj->entry[index]->size - 1] = val;
    }
    else
    {
        obj->entry[index]->snap_id[obj->entry[index]->size] = obj->snap_id;
        obj->entry[index]->val[obj->entry[index]->size] = val;
        obj->entry[index]->size++;
    }
}

int snapshotArraySnap(SnapshotArray *obj)
{
    return obj->snap_id++;
}

int snapshotArrayGet(SnapshotArray *obj, int index, int snap_id)
{
    int ret = 0;
    // for (int i = 0; i < obj->entry[index]->size; i++)
    // {
    //     if (snap_id >= obj->entry[index]->snap_id[i])
    //     {
    //         ret = obj->entry[index]->val[i];
    //     }
    // }
    int high = obj->entry[index]->size - 1;
    int low = 0;
    int mid;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (obj->entry[index]->snap_id[mid] == snap_id)
        {
            return obj->entry[index]->val[mid];
        }
        else if (obj->entry[index]->snap_id[mid] > snap_id)
        {

            high = mid - 1;
        }
        else
        {
            ret = obj->entry[index]->val[mid];
            low = mid + 1;
        }
    }

    return ret;
}

void snapshotArrayFree(SnapshotArray *obj)
{
    for (int i = 0; i < obj->length; i++)
    {
        free(obj->entry[i]->snap_id);
        free(obj->entry[i]->val);
        free(obj->entry[i]);
    }
    free(obj->entry);
    free(obj);
}
/**
 * Your SnapshotArray struct will be instantiated and called as such:
 * SnapshotArray* obj = snapshotArrayCreate(length);
 * snapshotArraySet(obj, index, val);

 * int param_2 = snapshotArraySnap(obj);

 * int param_3 = snapshotArrayGet(obj, index, snap_id);

 * snapshotArrayFree(obj);
*/
// @lc code=end
