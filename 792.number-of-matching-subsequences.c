/*
 * @lc app=leetcode id=792 lang=c
 *
 * [792] Number of Matching Subsequences
 */
#include "header\leetcode.h"

// @lc code=start
// typedef (*KeyCompare)(const void *, const void *);
// typedef (*hashCode)(const void *);
// typedef struct HashNode
// {
//     void *key;
//     void *val;
//     struct HashNode *pre;
//     struct HashNode *next;
// } HashNode;
// typedef struct HashTableHead
// {
//     int length;
//     struct HashNode *head;
// } HashTableHead;
// typedef struct HashTable
// {
//     int size;
//     int loadfactor; // size/capacity
//     int capacity;
//     KeyCompare key_eq;
//     hashCode hash;
//     HashTableHead **buckets;
// } HashTable;

// HashTable *HashTableCreate(int size, KeyCompare key_eq, hashCode hash)
// {
//     HashTable *table = (HashTable *)malloc(sizeof(HashTable));
//     table->size = 0;
//     table->loadfactor = 0;
//     table->capacity = size;
//     table->key_eq = key_eq;
//     table->hash = hash;
//     table->buckets = (HashTableHead **)calloc(size, sizeof(HashTableHead *));
//     for (int i = 0; i < size; i++)
//         table->buckets[i] = (HashTableHead *)calloc(1, sizeof(HashTableHead));
//     return table;
// }
// int HashTableAddress(HashTable *table, void *key)
// {
//     int address = table->hash(key) % table->capacity;
//     return address < 0 ? -address : address;
// }
// // return val was update
// void *HashTableInsert(HashTable *table, void *key, void *val)
// {
//     int address = HashTableAddress(table, key);
//     HashNode *node = table->buckets[address]->head;
//     for (int i = 0; i < table->buckets[address]->length; i++)
//     {
//         int cmp = table->key_eq(node->key, key);
//         if (cmp == 0)
//         {
//             void *ret = node->val;
//             node->val = val;
//             return ret;
//         }
//         node = node->next;
//     }
//     table->buckets[address]->length++;
//     node = (HashNode *)malloc(sizeof(HashNode));
//     node->val = val;
//     node->key = key;
//     node->next = table->buckets[address]->head;
//     node->pre = NULL;
//     if (node->next != NULL)
//         node->next->pre = node;
//     table->buckets[address]->head = node;
//     return NULL;
// }
// void *HashTableFind(HashTable *table, void *key)
// {
//     int address = HashTableAddress(table, key);
//     HashNode *node = table->buckets[address]->head;
//     for (int i = 0; i < table->buckets[address]->length; i++)
//     {
//         int cmp = table->key_eq(node->key, key);
//         if (cmp == 0)
//         {
//             return node->val;
//         }
//         node = node->next;
//     }
//     return NULL;
// }
// bool isSubsequence(char *s, char *t)
// {
//     if (*s == '\0')
//         return true;

//     while (*t != '\0')
//     {

//         if (*s == *t)
//         {
//             s++;
//         }
//         if (*s == '\0')
//         {
//             return true;
//         }
//         t++;
//     }
//     return false;
// }
// int BKDhash(char *key)
// {
//     int hashCode = 0;
//     while (*key++)
//         hashCode = (hashCode * 31 + *key) & 0x00ffffff;
//     return hashCode;
// }
// int keystrcmp(void *a, void *b)
// {
//     return strcmp((char *)a, (char *)b);
// }
// int numMatchingSubseq(char *s, char **words, int wordsSize)
// {
//     int res = 0;
//     HashTable *table = HashTableCreate(1000, keystrcmp, BKDhash);
//     HashNode *node = NULL;
//     for (int i = 0; i < wordsSize; i++)
//     {
//         // printf("%d\n", i);
//         node = HashTableFind(table, words[i]);
//         // printf("    node = %p\n", node);
//         if (node == NULL)
//         {
//             if (isSubsequence(words[i], s))
//             {
//                 HashTableInsert(table, words[i], 1);
//                 res++;
//             }
//             else
//                 HashTableInsert(table, words[i], 2);
//         }
//         else if (node == 1)
//             res++;
//     }
//     return res;
// }
char *waiting[128][5000];

int numMatchingSubseq(char *S, char **words, int wordsSize)
{
    // save how many words start at char a-z
    // wn like a queue
    int wn[128] = {};
    while (wordsSize--)
    {
        char *word = *words++;
        // save start at char a-z next char
        waiting[*word][wn[*word]++] = word + 1;
    }
    while (*S)
    {
        char c = *S++;
        // n is how many word at waiting[a-z]
        int n = wn[c];
        // clear wn[c]
        wn[c] = 0;
        for (int i = 0; i < n; i++)
        {
            char *it = waiting[c][i];
            waiting[*it][wn[*it]++] = it + 1;
        }
    }
    // wn[0] means words[i] is go to last word
    return wn[0];
}
// @lc code=end
