/*
 * @lc app=leetcode id=128 lang=c
 *
 * [128] Longest Consecutive Sequence
 */
#include "header\leetcode.h"

// @lc code=start
typedef (*KeyCompare)(const void *, const void *);
typedef (*hashCode)(const void *);
typedef struct HashNode
{
    void *key;
    void *val;
    struct HashNode *pre;
    struct HashNode *next;
} HashNode;
typedef struct HashTableHead
{
    int length;
    struct HashNode *head;
} HashTableHead;
typedef struct HashTable
{
    int size;
    int loadfactor; // size/capacity
    int capacity;
    KeyCompare key_eq;
    hashCode hash;
    HashTableHead **buckets;
} HashTable;

HashTable *HashTableCreate(int size, KeyCompare key_eq, hashCode hash)
{
    HashTable *table = (HashTable *)malloc(sizeof(HashTable));
    table->size = 0;
    table->loadfactor = 0;
    table->capacity = size;
    table->key_eq = key_eq;
    table->hash = hash;
    table->buckets = (HashTableHead **)calloc(size, sizeof(HashTableHead *));
    for (int i = 0; i < size; i++)
        table->buckets[i] = (HashTableHead *)calloc(1, sizeof(HashTableHead));
    return table;
}
int HashTableAddress(HashTable *table, void *key)
{
    int address = table->hash(key) % table->capacity;
    return address < 0 ? -address : address;
}
// return val was update
void *HashTableInsert(HashTable *table, void *key, void *val)
{
    int address = HashTableAddress(table, key);
    HashNode *node = table->buckets[address]->head;
    for (int i = 0; i < table->buckets[address]->length; i++)
    {
        int cmp = table->key_eq(node->key, key);
        if (cmp == 0)
        {
            void *ret = node->val;
            node->val = val;
            return ret;
        }
        node = node->next;
    }
    table->buckets[address]->length++;
    node = (HashNode *)malloc(sizeof(HashNode));
    node->val = val;
    node->key = key;
    node->next = table->buckets[address]->head;
    node->pre = NULL;
    if (node->next != NULL)
        node->next->pre = node;
    table->buckets[address]->head = node;
    return NULL;
}
HashNode *HashTableFind(HashTable *table, void *key)
{
    int address = HashTableAddress(table, key);
    HashNode *node = table->buckets[address]->head;
    for (int i = 0; i < table->buckets[address]->length; i++)
    {
        int cmp = table->key_eq(node->key, key);
        if (cmp == 0)
        {
            return node;
        }
        node = node->next;
    }
    return NULL;
}
int cmp(int a, int b)
{
    return a - b;
}
int hash(int a)
{
    return a;
}
// hashmap
#define MAPSIZE 20000
// int longestConsecutive(int *nums, int numsSize)
// {
//     if (numsSize == 0)
//         return 0;
//     HashTable *map = HashTableCreate(MAPSIZE, cmp, hash);
//     int res = 0;
//     for (int i = 0; i < numsSize; i++)
//     {
//         HashTableInsert(map, nums[i], 0);
//     }
//     for (int i = 0; i < MAPSIZE; i++)
//     {
//         HashNode *node = map->buckets[i]->head;
//         while (node)
//         {
//             // printf("%d\n", node->key);
//             if (HashTableFind(map, (int)node->key - 1) == NULL)
//             {
//                 int curnum = node->key;
//                 int curstreak = 1;
//                 while (HashTableFind(map, curnum + 1) != NULL)
//                 {
//                     curnum++;
//                     curstreak++;
//                 }
//                 res = fmax(res, curstreak);
//             }

//             node = node->next;
//         }
//     }
//     return res;
// }
int longestConsecutive(int *nums, int numsSize)
{
    if (numsSize == 0)
        return 0;
    HashTable *map = HashTableCreate(MAPSIZE, cmp, hash);
    int res = 0;
    for (int i = 0; i < numsSize; i++)
    {
        HashTableInsert(map, nums[i], 0);
    }
    for (int i = 0; i < MAPSIZE; i++)
    {
        HashNode *node = map->buckets[i]->head;
        while (node)
        {
            if (node->val == 0)
            {
                int curstreak = 1;
                node->val = 0;
                HashNode *temp;
                int j = 1;
                do
                {
                    temp = HashTableFind(map, (int)node->key - j++);
                    if (temp != NULL)
                    {
                        if (temp->val == 0)
                        {
                            curstreak++;
                            temp->val = 1;
                        }
                    }
                } while (temp);
                j = 1;
                do
                {
                    temp = HashTableFind(map, (int)node->key + j++);
                    if (temp != NULL)
                    {
                        if (temp->val == 0)
                        {
                            curstreak++;
                            temp->val = 1;
                        }
                    }
                } while (temp);

                res = fmax(res, curstreak);
            }
            node = node->next;
        }
    }
    return res;
}
// sort
//  int longestConsecutive(int *nums, int numsSize)
//  {
//      if (numsSize == 0)
//          return 0;
//      qsort(nums, numsSize, sizeof(int), cmp);
//      int cnt = 1;
//      int res = 1;
//      int ele = nums[0];
//      for (int i = 1; i < numsSize; i++)
//      {
//          if (nums[i] == ele)
//              continue;
//          if (nums[i] == ele + 1)
//              cnt++;
//          else
//              cnt = 1;
//          ele = nums[i];
//          res = fmax(res, cnt);
//      }
//      return res;
//  }
//  @lc code=end
