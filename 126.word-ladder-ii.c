/*
 * @lc app=leetcode id=126 lang=c
 *
 * [126] Word Ladder II
 */
#include "header\leetcode.h"

// @lc code=start

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
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
// call back function
int BKDhash(char *key)
{
    int hashCode = 0;
    while (*key++)
        hashCode = hashCode * 31 + *key;
    return hashCode;
}
int keystrcmp(void *a, void *b)
{
    return strcmp((char *)a, (char *)b);
}
// char ***findLadders(char *beginWord, char *endWord, char **wordList, int wordListSize, int *returnSize, int **returnColumnSizes)
// {
//     HashTable *dict = HashTableCreate(10000, keystrcmp, BKDhash);
//     char **queue[1000000];
//     int front = 0;
//     int rear = -1;
//     int step = 0;
//     int finded = false;
//     int len = strlen(endWord);
//     *returnSize = 0;
//     int rescapacity = 2000;
//     char ***res = (char ***)malloc(rescapacity * sizeof(char **));
//     *returnColumnSizes = (int *)malloc(rescapacity * sizeof(char));
//     *returnSize = 0;
//     queue[++rear] = (char **)malloc(1 * sizeof(char *));
//     queue[rear][0] = beginWord;
//     for (int i = 0; i < wordListSize; i++)
//     {
//         HashTableInsert(dict, wordList[i], -1);
//     }
//     if (HashTableFind(dict, endWord) == NULL)
//         return res;
//     while (front <= rear && !finded && step < wordListSize)
//     {
//         int size = rear - front + 1;
//         while (size)
//         {
//             size--;
//             char **pop = queue[front++];
//             char word[10];
//             memcpy(word, pop[step], strlen(pop[step]) + 1);
//             // if (step == 14)
//             // {
//             //     for (int i = 0; i <= step; i++)
//             //     {
//             //         printf("%s  ", pop[i]);
//             //     }
//             //     printf("\n");
//             // }
//             for (int i = 0; i < len; i++)
//             {
//                 char temp = word[i];

//                 for (int j = 'a'; j <= 'z'; j++)
//                 {
//                     if (j == temp)
//                         continue;
//                     word[i] = j;
//                     HashNode *node = HashTableFind(dict, word);

//                     if (node == NULL)
//                         continue;
//                     if (strcmp(node->key, endWord) == 0)
//                     {
//                         printf("finded\n");
//                         res[*returnSize] = (char **)malloc((step + 2) * sizeof(char *));
//                         memcpy(res[*returnSize], pop, sizeof(char *) * (step + 1));
//                         res[*returnSize][step + 1] = endWord;
//                         (*returnColumnSizes)[*returnSize] = step + 2;
//                         (*returnSize)++;
//                         finded = true;
//                         continue;
//                     }

//                     if (node->val == -1 || node->val == step)
//                     {

//                         node->val = step;
//                         queue[++rear] = (char **)malloc((step + 2) * sizeof(char *));
//                         memcpy(queue[rear], pop, sizeof(char *) * (step + 1));
//                         queue[rear][step + 1] = node->key;
//                     }
//                 }
//                 word[i] = temp;
//             }
//             free(pop);
//         }
//         step++;
//     }
//     while (front <= rear)
//     {
//         free(queue[front]);
//         front++;
//     }
//     return res;
// }
typedef struct tree
{
    int val;
    int lenth;
    HashTable *table;
    char **key;
} tree;
void generatepath(HashTable *dict, char *beginWord, char *endword, char ***res, int *returnSize, int **returnColumnSizes, char *buf[], int bufsize, int bufindex)
{

    if (beginWord == endword)
    {
        buf[0] = endword;
        res[*returnSize] = (char **)malloc(sizeof(char *) * bufsize);
        memcpy(res[*returnSize], buf, bufsize * sizeof(char *));
        (*returnColumnSizes)[*returnSize] = bufsize;
        (*returnSize)++;
    }
    HashNode *node = HashTableFind(dict, endword);
    if (node == NULL)
        return;
    tree *val = node->val;
    // printf("%s\n", endword);
    for (int i = 0; i < val->lenth; i++)
    {
        buf[bufindex - 1] = endword;
        generatepath(dict, beginWord, val->key[i], res, returnSize, returnColumnSizes, buf, bufsize, bufindex - 1);
    }
}

// have not free allocated memory
char ***findLadders(char *beginWord, char *endWord, char **wordList, int wordListSize, int *returnSize, int **returnColumnSizes)
{
    HashTable *dict = HashTableCreate(1000, keystrcmp, BKDhash);
    char *queue[1000000];
    int front = 0;
    int rear = -1;
    int step = 0;
    int finded = false;
    int len = strlen(endWord);
    *returnSize = 0;
    int rescapacity = 1000;
    char ***res = (char ***)malloc(rescapacity * sizeof(char **));
    *returnColumnSizes = (int *)malloc(rescapacity * sizeof(char));
    *returnSize = 0;
    queue[++rear] = beginWord;
    for (int i = 0; i < wordListSize; i++)
    {
        tree *val = (tree *)malloc(sizeof(tree));
        val->table = HashTableCreate(50, keystrcmp, BKDhash);
        val->lenth = 0;
        val->val = -1;
        val->key = (char **)malloc(sizeof(char *) * 500);
        HashTableInsert(dict, wordList[i], val);
    }
    tree *val = (tree *)malloc(sizeof(tree));
    val->lenth = 0;
    val->val = -2;
    HashTableInsert(dict, beginWord, val);
    if (HashTableFind(dict, endWord) == NULL)
        return res;
    while (front <= rear && !finded && step < wordListSize)
    {
        int size = rear - front + 1;
        while (size)
        {
            size--;
            char *pop = queue[front++];
            char word[10];

            memcpy(word, pop, len + 1);
            // printf("%s\n", word);
            for (int i = 0; i < len; i++)
            {
                char temp = word[i];

                for (int j = 'a'; j <= 'z'; j++)
                {
                    if (j == temp)
                        continue;
                    word[i] = j;
                    HashNode *node = HashTableFind(dict, word);

                    if (node == NULL)
                        continue;
                    tree *val = (tree *)node->val;
                    if (strcmp(word, endWord) == 0)
                        finded = true;
                    if (val->val == -1 || val->val == step)
                    {
                        if (HashTableFind(val->table, pop) == NULL)
                        {
                            val->val = step;
                            val->key[val->lenth++] = pop;
                            queue[++rear] = node->key;
                            HashTableInsert(val->table, pop, 0);
                        }
                    }
                }
                word[i] = temp;
            }
        }
        // printf("\n");
        step++;
    }
    char *buf[step + 1];
    // printf("%d\n", ((tree *)HashTableFind(dict, "tex")->val)->lenth);
    generatepath(dict, beginWord, endWord, res, returnSize, returnColumnSizes, buf, step + 1, step + 1);
    return res;
}
// @lc code=end
