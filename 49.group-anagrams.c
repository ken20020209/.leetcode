/*
 * @lc app=leetcode id=49 lang=c
 *
 * [49] Group Anagrams
 */
#include "header\leetcode.h"

// @lc code=start

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#define abs(a) (((a) >= 0) ? (a) : (-a))
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
        table->head[address]->node->val = value;
        table->head[address]->node->key = key;
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
// return deleted elements
int HashTableRM(HashTable *table, int key)
{
    int address = key % table->capacity;
    address = abs(address);
    int len = table->head[address]->length;
    int ret = 0;
    if (len == 0)
        return 0;
    HashNode *node = table->head[address]->node;
    HashNode *temp;
    while (node != NULL)
    {
        if (node->key == key)
        {
            if (node->pre == NULL)
            {
                table->head[address]->node = node->next;
                table->head[address]->node->pre = NULL;
                table->head[address]->length--;
                temp = node->next;
                HashNodeFree(node);
                node = temp;
                ret++;
            }
            else
            {
                node->pre->next = node->next;
                table->head[address]->length--;
                temp = node->next;
                HashNodeFree(node);
                node = temp;
                ret++;
            }
        }
        else
        {
            node = node->next;
        }
    }
    return ret;
}
// return get data size;
// 0 no data
//-1 cant save every data
int HashTableDataGet(HashTable *table, int key, int *arr, int size)
{
    int address = key % table->capacity;
    address = abs(address);
    if (table->head[address] == NULL)
        return 0;
    int len = table->head[address]->length;
    HashNode *node = table->head[address]->node;
    if (len == 0)
        return 0;
    if (len > size)
        return -1;
    for (int i = 0; i < len; i++)
    {
        arr[i] = node->val;
        node = node->next;
    }
    return len;
}
int HashTablePrintf(HashTable *table, int key)
{
    int address = key % table->capacity;
    address = abs(address);
    printf("key:%d\n", key);
    if (table->head[address] == NULL || table->head[address]->length == 0)
    {
        printf("There is no data\n");
        return 0;
    }
    HashNode *node = table->head[address]->node;
    for (int i = 0; i < table->head[address]->length; i++)
    {
        printf("LinkList%d:%d\n", i + 1, node->val);
        node = node->next;
    }
    return 1;
}
int cmp(char *a, char *b)
{
    while (*a == *b && *a != 0 && *b != 0)
    {
        a++;
        b++;
    }
    if (*b == 0 && *a != 0)
        return -1;
    if (*b != 0 && *a == 0)
        return 1;
    return *a - *b;
}
int BKDhash(const char *a)
{
    int seed = 31;
    int hash = 0;
    while (*a != '\0')
    {
        if (hash > INT_MAX >> 8)
        {
            hash &= 0x00fffff;
            hash >>= 8;
        }
        hash = hash * seed + *a;
        a++;
    }
    return hash;
}
char ***groupAnagrams(char **strs, int strsSize, int *returnSize, int **returnColumnSizes)
{
    HashTable *table = HashTableCreate(10000);
    HashNode *node = NULL;
    int hash;
    // map[i][0]=key
    /// map[i][1]=i on res[]
    char temp[100];
    char temp2[100];
    int flag = 0;
    int resS = 10000;
    int pos;
    int col;
    char ***res = (char ***)calloc(resS, sizeof(char **));
    *returnSize = 0;
    *returnColumnSizes = (int *)calloc(resS, sizeof(int));
    for (int i = 0; i < strsSize; i++)
    {
        int len = strlen(strs[i]);
        memcpy(temp, strs[i], len + 1);
        qsort(temp, len, sizeof(char), cmp);
        hash = BKDhash(temp);
        // printf("hash:%d\n", hash);
        flag = 1;
        while (flag)
        {
            flag = 0;
            node = HashTableSerch(table, hash);
            if (node == NULL)
            {
                HashTableInsert(table, hash, (*returnSize)++);
                node = HashTableSerch(table, hash);
            }

            pos = node->val;
            col = (*returnColumnSizes)[pos];
            if (col != 0)
            {
                memcpy(temp2, res[pos][0], (strlen(res[pos][0]) + 1) * sizeof(char));
                // printf("%s\n",temp2);
                qsort(temp2, strlen(res[pos][0]), sizeof(char), cmp);
                // printf("%s\n",temp2);
                if (strcmp(temp, temp2) != 0)
                {
                    printf("same hash\n");
                    flag = 1;
                    hash += 10;
                }
            }
        }
        if (col == NULL)
            res[pos] = (char **)malloc((col + 1) * sizeof(char *));
        else
            res[pos] = (char **)realloc(res[pos], (col + 1) * sizeof(char *));
        res[pos][col] = (char *)malloc((len + 1) * sizeof(char));

        memcpy(res[pos][col], strs[i], (len + 1) * sizeof(char));
        (*returnColumnSizes)[pos]++;
    }
    return res;
}
// @lc code=end
