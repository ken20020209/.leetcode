/*
 * @lc app=leetcode id=981 lang=c
 *
 * [981] Time Based Key-Value Store
 */
#include "header\leetcode.h"

// @lc code=start
#define MAPSIZE 10000

typedef struct
{
    int timestamp;
    char *data;
} vetor;
typedef struct
{
    int key;
    int size;
    int capacity;
    vetor *arrtree;
} entry;
typedef struct
{
    int capacity;
    int size;
    entry **node;
} TimeMap;
int BKDhash(char *s)
{
    int ret = 0;
    while (*s != 0)
    {
        if (ret > INT_MAX >> 8)
            ret &= 0x00FFFFFF;
        ret = ret * 31 + *s;
        s++;
    }
    return ret & 0x7FFFFFFF;
}
TimeMap *timeMapCreate()
{
    TimeMap *obj = (TimeMap *)malloc(sizeof(TimeMap));
    obj->capacity = MAPSIZE;
    obj->size = 0;
    obj->node = (entry **)calloc(MAPSIZE, sizeof(entry *));

    return obj;
}

// value is malloc
void timeMapSet(TimeMap *obj, char *key, char *value, int timestamp)
{
    int hash = BKDhash(key);
    int address = hash % obj->capacity;
    int len = strlen(value);
    // char *data = (char *)malloc(len + 1);
    // memcpy(data, value, len + 1);

    while (obj->node[address] != 0 && obj->node[address]->key != hash)
    {
        address = address + 1 % obj->capacity;
    }

    if (obj->node[address] == NULL)
    {
        obj->node[address] = (entry *)malloc(sizeof(entry));
        obj->node[address]->key = hash;
        obj->node[address]->capacity = 10;
        obj->node[address]->size = 0;
        obj->node[address]->arrtree = (vetor *)malloc(obj->node[address]->capacity * sizeof(vetor));
    }
    // BS serch to fine insert place
    int pos = 0;
    int high = obj->node[address]->size - 1;
    int low = 0;
    int mid;
    while (low <= high)
    {

        mid = low + (high - low) / 2;
        if (obj->node[address]->arrtree[mid].timestamp < timestamp)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    if (low != 0 && obj->node[address]->arrtree[low - 1].timestamp > timestamp)
    {
        pos = low - 1;
    }
    else
        pos = low;

    // line serch O(n) time to fine insert place
    // TLE

    // for (i = 0; i < obj->node[address]->size; i++)
    // {
    //     if (obj->node[address]->arrtree[i].timestamp > timestamp)
    //     {
    //         break;
    //     }
    // }

    // insert sort O(n)time
    for (int j = obj->node[address]->size; j > pos; j--)
    {
        obj->node[address]->arrtree[j].timestamp = obj->node[address]->arrtree[j - 1].timestamp;
        obj->node[address]->arrtree[j].data = obj->node[address]->arrtree[j - 1].data;
    }

    obj->node[address]->arrtree[pos].timestamp = timestamp;
    obj->node[address]->arrtree[pos].data = value;
    obj->node[address]->size++;

    // extend vetor capacity
    if (obj->node[address]->size + 1 == obj->node[address]->capacity)
    {
        obj->node[address]->capacity *= 2;
        obj->node[address]->arrtree = (vetor *)realloc(obj->node[address]->arrtree, obj->node[address]->capacity * sizeof(vetor));
    }
}

char *timeMapGet(TimeMap *obj, char *key, int timestamp)
{
    int hash = BKDhash(key);
    int max = 0;
    int address = hash % obj->capacity;
    char *ret = NULL;
    // hashmap key != hash fine address++
    while (obj->node[address] != 0 && obj->node[address]->key != hash)
    {
        address = address + 1 % obj->capacity;
    }

    // if (obj->node[address] == 0)
    //     return NULL;
    if (obj->node[address] == NULL)
    {
        ret = (char *)calloc(1, sizeof(char));
        return ret;
    }
    // bs serch pos
    int high = obj->node[address]->size - 1;
    int low = 0;
    int mid;
    while (low <= high)
    {

        mid = low + (high - low) / 2;
        if (obj->node[address]->arrtree[mid].timestamp == timestamp)
        {
            ret = obj->node[address]->arrtree[mid].data;
            break;
        }
        else if (obj->node[address]->arrtree[mid].timestamp < timestamp)
        {
            ret = obj->node[address]->arrtree[mid].data;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    if (ret == NULL)
        ret = (char *)calloc(1, sizeof(char));
    return ret;
}

void timeMapFree(TimeMap *obj)
{
    for (int i = 0; i < obj->capacity; i++)
    {
        if (obj->node[i] != NULL)
        {
            free(obj->node[i]->arrtree);
            free(obj->node[i]);
        }
    }
    free(obj);
}

/**
 * Your TimeMap struct will be instantiated and called as such:
 * TimeMap* obj = timeMapCreate();
 * timeMapSet(obj, key, value, timestamp);

 * char * param_2 = timeMapGet(obj, key, timestamp);

 * timeMapFree(obj);
*/
// @lc code=end
