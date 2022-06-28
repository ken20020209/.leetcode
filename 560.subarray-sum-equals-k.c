/*
 * @lc app=leetcode id=560 lang=c
 *
 * [560] Subarray Sum Equals K
 */
#include "header\leetcode.h"

// @lc code=start
int abs(int a)
{
    return a < 0 ? -a : a;
}

typedef struct HashNode
{
    int val;
    int key;
    struct HashNode *pre;
    struct HashNode *next;
} HashNode;
typedef struct HashTableHead
{
    int length;
    struct HashNode *node;
} HashTableHead;
typedef struct HashTable
{
    int size;
    int loadfactor;
    int capacity;
    int NeedReHash;
    struct HashTableHead **head; // data link list
} HashTable;
int BKDhash(char *str)
{
    int seed = 31, hash = 0;
    for (int i = 0; str[i]; i++)
        hash = hash * seed + str[i];
    return hash & 0x7fffffff;
}
HashNode *HashNodeCreate()
{
    HashNode *node = (HashNode *)calloc(1, sizeof(HashNode));
    return node;
}
void HashNodeFree(HashNode *node)
{
    free(node);
}
void HashLinkListFree(HashTableHead *head)
{
    int len = head->length;
    for (int i = 0; i < len; i++)
    {
        HashNode *node = head->node->next;
        free(head->node);
        head->node = node;
    }
}
HashTable *HashTableCreate(int capacity)
{
    HashTable *ht = (HashTable *)malloc(sizeof(HashTable));
    if (ht == NULL)
        return NULL;
    ht->size = 0;
    ht->capacity = capacity;
    ht->loadfactor = 0;
    ht->NeedReHash = 0;
    ht->head = (HashTableHead **)calloc(capacity, sizeof(HashTableHead *));
    if (ht->head == NULL)
    {
        free(ht);
        return NULL;
    }
    return ht;
}
void HashTableFree(HashTable *table)
{
    for (int i = 0; i < table->capacity; i++)
    {
        if (table->head[i] != NULL)
        {
            if (table->head[i]->length == 0)
            {
                free(table->head[i]);
            }
            else
            {
                HashLinkListFree(table->head[i]);
                free(table->head[i]);
            }
        }
    }
    free(table->head);
    free(table);
}

int HashTableInsert(HashTable *table, int key, int value)
{
    int address = key % table->capacity;
    address = abs(address);
    if (table->head[address] == 0)
    {
        table->head[address] = (HashTableHead *)malloc(sizeof(HashTableHead));
        table->head[address]->length = 1;
        table->head[address]->node = HashNodeCreate();
        table->head[address]->node->val = value;
        table->head[address]->node->key = key;
        table->size++;
    }
    else if (table->head[address]->length == 0)
    {
        table->head[address]->length = 1;
        table->head[address]->node = HashNodeCreate();
        table->head[address]->node->key = key;
        table->head[address]->node->val = value;
        table->size++;
    }
    else
    {
        table->head[address]->length++;
        table->head[address]->node->pre = HashNodeCreate();
        table->head[address]->node->pre->next = table->head[address]->node;
        table->head[address]->node = table->head[address]->node->pre;
        table->head[address]->node->val = value;
        table->head[address]->node->key = key;
        table->size++;
    }
    return 1;
}
// return 0 cant fine
// return address
HashNode *HashTableSerch(HashTable *table, int key)
{
    int address = key % table->capacity;
    address = abs(address);
    if (table->head[address] == NULL)
        return 0;
    if (table->head[address]->length == 0)
        return 0;
    HashNode *node = table->head[address]->node;
    while (node != NULL)
    {
        if (node->key == key)
            return node;
        node = node->next;
    }
    return 0;
}
int subarraySum(int *nums, int numsSize, int k)
{
    int res = 0;
    HashTable *table = HashTableCreate(10000);
    for (int i = 1; i < numsSize; i++)
        nums[i] += nums[i - 1];
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] == k)
            res++;
        HashNode *node = HashTableSerch(table, nums[i]);
        if (node != NULL)
        {
            
            res += node->val;
        }
        node = HashTableSerch(table, k + nums[i]);
        HashTableInsert(table, k + nums[i], node == NULL ? 1 : node->val + 1);
    }
    // HashTableFree(table);
    return res;
}
// @lc code=end
