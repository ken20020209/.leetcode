#include "../header/leetcode.h"

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
